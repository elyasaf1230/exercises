/*
	The queue is emplemented on top of LinkedList.
*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Linked_List.h"

typedef struct Queue Queue;

struct Queue
{
	Linked_List* _list;
};


/*
	initQueue:
		This function initialize the given queue.

	INPUT:
		pointer to the queue.

	OUTPUT:
		if success - return 'queue'.
		else - return NULL ('queue' == NULL, ect...)
*/
Queue* initQueue(Queue* queue);

/*
	killQueue:
		The function kill (or destroy) the given queue.

	INPUT:
		pointer to the queue.

	OUTPUT:
		if success - return 'queue'.
		else - return NULL ('queue' == NULL, ect...)
*/
Queue* killQueue(Queue* queue);

/*
	push_back:
		This function add 'value' to the end of 'queue'.

	INPUT:
		queue - pointer to Queue.
		Panel*   - value to add to queue.

	OUTPUT:
		if success - return 'queue'.
		else - NULL. ('queue' == NULL ect...)
*/
Queue* push_back(Queue* queue, Panel* value);

/*
	pop:
		This function pop out the first value in the given queue and return it.

	INPUT:
		queue - pointer to queue.

	OUTPUT:
		Panel* - the popped out value. 
		(NULL if error, 'queue' is NULL, no one call to initqueue(), no values in queue ect...) 
*/
Panel* pop(Queue* queue);

/*
	getQueueLength:
		This function return the length of 'queue'.

	INPUT:
		queue - pointer to Queue.

	OUTPUT:
		int - the length of the queue. (-1 if error, 'queue' == NULL ect...)
*/
int getQueueLength(Queue* queue);

/*
	top:
		This function return the first value in the given queue (without pop it out).

	INPUT:
		queue - pointer to queue.

	OUTPUT:
		Panel* - the first value in 'queue' (NULL if error, 'queue' == NULL, 'queue' is empty ect...)
*/
Panel* top(Queue* queue);

#endif