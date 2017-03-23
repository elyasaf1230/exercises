#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cmath>

#define TOO_MANY_I 1
#define TOO_MANY_S "Too many arguments!"
#define TOO_LESS_I 2
#define TOO_LESS_S "Too less arguments!"
#define INVALID_I  3
#define INVALID_S "Invalid argument!"

class CalculatorOperation
{
protected:
	int _requiredParameters;
	std::vector<std::string> _operations;

public:

	/*
		Constructor:

		INPUT:
			requiredParameters - number of required parameters for the operation.
			operations - names of the operation.

		OUTPUT:
			None.
	*/
	CalculatorOperation(int requiredParameters, std::vector<std::string> operations){
		this->_requiredParameters = requiredParameters;
		this->_operations = operations;
	};

	/*
		This method return true if the given operation is supported, and false if not.

		INPUT:
			op_string - std::string with the operation to check.

		OUTPUT:
			bool - true if supported and false if not.
	*/
	bool supportsOperation(std::string op_string) const {
		return !(std::find(this->_operations.begin(), this->_operations.end(), op_string) == this->_operations.end());
	};
	
	/*
		This methor return how much parametrs this operation needs.

		INPUT:
			None.

		OUPUT:
			int - number of required parameters.
	*/
	int requiredParametrs() const {
		return this->_requiredParameters; 
	};

	/*
		This method should calculate the result of the operation on 'currVal' and the give parameters.

		INPUT:
			currVal - the number (double) the operate work on.
			parameters - additional parameters to the operation. (optional if there are no parameters).

		OUTPUT:
			double - result.

		Note:
			This method should throw exceptions if there are not enough, too much, or invalid parameters.
	*/
	virtual double calcResult(double currVal, std::vector<std::string> parameters = {}) = 0;
};