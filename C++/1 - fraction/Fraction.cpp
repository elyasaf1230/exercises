#include "Fraction.h"


/*
	Default constructor.

	INPUT:
		None.

	OUPUT:
		None.
*/
Fraction::Fraction()
{
	this->_numerator = 0;
	this->_denominator = 0;
}

/*
	Constructor for ints.
	(note that if denominator is 0, it will be set to 1.)
	This constructor can be used like another constructor that get only one int - integer number.

	INPUT:
		numerator - int for numerator of the fraction.
		denominator - int for denominator of the fraction.

	OUTPUT:
		None.
*/
Fraction::Fraction(const int numerator, const int denominator)
{
	this->_numerator = numerator;

	if (denominator == 0) 
		this->_denominator = 1;
	else
		this->_denominator = denominator;

	this->simplify();
}

/*
	Constructor for double (or float).

	INPUT:
		number - double number (or float).

	OUTPUT:
		None.
*/
Fraction::Fraction(const double number)
{
	this->_numerator = static_cast<int>(number);
	this->_denominator = 1;

	//multiple the numerator and the denominator until numerator/denominator==number
	//(it will work because when casting double to int' all the digits after the . (dot) are gone.
	while (static_cast<double>(this->_numerator) / static_cast<double>(this->_denominator) < number)
	{
		this->_denominator *= 10;
		this->_numerator = static_cast<int>(number * this->_denominator);
	}

	//now simplify it...
	simplify();	
}

/*
	Copy constructor.

	INPUT:
		Fration to copy...

	OUTPUT:
		None.
*/
Fraction::Fraction(const Fraction &other)
{
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;

	//useless... but still...
	this->simplify();
}

/*
	Destructor.

	INPUT:
		None.

	OUTPUT:
		None.
*/
Fraction::~Fraction()
{
}

/*
	getNumerator:
		Method to get the numerator number in the fraction.

	INPUT:
		None.

	OUTPUT:
		int - the value.
*/
int Fraction::getNumerator() const
{
	return this->_numerator;
}

/*
	getDenominator:
		Method to get the denominator number in the fraction.

	INPUT:
		None.

	OUTPUT:
		int - the value.
*/
int Fraction::getDenominator() const
{
	return this->_denominator;
}

/*
	setNumerator:
		Method to set the numerator value of the fraction.

	INPUT:
		numerator - new numerator to set.

	OUTPUT:
		None.
*/
void Fraction::setNumerator(const int numerator)
{
	this->_numerator = numerator;

	this->simplify();
}

/*
	setDenominator:
		Method to set the denominator value of the fraction.

	INPUT:
		denominator - new denominator to set.

	OUTPUT:
		bool - true on success, false on error (denominator cannot be 0).
*/
bool Fraction::setDenominator(const int denominator)
{
	if (denominator == 0) 
		return false;

	this->_denominator = denominator;

	this->simplify();
	return true;
}

/*
	to_string:
		Method to get the fraction as a string (to print, for example)

	INPUT:
		None.

	OUTPUT:
		std::string - the fraction as a string.
*/
std::string Fraction::to_string() const
{
	if (this->getNumerator() == 0 || this->getDenominator() == 1)
		return std::to_string(this->getNumerator());
	
	return (std::to_string(this->_numerator) + std::string("/") + std::to_string(this->_denominator));
}

/*
	to_double:
		Method to get the fraction as rational number (double).

	INPUT:
		None.

	OUTPUT:
		double.
*/
double Fraction::to_double() const
{
	return this->getNumerator() / static_cast<double>(this->getDenominator());
}

/*
	 simplify:
		This function simplify the fraction. 
		It should be call after any modification of the fraction (numerator of denominator).

	INPUT:
		None.

	OUTPUT:
		None.
*/
void Fraction::simplify()
{
	int start;  

	//finding the biggest, and taking half of it - this is where we sould 
	//start search for common factor between numerator and denominator. 
	if (this->_numerator > this->_denominator)
		start = this->_numerator / 2;
	else
		start = this->_denominator / 2;

	//searching for biggest divider and divide numerator and denominator
	for (int divider = start; divider > 1; --divider)
	{
		if (this->_numerator % divider == 0 &&
			this->_denominator % divider == 0)
		{
			this->_numerator /= divider;
			this->_denominator /= divider;
		}
	}
}

/*
	operator ==:
	
	INPUT:
		Fraction to compare.

	OUTPUT:
		True if the fractions are equal. false if not.
*/
bool Fraction::operator==(const Fraction &other) const
{
	//It will work because the class is resposible to call the 
	//'simplify' method after any modification of the fraction.
	return (this->_numerator == other._numerator && this->_denominator == other._denominator);
}

/*
	operator <:

	INPUT:
		Fraction to compare with.

	OUTPUT:
		True if the current fraction is smaller then the other.
*/
bool Fraction::operator<(const Fraction &other) const
{
	Fraction temp(*this - other);

	return temp.getNumerator() < 0;
}

/*
	operator >:

	INPUT:
		Fraction to compare with.

	OUTPUT:
		True if the current fraction is greater then the other.
*/
bool Fraction::operator>(const Fraction &other) const
{
	Fraction temp(*this - other);

	return temp.getNumerator() > 0;
}

/*
	operator <=:

	INPUT:
		Fraction to compare with.

	OUTPUT:
		True if the current fraction is smaller or equal to the other.
*/
bool Fraction::operator<=(const Fraction &other) const
{
	return (*this == other || *this < other);
}

/*
	operator >=:

	INPUT:
		Fraction to compare with.

	OUTPUT:
		True if the current fraction is greater or equal to the other.
*/
bool Fraction::operator>=(const Fraction &other) const
{
	return (*this == other || *this > other);
}

/*
	operator !=:

	INPUT:
		Fraction to compare with.

	OUTPUT:
		True if the current fraction is not equal to the other.
*/
bool Fraction::operator!=(const Fraction &other) const
{
	return !(*this == other);
}

/*
	operator =:

	INPUT:
		Fraction to copy.

	OUTPUT:
		Fraction....
*/
Fraction Fraction::operator=(const Fraction &other)
{
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;

	return *this;
}

/*
	operator +:

	INPUT:
		Fraction to add.

	OUTPUT:
		Fraction - result...
*/
Fraction Fraction::operator+(const Fraction &other) const
{
	return Fraction((this->getNumerator() * other.getDenominator()) + (other.getNumerator() * this->getDenominator()), 
					this->getDenominator() * other.getDenominator());
}

/*
	operator -:

	INPUT:
		Fraction to reduce.

	OUTPUT:
		Fraction - result.
*/
Fraction Fraction::operator-(const Fraction &other) const
{
	return Fraction((this->getNumerator() * other.getDenominator()) - (other.getNumerator() * this->getDenominator()),
					this->getDenominator() * other.getDenominator());
}

/*
	operator *:
	
	INPUT:
		Fraction to multiple.
		
	OUTPUT:
		Fraction - result.
*/
Fraction Fraction::operator*(const Fraction &other) const
{
	return Fraction(this->getNumerator() * other.getNumerator(),
					this->getDenominator() * other.getDenominator());
}

/*
	operator /:

	INPUT:
		Fraction to divide by.

	OUTPUT:
		Franction - result.
*/
Fraction Fraction::operator/(const Fraction &other) const
{
	Fraction temp(other.getDenominator(), other.getNumerator());

	return (*this * temp);
}

