#include <iostream>
#include <string>
#include "Fraction.h"


int main()
{
	Fraction f1(1, 2);
	Fraction f2(0.5);
	Fraction f3(60, 120);
	Fraction f4(f3 * f1);

	Fraction f5 = f1 + 9;
	int f6 = static_cast<int>((f5 / 0.5).to_double());
	
	std::cout << "f1: " << f1.to_string() << std::endl;
	std::cout << "f2: " << f2.to_string() << std::endl;
	std::cout << "f3: " << f3.to_string() << std::endl;
	std::cout << "f4: " << f4.to_string() << std::endl;
	std::cout << "f5: " << f5.to_string() << std::endl;
	std::cout << "f6: " << f6 << std::endl;
	
	std::cout << "f1 <= f2 : " << (f1 <= f2) << std::endl;
	std::cout << "f1 >= 12 : " << (f1 >= 12) << std::endl;
	std::cout << "34: " << Fraction(34).to_string() << std::endl;

	getchar();
	return 0;
}