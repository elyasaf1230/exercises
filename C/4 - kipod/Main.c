/*
	Instructions: (always wanted to say it ^_^)

	* The program gets file with 100*100 ints (\t between columns, \n between rows).
	* The program will print the best way from (0,0) to (99,99) to the screen.
	
	*To make this program posible, I took the LinkedList and Queue structures from exercise 1 
	 and modify it to make it suitable to this exercise.

	* I could make structure for the Panels matrix and put the funtions defined here next to it, 
	  but I chose to implement this task as a program and not as a library.

	* file format:
			100*100 numbers between 0 and 100.
			Columns separated with '\t'.
			Rows separated with '\n'.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Linked_List.h"
#include "Queue.h"
#include "Panel.h"

#define WORLD_LENGTH 100
#define WORLD_WIDTH  100

#define MAX_SIZE 100
#define SIZE_OF_NUM 5 //largest number is 1000 - 4 digits, + '\0' = 5 digits

#define UP_LEFT		-4
#define UP			-3
#define UP_RIGHT	-2
#define LEFT		-1
#define CENTER		 0
#define RIGHT		 1
#define DOWN_LEFT	 2
#define DOWN		 3
#define DOWN_RIGHT	 4


/*
	loadWorldFromFile:
		This function read world from file and assign it in the given array.

	INPUT:
		world - array of panels to init.
		fileName - name of the file to read from.

	OUTPUT:
		Panel* - if success - return world, if failed - return NULL.
*/
Panel* loadWorldFromFile(Panel world[][WORLD_LENGTH], char* fileName);

/*
	initWorld:
		This function inits the given world.

	INPUT:
		world - array of Panels...

	OUTPUT:
		Panel* - world on success, NULL on failure
*/
Panel* initWorld(Panel world[][WORLD_LENGTH]);

/*
	calcDistance:
		This function calculates the distance from panel 'src' to all the panels in the matrix 'world'.
		(This function implements the dijkstra algorithm)

	INPUT:
		world - array of panels.
		src - source panel.

	OUTPUT:
		None. (the return value is in the panels (Panel.distance))
*/
void calcDistance(Panel world[][WORLD_LENGTH], Panel* src);

/*
	printWay:
		This function prints the best way that calculated previusly by 'calcDistance'.
		To acomplish this, the function will go from dst to src and push all the panels in LinkedList, 
		so it will be able to read it from end to start..

	INPUT:
		world - array of panels.
		src - source panel.
		dst - destnation panel.

	OUTPUT:
		None.		
*/
void PrintWay(Panel world[][WORLD_LENGTH], Panel* src, Panel* dst);

/*
	getNeighbours:
		This function place the neighbours of the given Panel in the given Queue.

	INPUT:
		world - array of Panels.
		panel - pointer to the current Panel.
		queue - Queue to place the neighbours in.

	OUTPUT:
		None. (results can be fount in the queue...)
*/
void getNeighbours(Panel world[][WORLD_LENGTH], Panel* panel, Queue* queue);

/*
	getDirection:
		This function return number that indicates the direction from 'from' to 'to'. (lol)

		INPUT:
			from - panel from...?
			to - panel to....?

		OUTPUT:
			int - defines... 
*/
int getDirection(Panel* from, Panel* to);

int main(int argc, char* argv[])
{
	Panel world[WORLD_WIDTH][WORLD_LENGTH];
	char filename[MAX_SIZE];
	//checking the arguments
	if (argc != 2)
	{
		printf("Invalid argumants!\nUsage: Moshe.exe [File Name]\n");
		getchar();
		exit(0);
	}

	if (initWorld(world) != world)
	{
		printf("Something went wrong, go away, I need to recover\n");
		getchar();
		exit(0);
	}

	strcpy_s(filename, MAX_SIZE, argv[1]);

	if (loadWorldFromFile(world, filename) != world)
	{
		printf("Could not load world from file (did you spelled it correctly?)!\n");
		getchar();
		exit(0);
	}

	printf("load from file success!\n");

	//init the begining panel
	world[0][0].distance = 0;

	calcDistance(world, &world[0][0], &world[WORLD_WIDTH - 1][WORLD_LENGTH - 1]);
	printf("clac distance success!\n");

	PrintWay(world, &world[0][0], &world[WORLD_WIDTH - 1][WORLD_LENGTH - 1]);

	printf("Congratulations!\nNow go away, let me rest...\n");

	getchar();
	return 0;
}

