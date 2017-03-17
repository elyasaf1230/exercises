#pragma once

#include <iostream>
#include <string>
#include "WhiteWine.h"

class CarmelEmeraldRiesling : public WhiteWine
{
public:
	CarmelEmeraldRiesling(int year) : WhiteWine(year, "'Carmel Emerald Riesling'") {}
};