#pragma once

#include <iostream>
#include <string>
#include "Wine.h"

class WhiteWine : public Wine
{
public:
	WhiteWine(int year, std::string name) : Wine(year, name + std::string(" white")) {}
	virtual std::string prepare() { return std::string("The wine should be cold.\nYou pour it into a fancy glass and serve."); }
};
