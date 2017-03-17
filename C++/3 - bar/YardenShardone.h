#pragma once

#include <iostream>
#include <string>
#include "WhiteWine.h"

class YardenShardone : public WhiteWine
{
public:
	YardenShardone(int year) : WhiteWine(year, "'Yarden Shardone'") {}
};