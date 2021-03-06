#pragma once

#include "CalculatorOperation.h"

class Tan : public CalculatorOperation
{
public:

	/*
		Constructor:

		INPUT:
			None.

		OUTPUT:
			None.
	*/
	Tan() : CalculatorOperation(0, { "tan", "tangens" }) {

	}

	virtual double calcResult(double currVal, std::vector<std::string> parameters = {})
	{
		if (parameters.size() > this->_requiredParameters) throw std::exception(TOO_MANY_S, TOO_MANY_I);

		return tan(currVal);
	};
};