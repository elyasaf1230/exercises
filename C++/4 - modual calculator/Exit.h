#pragma once

#include "CalculatorOperation.h"

class Exit : public CalculatorOperation
{
public:

	/*
		Constructor:

		INPUT:
			None.

		OUTPUT:
			None.
	*/
	Exit() : CalculatorOperation(0, { "exit", "quit", "q" }) {

	}

	virtual double calcResult(double currVal, std::vector<std::string> parameters = {})
	{
		if (parameters.size() > this->_requiredParameters) throw std::exception(TOO_MANY_S, TOO_MANY_I);
		
		return currVal;
	};
};