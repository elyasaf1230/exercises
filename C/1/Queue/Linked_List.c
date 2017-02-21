#include "Linked_List.h"

Linked_List* initList(Linked_List* list)
{
	//if list is empty
	if (list == NULL) return NULL;

	list->_first = NULL;
	list->_last  = NULL;
	list->_count = 0;
	list->_sum   = 0;

	return list;
}

Linked_List* killList(Linked_List* list)
{
	Node *curr = NULL, *next = NULL;

	//if list is empty
	if (list == NULL) return NULL;
	
	//starting from first to last
	curr = list->_first;

	//deleting all nodes
	while (curr != NULL)
	{
		//saving the next to move to it later
		next = curr->_next;

		//deleting the current node
		free(curr);

		//moving to the next node
		curr = next;
	}

	//init list
	initList(list);

	return list;
}

Linked_List* addNodeToList(Linked_List* list, Node* node)
{
	if (list == NULL || node == NULL) return NULL;

	//the new node should be the last node, so it's next should be NULL
	node->_next = NULL;

	//obviously, we need to put 'node' as the next of the '_last',
	//but if the list is empty, _first and _last are NULL,
	//so let's say that if _first is NULL, the list is empty.
	if (list->_first == NULL){
		//node is the first so it's prev is NULL
		node->_prev = NULL;

		//placing node
		list->_first = node;
		list->_last = node;
	}
	else //list not empty
	{
		//tie up the new node with the last node of the list
		node->_prev = list->_last;
		list->_last->_next = node;

		//set the new node as the last node of the list.
		list->_last = node;
	}

	//add the data to sum and count
	++list->_count;
	list->_sum += node->_value;

	return list;
}

Linked_List* addValueToList(Linked_List* list, int value)
{
	//in this function we just make new node and call addToList(Linked_List* list, Node* node)

	if (list == NULL) return NULL;

	//creating new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return NULL;

	//placing the data
	newNode->_next = NULL;
	newNode->_prev = NULL;
	newNode->_value = value;

	//adding to list
	return addNodeToList(list, newNode);
}

Linked_List* removeFromList(Linked_List* list, Node* node)
{
	Node *prev = NULL, *next = NULL;

	if (list == NULL || node == NULL) return NULL;

	//first, we tie up the prev with the next:
	prev = node->_prev;
	next = node->_next;

	//dealing with prev
	if (prev != NULL) //is not first (equal to: list->_first != node)
	{
		prev->_next = next;
	}
	else //is first (equal to: list->_first == node)
	{
		list->_first = next;
	}

	//dealing with next
	if (next != NULL) //is not last (equal to: list->_last != node)
	{
		next->_prev = prev;
	}
	else //is last (equal to: list->_last == node)
	{
		list->_last = prev;
	}
	
	
	//updating the list:
	--list->_count;
	list->_sum -= node->_value;

	//deleting the node:
	free(node);

	return list;
}

int getListLength(Linked_List* list)
{
	if (list == NULL) return -1;

	return list->_count;
}

Node* getFirstNode(Linked_List* list)
{
	if (list == NULL) return NULL;

	return (list->_first);
}

Node* getLastNode(Linked_List* list)
{
	if (list == NULL) return NULL;

	return list->_last;
}

Node* getNextNode(Linked_List* list, Node* node)
{
	if (list == NULL || node == NULL || list->_first == NULL) return NULL;
	
	return node->_next;
}

Node* getPrevNode(Linked_List* list, Node* node)
{
	if (list == NULL || node == NULL || list->_first == NULL) return NULL;

	return node->_prev;
}

int getNodeData(Node* node)
{
	if (node == NULL) return -1;

	return node->_value;
}

double getAvrage(Linked_List* list)
{
	if (list == NULL) return -1;

	return list->_sum / (double)getListLength(list); //can use list->_count too..
}