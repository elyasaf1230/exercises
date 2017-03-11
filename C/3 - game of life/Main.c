#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Board.h"


int main(int argc, char* argv[])
{
	Board* myboard = NULL;
	int temp = 0;
	char filename[FILENAME_MAX];

	//checking args:
	if (argc != 2)
	{
		printf("Wrong arguments, Format:\nGameOfLife.exe [fileName.txt]\n");
		getchar();
		exit(0);
	}

	//create new board:
	if ((myboard = createBoard()) == NULL)
	{
		printf("Failed to allocate the board! check your memory!\n");
		getchar();
		exit(0);
	}

	//load from file:
	strcpy(filename, argv[1]);
	temp = loadBoardFromFile(myboard, filename);

	if (temp == ERROR)
	{
		printf("Failed to load from file, Check your file!\n");
		printf("Format: ' ' for dead cells, '*' for live cells\n");
		printf("You need %d lines and %d cells in each line\n", WIDTH, LENGTH);
		getchar();
		exit(0);
	}
	else if (temp == FATAL_ERROR)
	{
		printf("Fatal Error - Check your file's name!\n");
		getchar();
		exit(0);
	}

	//printing first:
	printBoard(myboard);

	//now need to update the board and print it, 
	//we sould make a wait between the updates so it won't be too fast..
	while (temp != 'q')
	{
		printf("press 'q' to exit, anything else to the next move: \n");
		temp = getch();
		updateBoard(myboard);
		printBoard(myboard);
	}
	
	//deleting the board:
	killBoard(myboard);

	return 0;
}

