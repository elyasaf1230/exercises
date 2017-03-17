#pragma once

#include <iostream>
#include <string>
#include "Drink.h"

class Juice : public Drink
{
public:
	Juice(std::string name) : Drink(name + std::string(" juice")) { }
	virtual std::string prepare() { return "Well, all you need to do is pour it into a glass, add some ice and serve."; }
};
