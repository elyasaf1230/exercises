#pragma once

#include "CalculatorOperation.h"

class Divide : public CalculatorOperation
{
public:

	/*
		Constructor:

		INPUT:
			None.

		OUTPUT:
			None.
	*/
	Divide() : CalculatorOperation(1, { "/", "div", "divide" }) {

	}

	virtual double calcResult(double currVal, std::vector<std::string> parameters = {})
	{
		if (parameters.size() > this->_requiredParameters) throw std::exception(TOO_MANY_S, TOO_MANY_I);
		if (parameters.size() < this->_requiredParameters) throw std::exception(TOO_LESS_S, TOO_LESS_I);

		return currVal / std::stod(parameters[0].c_str());
	};
};