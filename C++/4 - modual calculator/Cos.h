#pragma once

#include "CalculatorOperation.h"

class Cos : public CalculatorOperation
{
public:

	/*
		Constructor:

		INPUT:
			None.
	
		OUTPUT:
			None.
	*/
	Cos() : CalculatorOperation(0, { "cos", "cosinus" }) {

	}

	virtual double calcResult(double currVal, std::vector<std::string> parameters = {})
	{
		if (parameters.size() > this->_requiredParameters) throw std::exception(TOO_MANY_S, TOO_MANY_I);

		return cos(currVal);
	};
};