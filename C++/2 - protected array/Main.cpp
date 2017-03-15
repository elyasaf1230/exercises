#include <iostream>


int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int* brr = arr;
	++brr;

	std::cout << arr[0] << std::endl;
	std::cout << brr[0] << std::endl;
	std::cout << brr[-1] << std::endl;
	std::cout << arr[-1] << std::endl;

	getchar();
	return 1;

}