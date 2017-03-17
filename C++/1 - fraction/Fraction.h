#pragma once

#include <iostream>
#include <string>

class Fraction
{
private:
	int _numerator;
	int _denominator;

	void simplify();
	
public:
	//constructors
	Fraction(const int numerator, const int denominator = 1);
	Fraction(const double number);
	Fraction(const Fraction &other);
	Fraction();

	//destructors
	~Fraction();
	
	//getters
	int getNumerator() const;
	int getDenominator() const;

	//setters
	void setNumerator(const int numerator);
	bool setDenominator(const int denominator);

	//conversations
	std::string to_string() const;
	double to_double() const;

	//operators
	bool	operator==(const Fraction &other) const;
	bool	operator<(const Fraction &other) const;
	bool	operator>(const Fraction &other) const;
	bool	operator<=(const Fraction &other) const;
	bool	operator>=(const Fraction &other) const;
	bool	operator!=(const Fraction &other) const;
	Fraction operator=(const Fraction &other);
	Fraction operator+(const Fraction &other) const;
	Fraction operator-(const Fraction &other) const;
	Fraction operator*(const Fraction &other) const;
	Fraction operator/(const Fraction &other) const;
};