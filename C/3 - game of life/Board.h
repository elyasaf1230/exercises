#ifndef _BOARD_H_
#define _BOARD_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100
#define WIDTH 25
#define SUCCESS 1
#define FATAL_ERROR 0
#define ERROR -1
#define LIVE '*'
#define DEAD ' '

typedef struct Board Board;

struct Board
{
	char _board[WIDTH][LENGTH]; //live = '*' dead = ' '
};


/*
	createBoard:
		This function create new board, call initBoard and return it.

	INPUT:
		None.

	OUTPUT:
		pointer tor new board.
*/
Board* createBoard();

/*
	initBoard:
		This function inits the given Board.

	INPUT:
		Pointer to Board to init.

	OUTPUT:
		None.
*/
void initBoard(Board* board);

/*
	killBoard:
		This function destroy the given board.

	INPUT:
		board - pointer to Board to destroy.

	OUTPUT:
		None.
*/
void killBoard(Board* board);

/*
	loadBoardFromFile:
		This function load board from file.
		(format of file - '*' for live ' ' for dead)

	INPUT:
		pointer to Board - the board to load to.
		string - file name to load from.

	OUTPUT:
		int - 1 - success.
			  0 - fatal error ('board' ==  NULL or file could not open)
			 -1 - error - file have too less (or many) chars in it, or there are invalid chars.
*/
int loadBoardFromFile(Board *board, char* fileName);

/*
	updateBoard:
		This function apply the rules on board.

	INPUT:
		pointer to Board - the board to update.

	OUTPUT:
		None (no problem if 'board' is NULL, it the user's problem ;)).
*/
void updateBoard(Board *board);

/*
	howMuchNearMe:
		This function calculate the "neightbors" of the given cell.

	INPUT:
		board - pointer to Board that cell in.
		(x, y) - cell location.

	OUTPUT:
		int - number of live cells near the given cell (return -1 if error).
*/
int howMuchNearMe(char board[][LENGTH], int x, int y);

/*
	printBoard:
		This function print the given board to the screen.

	INPUT:
		board - pointer to Board to print.

	OUTPUT:
		None.
*/
void printBoard(Board *board);

#endif