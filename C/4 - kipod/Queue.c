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

Queue* push_back(Queue* queue, Panel* value)
{
	if (queue == NULL || queue->_list == NULL) return NULL;

	if (addValueToList(queue->_list, value) == NULL) return NULL;

	return queue;
}

Panel* pop(Queue* queue)
{
	Panel* ret = NULL;

	if (queue == NULL || queue->_list == NULL) return NULL;

	//getting the data of the first var
	ret = top(queue);

	//deleting the first var
	if (removeFromList(queue->_list, getFirstNode(queue->_list)) == NULL) return NULL;

	return ret;	
}

int getQueueLength(Queue* queue)
{
	if (queue == NULL || queue->_list == NULL) return -1;

	return getListLength(queue->_list);
}

Panel* top(Queue* queue)
{
	if (queue == NULL || queue->_list == NULL) return NULL;

	//check if there is enough values in the list
	if (getListLength(queue->_list) <= 0) return NULL;

	return getNodeData(getFirstNode(queue->_list));
}