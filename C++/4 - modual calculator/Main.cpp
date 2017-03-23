#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <locale>
#include <algorithm>

#include "CalculatorOperation.h"

#include "Set.h"
#include "Add.h"
#include "Sub.h"
#include "Multi.h"
#include "Divide.h"
#include "Pow.h"
#include "Sqrt.h"
#include "Log.h"
#include "Sin.h"
#include "Cos.h"
#include "Tan.h"
#include "Exit.h"

#define BUFFER_SIZE 100

void initOperations(std::vector<CalculatorOperation*> &operations);
void killOperations(std::vector<CalculatorOperation*> &operations);

void getParameters(std::vector<std::string> &parameters, int numOfParameters);
CalculatorOperation* getSuitableOperation(std::vector<CalculatorOperation*> &operations, std::string operation);

int main()
{
	std::vector<CalculatorOperation*> availableOperations;
	std::string operation = "";
	std::vector<std::string> parameters;
	CalculatorOperation* currentOperation = NULL;
	double reg = 0;

	//load the available operations
	initOperations(availableOperations);

	std::cout << "Wellcome to my advanced modular calculator!" <<std::endl;

	while (currentOperation != availableOperations.back())
	{
		std::cout << "-> ";
		//getting the operation
		std::cin >> operation;
		
		//lower it
		std::transform(operation.begin(), operation.end(), operation.begin(), tolower);

		//getting the suitable operation
		currentOperation = getSuitableOperation(availableOperations, operation);

		//check if found
		if (currentOperation == NULL)
		{
			//cleaning the buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Operation not supported!" << std::endl;
			continue;
		}

		//getting the parameters
		getParameters(parameters, currentOperation->requiredParametrs());

		//calculate the result
		try
		{
			reg = currentOperation->calcResult(reg, parameters);
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	
		//printing the current value
		std::cout << "Current value is: " << reg << std::endl;

		//clear the parameters vector
		parameters.clear();
	}

	//clear the operations from memory
	killOperations(availableOperations);

	std::cout << "GoodBye!" << std::endl;

	getchar();

	return 0;
}


/*
	This function inits the operations of the calculator.

	INPUT:
		vector of operations to init.

	OUTPUT:
		None.

*/
void initOperations(std::vector<CalculatorOperation*> &operations)
{
	operations.push_back(new Set());
	operations.push_back(new Add());
	operations.push_back(new Sub());
	operations.push_back(new Multi());
	operations.push_back(new Divide());
	operations.push_back(new Pow());
	operations.push_back(new Sqrt());
	operations.push_back(new Log());
	operations.push_back(new Sin());
	operations.push_back(new Cos());
	operations.push_back(new Tan());
	operations.push_back(new Exit()); //exit should allways be the last operation
}

/*
	This function free all the mess initOperations did...

	INPUT:
		vector - the operations.

	OUTPUT:
		None.
*/
void killOperations(std::vector<CalculatorOperation*> &operations)
{
	while (operations.size() > 0)
	{
		delete operations.back();
		operations.pop_back();
	}
}

/*
	This function getting the parameters from the user and parsing it to the given vector.

	INPUT:
		vector - the vector to store the parametrs from the user.

	OUTPUT:
		None.
*/
void getParameters(std::vector<std::string> &parameters, int numOfParameters)
{
	std::string parameter;

	//parsing the parameters and put into the vector
	for (int i = 0; i < numOfParameters; ++i)
	{
		//read the parameter
		std::cin >> parameter;

		//push the parameter into the vector
		parameters.push_back(parameter);
	}
}

/*
	This function moving on all operations in the vector untill it finds operation that support the given operation.

	INPUT:
		operations - operation to run on.
		operation  - operation to search for.

	OUTPUT:
		The suitable operation.
		NULL if can' find the required operation.
*/
CalculatorOperation* getSuitableOperation(std::vector<CalculatorOperation*> &operations, std::string operation)
{
	CalculatorOperation* ret = NULL;

	for (int i = 0; i < operations.size() && !ret; ++i)
	{
		if (operations[i]->supportsOperation(operation))
		{
			ret = operations[i];
		}
	}

	return ret;
}