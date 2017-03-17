#pragma once

#include <iostream>
#include <string>
#include "Drink.h"

class Beer : public Drink
{
public:
	Beer(std::string name) : Drink(name + std::string(" beer")) { }
	virtual std::string prepare() { return "Well, all you need to do is pour it into a glass and serve."; }
};
