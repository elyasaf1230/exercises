#pragma once

#include "CalculatorOperation.h"

class Sin : public CalculatorOperation
{
public:

	/*
		Constructor:

		INPUT:
			None.

		OUTPUT:
			None.
	*/
	Sin() : CalculatorOperation(0, { "sin", "sinus" }) {

	}

	virtual double calcResult(double currVal, std::vector<std::string> parameters = {})
	{
		if (parameters.size() > this->_requiredParameters) throw std::exception(TOO_MANY_S, TOO_MANY_I);

		return sin(currVal);
	};
};