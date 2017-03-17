#pragma once

#include <iostream>
#include <string>
#include "RedWine.h"

class ChadeauMargot : public RedWine
{
public:
	ChadeauMargot(int year) : RedWine(year, "'Chadeau Margot'") {}
};