Panel* loadWorldFromFile(Panel world[][WORLD_LENGTH], char* fileName)
{
	FILE *file; 
	int y = 0, x = 0, error = 0, i = 0, num = 0;
	char numS[SIZE_OF_NUM], temp = ' ';

	if (world == NULL || fileName == NULL) return NULL;
	
	file = fopen(fileName, "r");

	if (file == NULL) return NULL;

	
	for (y = 0; y < WORLD_WIDTH && error == 0; ++y)				//
	{															// moving on all the matrix
		for (x = 0; x < WORLD_LENGTH && error == 0; ++x)		//
		{
			//init temp
			temp = ' ';

			//init numS (read number from file)
			for (i = 0; i < SIZE_OF_NUM && temp != EOF && temp != '\t' && temp != '\n'; ++i)
			{
				//read one char
				temp = (char)fgetc(file);

				//check if digit
				if (!((temp >= '0' && temp <= '9') || temp == '\t' || temp == '\n' || temp == EOF))
					error = 1;

				//assign it to the string
				numS[i] = temp;
			}

			//checking if string is valid:
			switch (numS[i - 1]) //or 'temp' 
			{
			case EOF:
				if (y != WORLD_WIDTH - 1 || x != WORLD_LENGTH - 1) //not the end of the matrix
					error = 1;
				break;
			case '\n':
				if (x != WORLD_LENGTH - 1) //not the end of the line
					error = 1;
			case '\t':
				if (i == 1) // no digits in Snum
					error = 1;
				break;
			default:
				break;
			}

			//setting last char in string
			numS[i - 1] = '\0';

			//convert to number
			num = atoi(numS);

			//check if number is valid and assign to world
			if (num > 1000 || num < 0)
				error = 1;
			else
				world[y][x].weight = num;
		}
	}

	if (error == 1)
		return NULL;
	return world;
}

Panel* initWorld(Panel world[][WORLD_LENGTH])
{
	unsigned int y = 0, x = 0;

	if (world == NULL) return NULL;

	for (y = 0; y < WORLD_WIDTH; ++y)			//
	{											// moving on all the matrix
		for (x = 0; x < WORLD_LENGTH; ++x)		//
		{
			world[y][x].x = x;
			world[y][x].y = y;
			world[y][x].weight = 0;
			world[y][x].distance = -1; //infinite... largest number that 'unsigned int' can get.
		}
	}

	return world;
}

void calcDistance(Panel world[][WORLD_LENGTH], Panel* src)
{
	Queue panelsToCheck, neighboursPanels;
	Panel *currentPanel, *neighbourPanel;

	if (initQueue(&panelsToCheck) != &panelsToCheck, initQueue(&neighboursPanels) != &neighboursPanels)
	{
		printf("init queue failed? what the hack?!");
		return;
	}
	
	if (push_back(&panelsToCheck, src) != &panelsToCheck)
	{
		printf("push to queue failed? what the hack?!");
		return;
	}

	while (getQueueLength(&panelsToCheck) > 0) //until there is no more panels to check
	{
		//pop the current panel to check
		currentPanel = pop(&panelsToCheck);

		//getting the neighbours of the current panel
		getNeighbours(world, currentPanel, &neighboursPanels);

		//run on all the neighbors
		while (getQueueLength(&neighboursPanels) > 0)
		{
			//pop the current neighbour
			neighbourPanel = pop(&neighboursPanels);

			//if need to update the distance, updating and pushing to the queue to check.
			if (currentPanel->distance + neighbourPanel->weight < neighbourPanel->distance)
			{
				neighbourPanel->distance = currentPanel->distance + neighbourPanel->weight;
				push_back(&panelsToCheck, neighbourPanel); //yeah yeah, I know, I should check the return value but... no! Please no! ;(
			}
		}
	}
	//at this point, all the panels in world should have the lowest distance from src.

	killQueue(&panelsToCheck);
	killQueue(&neighboursPanels);

	return;
}

