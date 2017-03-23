#pragma once

#include "CalculatorOperation.h"

class Sqrt : public CalculatorOperation
{
public:

	/*
		Constructor:

		INPUT:
			None.

		OUTPUT:
			None.
	*/
	Sqrt() : CalculatorOperation(0, { "sqrt" }) {

	}

	virtual double calcResult(double currVal, std::vector<std::string> parameters = {})
	{
		if (parameters.size() > this->_requiredParameters) throw std::exception(TOO_MANY_S, TOO_MANY_I);

		return sqrt(currVal);
	};
};