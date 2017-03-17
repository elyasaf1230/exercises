#include <iostream>
#include <string>

#include "Beer.h"
#include "Juice.h"

//red wines
#include "Chianti.h"
#include "YardenCabernetSauvignon.h"
#include "ChadeauMargot.h"
#include "YardenHarHermon.h"
//white wines
#include "GolanSmadar.h"
#include "YardenShardone.h"
#include "CarmelEmeraldRiesling.h"

#define STOCK_SIZE 10 
#define LIST_OPTIONS 0
#define HOW_PREPARE 99
#define LEAVE 100

void loadStock(Drink* stock[]); 
void printMenu(Drink* stock[]);
void deleteStock(Drink* stock[]);

int main()
{
	Drink* stock[STOCK_SIZE] = { NULL };
	Drink* lastDrink = NULL;
	int choice;

	try
	{
		loadStock(stock);
	}
	catch (...)
	{
		std::cout << "Failed on initStock!" << std::endl << "ERROR: probably bad allocation..." << std::endl;
		exit(0);
	}

	while (true)
	{
		std::cout << "What can I get you, sir? ( 0 - list options)" << std::endl;

		std::cin >> choice;

		if (choice <= STOCK_SIZE && choice > 0)
		{
			std::cout << "One " << stock[choice - 1]->getName() << " is coming up, sir." << std::endl;
			lastDrink = stock[choice - 1];
		}
		else if (choice == LIST_OPTIONS)
		{
			printMenu(stock);
		}
		else if (choice == HOW_PREPARE)
		{
			if (lastDrink == NULL)
				std::cout << "Are you crazy!?\nYou haven't pick any, and still you are out of your mind!" << std::endl;
			else
				std::cout << "Your last drink is: " << lastDrink->getName() << std::endl << lastDrink->prepare() << std::endl;
		}
		else if (choice == LEAVE)
		{
			std::cout << "Bar is closed! Good night!";
			break;
		}
	}

	deleteStock(stock);
	
	getchar();
	getchar();

	return 0;
}


/*
	loadStock:
		This function creates and load to the given array the drinks of the back.

	INPUT:
		stock - array to store the drinks.

	OUTPUT:
		None.
*/
void loadStock(Drink* stock[])
{
	stock[0] = new CarmelEmeraldRiesling(1986);
	stock[1] = new GolanSmadar(-1989);
	stock[2] = new YardenHarHermon(1994);
	stock[3] = new YardenShardone(1997);
	stock[4] = new Chianti(1997);
	stock[5] = new YardenCabernetSauvignon(1997);
	stock[6] = new ChadeauMargot(1997);

	stock[7] = new Beer("Heineken");
	stock[8] = new Beer("Goldstar");

	stock[9] = new Juice("Petel");
	
	return;
}

/*
	printMenu:
		This function prints out the menu of the bar acording to the available stock.

	INPUT:
		stock - array of drinks available.

	OUTPUT:
		None.
*/
void printMenu(Drink* stock[])
{
	//prints first option (list options)
	std::cout << "(" << std::to_string(LIST_OPTIONS) + ") list options" << std::endl;

	for (int i = 1; i <= STOCK_SIZE; ++i)
	{
		std::cout << "(" << std::to_string(i) << ") " << stock[i - 1]->getName() << std::endl;
	}

	//printing the prepare and leave options:
	std::cout << "(" << std::to_string(HOW_PREPARE) + ") How did you prepare my last drink?" << std::endl;
	std::cout << "(" << std::to_string(LEAVE) + ") Leave the bar" << std::endl;

	return;
}

/*
	deleteStock:
		This function delete the allocated memory of the drinks.

	INPUT:
		stock - array of drinks to delete.

	OUTPUT:
		None.
*/
void deleteStock(Drink* stock[])
{
	for (int i = 0; i < STOCK_SIZE; ++i)
	{
		delete stock[i];
	}

	return;
}
