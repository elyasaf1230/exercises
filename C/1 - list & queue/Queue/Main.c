#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Queue.h"

int main()
{
	int i = 0;
	Queue* myqueue = (Queue*)malloc(sizeof(Queue));

	if (myqueue == NULL) exit(0);

	//init queue
	if (initQueue(myqueue) == NULL) exit(0);

	//inserts vars
	push_back(myqueue, 3);
	push_back(myqueue, 8);
	push_back(myqueue, 47);
	push_back(myqueue, 32);
	push_back(myqueue, 1);
	push_back(myqueue, 986);
	push_back(myqueue, 63);

	printf("queue len: %d\n", getQueueLength(myqueue));

	printf("first var: %d\n", top(myqueue));

	//printing all vars:
	for (i = getQueueLength(myqueue); i > 0; --i)
	{
		printf("current var: %d\n", pop(myqueue));
	}

	killQueue(myqueue);

	free(myqueue);

	getchar();

	return 0;
}