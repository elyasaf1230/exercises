#include <iostream>
#include <exception>
#include <string>
#include "ProtectedArray.h"


int main()
{	
	ProtectedArray<int> arr(10);
	
	std::cout << "before:" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " -> " << (arr[i] = 1) << std::endl;
	}

	ProtectedArray<int> brr = arr;
	
	//arr[0]
	brr[0] = 0;
	
	//arr[1]
	++brr;
	(*brr) = 0;
	
	//arr[3]
	ProtectedArray<int> crr = brr + 2;
	(*crr) = 0;

	//invalid index..
	try
	{
		crr += 10;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	//You can't do: int arr[]; int brr[]; brr = arr;
	//But hey! it's c++, so with my ProtectedArray you can! 
	crr = arr + 7;

	//arr[8]
	crr[1] = 0;
	
	std::cout << "after:" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " -> " << (arr[i]) << std::endl;
	}

	getchar();
	return 1;

}