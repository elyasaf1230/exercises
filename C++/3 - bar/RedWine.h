#pragma once

#include <iostream>
#include <string>
#include "Wine.h"

class RedWine : public Wine
{
public:
	RedWine(int year, std::string name) : Wine(year, name + std::string(" red")) {}
	virtual std::string prepare() { return std::string("The wine should be in the room temperature (16-18).\nYou pour it into a fancy glass and serve."); }
};
