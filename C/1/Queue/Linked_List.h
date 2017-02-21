#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct Node Node;
typedef struct Linked_List Linked_List;

 
/*
*	Node structure to hold the data.
*	the data is int right now but can be change easly.
*/
struct Node
{
	int   _value;
	Node* _next;
	Node* _prev; 
};

struct Linked_List
{
	Node* _first;
	Node* _last;
	int	  _count; 
	int   _sum;
};


/*
	initList: 
		This function initialize the given list.

	INPUT:
		pointer to the list.

	OUTPUT:
		if success - return 'list'.
		else - return NULL ('list' == NULL, ect...)
*/
Linked_List* initList(Linked_List* list);

/*
	killList:
		The function kill (or destroy) the given list.

	INPUT:
		pointer to the list.

	OUTPUT:
		if success - return 'list'.
		else - return NULL ('list' == NULL, ect...)

*/
Linked_List* killList(Linked_List* list);

/*
	addToList:
		This function add 'node' to the end of 'list'.

	INPUT:
		list - pointer to LinkedList.
		node - node to add to list.

	OUTPUT:
		if success - return 'list'.
		else - NULL. ('list' == NULL ect...)
*/
Linked_List* addNodeToList(Linked_List* list, Node* node);

/*
	addToList:
		This function make new node with the given value,
		and add it to the end of 'list'.

	INPUT:
		list - pointer to LinkedList.
		value - value to add to list.

	OUTPUT:
		if success - return 'list'.
		else - return NULL. ('node'/'list' == NULL ect..)
*/
Linked_List* addValueToList(Linked_List* list, int value);

/*
	removeFromList:
		This function remove 'node' from 'list'.

	INPUT: 
		list - pointer to LinkedList.
		node - pointer to Node.

	OUTPUT:
		if success - return 'list'.
		else - return NULL. ('list' == NULL, 'list' is circular, cannot create new Node due to malloc problem, ect..)
*/
Linked_List* removeFromList(Linked_List* list, Node* node);

/*
	getListLength:
		This function return the length of 'list'.

	INPUT:
		list - pointer to LinkedList.

	OUTPUT:
		int - the length of the list. (-1 if error, 'list' == NULL ect...)
*/
int getListLength(Linked_List* list);

/*
	getFirstNode:
		This function return the first node in 'list'.

	INPUT:
		list - pointer to LinkedList.

	OUTPUT:
		Node* - pointer to the first node in 'list'. (NULL if error, 'list' is empty ect...)
*/
Node* getFirstNode(Linked_List* list);

/*
	getLastNode:
		This function return the last node in 'list'.

	INPUT:
		list - pointer to LinkedList.

	OUTPUT:
		Node* - pointer to the last node in 'list'. (NULL if error, 'list' is empty ect...)
*/
Node* getLastNode(Linked_List* list);

/*
	getNextNode:
		This function return the next Node in 'list', relative to 'node'.

	INPUT:
		list - pointer to LinkedList.
		node - pointer to the current Node.

	OUTPUT:
		Node* - pointer to the next node. (NULL if error, 'list'/'node' == NULL, 'list' is empty, 'node' is the last ect...)
*/
Node* getNextNode(Linked_List* list, Node* node);

/*
	getPrevNode:
		This function return the previous Node in 'list', relative to 'node'.

	INPUT:
		list - pointer to LinkedList.
		node - pointer to the current Node.

	OUTPUT:
		Node* - pointer to the previous node. (NULL if error, 'list'/'node' == NULL, 'list' is empty, 'node' is first ect...)
*/
Node* getPrevNode(Linked_List* list, Node* node);

/*
	getNodeData:
		This function return value of 'node'.

	INPUT:
		node - pointer to Node.

	OUTPUT:
		int - value of 'node' (-1 if error, 'node' == NULL ect...)
*/
int getNodeData(Node* node);

/*
	getAvrage:
		This function return the avrage of all the nodes in 'list'

	INPUT:
		list - pointer to LinkedList.

	OUTPUT:
		double - avrage of all nodes in 'list' (-1 if error, 'list' == NULL, 'list' is empty ect...)
*/
double getAvrage(Linked_List* list);

#endif