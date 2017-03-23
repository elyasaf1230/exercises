#pragma once

#include "CalculatorOperation.h"

class Set : public CalculatorOperation
{
public:

	/*
		Constructor:

		INPUT:
			None.

		OUTPUT:
			None.
	*/
	Set() : CalculatorOperation(1, { "set" }) {

	}

	virtual double calcResult(double currVal, std::vector<std::string> parameters = {})
	{
		if (parameters.size() > this->_requiredParameters) throw std::exception(TOO_MANY_S, TOO_MANY_I);
		if (parameters.size() < this->_requiredParameters) throw std::exception(TOO_LESS_S, TOO_LESS_I);
		
		return std::stod(parameters[0].c_str());
	};
};