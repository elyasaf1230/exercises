#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Linked_List.h"

void printAllNode(Linked_List* list);

int main()
{
	//temps:
	Node* tempNode = NULL;

	//create list:
	Linked_List mylist;
	initList(&mylist);

	//adding new nodes:
	//by values
	addValueToList(&mylist, 10);
	addValueToList(&mylist, 23);
	addValueToList(&mylist, 41);
	addValueToList(&mylist, 1);

	//by nodes:
	tempNode = (Node*)malloc(sizeof(Node));
	tempNode->_value = 94;
	addNodeToList(&mylist, tempNode);
	
	tempNode = (Node*)malloc(sizeof(Node));
	tempNode->_value = 64;
	addNodeToList(&mylist, tempNode);
	
	printAllNode(&mylist);

	//removing node:
	removeFromList(&mylist, getFirstNode(&mylist)->_next->_next);

	printAllNode(&mylist);

	//clearing list:
	killList(&mylist);

	getchar();
	return 0;
}

void printAllNode(Linked_List* mylist)
{
	Node* tempNode = NULL;

	//reading all nodes in list:
	tempNode = getFirstNode(mylist);
	while (tempNode != getLastNode(mylist)){
		printf("node value: %d\n", getNodeData(tempNode));
		tempNode = getNextNode(mylist, tempNode);
	}
	printf("and last node value: %d\n", getNodeData(tempNode));

	printf("total nodes: %d\tavrage: %lf\n", getListLength(mylist), getAvrage(mylist));
}