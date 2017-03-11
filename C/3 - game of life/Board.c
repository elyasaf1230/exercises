#include "Board.h"

Board* createBoard()
{
	//allocate the board itself.
	Board* board = (Board*)malloc(sizeof(Board));

	if (board == NULL) return NULL;

	initBoard(board);

	return board;
}

void initBoard(Board* board)
{
	int x, y;

	if (board == NULL) return;

	for (y = 0; y < WIDTH; ++y)
	{
		for (x = 0; x < LENGTH; ++x)
		{
			board->_board[y][x] = LIVE;
		}
	}

	return;
}

void killBoard(Board* board)
{
	free(board);
}

int loadBoardFromFile(Board *board, char* fileName)
{
	int x, y, ret = SUCCESS;
	char buffer;
	FILE *file = fopen(fileName, "r");

	if (board == NULL || file == NULL) return FATAL_ERROR;

	//reading chars from file and insert to the board.
	for (y = 0; y < WIDTH; ++y)
	{
		for (x = 0; x < LENGTH; ++x)
		{
			buffer = fgetc(file);

			//checking if invali or EOF.
			if (buffer == EOF || (buffer != LIVE && buffer != DEAD))
				break;

			//insert the char into the board.
			board->_board[y][x] = buffer;
		}

		if (x < LENGTH) //if there was a break in the inner loop
			break;

		//there should be '\n' after each line, so lets pop it out.
		buffer = fgetc(file);
		if (buffer != '\n') //(last line is fine...)
			break;
	}

	if (y < WIDTH) // if there was a break in the loopp
		ret = ERROR;

	//closing the file.
	fclose(file);

	return ret;
}

void updateBoard(Board *board)
{
	int x, y, temp;
	char BoardCopy[WIDTH][LENGTH];
	if (board == NULL) return;

	/*
		to implement this function I created howMuchNearMe, 
		which gives us the live neighbors of the current cell.
		Then we will have to decide if the cell should be live or dead... Muahahaha! I have The POWER!!!

		One problem that I aware of:
		When updating the board I change it, so I change the results...
		To solve it I can make a copy of the board...


	RULES!:
	
		For a space that is 'populated':
			Each cell with one or no neighbors dies, as if by solitude.
			Each cell with four or more neighbors dies, as if by overpopulation.
			Each cell with two or three neighbors survives.
		For a space that is 'empty' or 'unpopulated'
			Each cell with three neighbors becomes populated.
	
		(Yeah, I copy that from the internet ^-^)
	*/

	//init the copy:
	for (y = 0; y < WIDTH; ++y)
	{
		for (x = 0; x < LENGTH; ++x)
		{
			BoardCopy[y][x] = board->_board[y][x];
		}
	}

	//running on all the cells in copy and update in the board.
	for (y = 0; y < WIDTH; ++y)
	{
		for (x = 0; x < LENGTH; ++x)
		{
			temp = howMuchNearMe(BoardCopy, x, y);
			switch (temp)
			{	
			case 2:
				break; //remain live or dead :/
			case 3:
				board->_board[y][x] = LIVE;
				break;
			default:
				//if 0,1, 4 or more
				board->_board[y][x] = DEAD;
				break;
			}
		}
	}

	return;
}

int howMuchNearMe(char board[][LENGTH], int x, int y)
{
	int Xcurr = x - 1, Ycurr = y - 1, countLive = 0;

	if (board == NULL || x >= LENGTH || y >= WIDTH) return ERROR;

	//counting the lives (max is 9, like the souls of a cat *_*)
	for (Ycurr = y - 1; Ycurr <= y + 1; ++Ycurr)
	{
		for (Xcurr = x - 1; Xcurr <= x + 1; ++Xcurr)
		{
			if (Ycurr >= 0 && Xcurr >= 0 && Ycurr < WIDTH && Xcurr < LENGTH && board[Ycurr][Xcurr] == LIVE)
			{
				++countLive;
			}
		}
	}

	//max is 9 because I am counting the center, let's fix it.
	if (board[y][x] == LIVE)
		--countLive;

	return countLive;
}

void printBoard(Board *board)
{
	int x = 0, y = 0;

	if (board == NULL) return;

	for (y = 0; y < WIDTH; ++y)
	{
		for (x = 0; x < LENGTH; ++x)
		{
			printf("%c", board->_board[y][x]);
		}
		printf("\n");
	}
	return;
}