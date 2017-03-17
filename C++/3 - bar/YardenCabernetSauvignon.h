#pragma once

#include <iostream>
#include <string>
#include "RedWine.h"

class YardenCabernetSauvignon : public RedWine
{
public:
	YardenCabernetSauvignon(int year) : RedWine(year, "'Yarden Cabernet Sauvignon'") {}
};