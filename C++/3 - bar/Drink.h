#pragma once

#include <iostream>
#include <string>

class Drink
{
protected:
	std::string _name;

public:
	Drink(std::string name) { this->_name = name; }
	virtual std::string getName() { return this->_name; }
	virtual std::string prepare() = 0;
};
