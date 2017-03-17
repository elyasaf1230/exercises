#pragma once

#include <iostream>
#include <string>
#include "WhiteWine.h"

class GolanSmadar : public WhiteWine
{
public:
	GolanSmadar(int year) : WhiteWine(year, "'Golan Smadar'") {}
};