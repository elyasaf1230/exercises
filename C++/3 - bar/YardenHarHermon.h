#pragma once

#include <iostream>
#include <string>
#include "RedWine.h"

class YardenHarHermon : public RedWine
{
public:
	YardenHarHermon(int year) : RedWine(year, "'Yarden HarHermon'") {}
};