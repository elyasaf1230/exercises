#ifndef _PANEL_H_
#define _PANEL_H_

#include <stdio.h>

typedef struct Panel Panel;

struct Panel
{
	int weight; //this represents the weight of the panel.
	unsigned int distance; //this represents the distance from the beginning until the current panel (including the weight).

	//this represents the place of the panel in the matrix (not really important, just to make it simple):
	int x;
	int y;
};


#endif