void PrintWay(Panel world[][WORLD_LENGTH], Panel* src, Panel* dst)
{
	//to print the way from src to dst we need to go from dst to src, (cant go from src to dst..)
	//push it in linkedList and then go from the end to the beginning...

	Linked_List way;
	Node* currentNode = NULL;
	Queue neighbours;
	Panel *currentPanel = dst, *nextPanel = NULL;
	int temp;

	if (initList(&way) != &way)
	{
		printf("init list failed!");
		return;
	}

	while (currentPanel != src) //until end (beginning, yeah, it's confusing...)
	{
		//pushing the current panel to the list
		if (addValueToList(&way, currentPanel) != &way)
		{
			printf("add value to list failed!");
			return;
		}

		//init the queue of neighbours
		if (initQueue(&neighbours) != &neighbours)
		{
			printf("init queue failed!");
			return;
		}

		//getting neighbours
		getNeighbours(world, currentPanel, &neighbours);

		//running on all neighbours and search for the next panel
		while (getQueueLength(&neighbours) > 0)
		{
			//get one of the neighbours
			nextPanel = pop(&neighbours);

			//check if nextPanel is on the way (is the correct next panel)
			if (nextPanel->distance + currentPanel->weight == currentPanel->distance)
			{
				currentPanel = nextPanel;
				break;
			}
		}

		//cleaning the queue
		killQueue(&neighbours);
	}

	//pushing the first panel (src) to the list
	if (addValueToList(&way, src) != &way)
	{
		printf("add value to list failed!");
		return;
	}

//printing the results:
	printf("Best way from (%d,%d) to (%d,%d) is (be careful, one wrong turn and I wont be able to help you get out of the mess):\n", src->x, src->y, dst->x, dst->y);

	//starting from src
	currentNode = getLastNode(&way);

	while (currentNode != getFirstNode(&way)) //running on the way (king way)
	{
		//get direction from current node to previus node.
		temp = getDirection(getNodeData(currentNode), getNodeData(getPrevNode(&way, currentNode)));

		//printing the direction
		switch (temp)
		{
		case UP_LEFT:
			printf("up left\n");
			break;
		case UP:
			printf("up\n");
			break;
		case UP_RIGHT:
			printf("up right\n");
			break;
		case LEFT:
			printf("left\n");
			break;
		case RIGHT:
			printf("right\n");
			break;
		case DOWN_LEFT:
			printf("down left\n");
			break;
		case DOWN:
			printf("down\n");
			break;
		case DOWN_RIGHT:
			printf("down right\n");
			break;
		case CENTER:
			printf("WTH?!?!\n");
			break;
		default:
			break;
		}

		//move to the next step
		currentNode = getPrevNode(&way, currentNode);
	}

	//finished
	printf("You have arrived!\n");

	killList(&way);

	return;
}

void getNeighbours(Panel world[][WORLD_LENGTH], Panel* panel, Queue* queue)
{
	int x = 0, y = 0;

	if (world == NULL || panel == NULL || queue == NULL) return;

	for (y = panel->y - 1; y <= panel->y + 1; ++y)
	{
		for (x = panel->x - 1; x <= panel->x + 1; ++x)
		{
			if (y >= 0 && y < WORLD_WIDTH &&			//check if in range
				x >= 0 && x < WORLD_LENGTH &&		//check if in range
				!(y == panel->y && x == panel->x))	//check if not panel
				push_back(queue, &world[y][x]); //pushing to queue
		}
	}
	return;
}

int getDirection(Panel* from, Panel* to)
{
	return ((to->y - from->y) * 3 + (to->x - from->x));
}