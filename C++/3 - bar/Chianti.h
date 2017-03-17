#pragma once

#include <iostream>
#include <string>
#include "RedWine.h"

class Chianti : public RedWine
{
public:
	Chianti(int year) : RedWine(year, "'Chianti'") {}
};