#include "Queue.h"

Queue* initQueue(Queue* queue)
{
	if (queue == NULL) return NULL;

	queue->_list = (Linked_List*)malloc(sizeof(Linked_List));

	if (queue->_list == NULL) return NULL;

	if (initList(queue->_list) == NULL) return NULL;

	return queue;
}

Queue* killQueue(Queue* queue)
{
	if (queue == NULL || queue->_list == NULL) return NULL;

	if (killList(queue->_list) == NULL) return NULL; //deleting nodes

	free(queue->_list);     //deleting list

	return queue;
}

Queue* push_back(Queue* queue, int value)
{
	if (queue == NULL || queue->_list == NULL) return NULL;

	if (addValueToList(queue->_list, value) == NULL) return NULL;

	return queue;
}

int pop(Queue* queue)
{
	int ret = -1;

	if (queue == NULL || queue->_list == NULL) return -1;

	//getting the data of the first var
	ret = top(queue);

	//deleting the first var
	if (removeFromList(queue->_list, getFirstNode(queue->_list)) == NULL) return -1;

	return ret;	
}

int getQueueLength(Queue* queue)
{
	if (queue == NULL || queue->_list == NULL) return -1;

	return getListLength(queue->_list);
}

int top(Queue* queue)
{
	if (queue == NULL || queue->_list == NULL) return -1;

	//check if there is enough values in the list
	if (getListLength(queue->_list) <= 0) return -1;

	return getNodeData(getFirstNode(queue->_list));
}