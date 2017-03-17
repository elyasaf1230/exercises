#pragma once

#include <iostream>
#include <string>
#include "Drink.h"

class Wine : public Drink
{
protected: 
	int _year;
public:
	Wine(int year, std::string name) : Drink(name + std::string(" wine")) { this->_year = year; }
	virtual std::string getName() { return this->_name + std::string(" (year ") + std::to_string(this->_year) + std::string(")"); }
};
