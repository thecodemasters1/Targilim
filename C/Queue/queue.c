#include "queue.h"

//Func #1
Queue initQueue()
{
	Queue q;
	q.first = NULL;
	q.last = NULL;
	q.length = 0;
	return q;
}

//Func #2
void deleteQueue(Queue * q)
{
	unsigned i;
	int length = get_queue_length(*q);
	for (i = 0; i < length; i++)
	{
		pop(q);
	}
}

//Func #3
void add_to_queue(Queue * q, void * value)
{
	Node added;
	added.value = value;
	added.next = NULL;

	if(q->first == NULL)
	{
		//Add node as first
		q->first = &added;
		q->last = &added;
	}
	else
	{
		//Add node as last
		q->last->next = &added;
		q->last = &added;
	}
	q->length++;
}

//Func #4
void * pop(Queue * q)
{
	Node * popped = q->first;
	if(popped == NULL) //Empty Queue
	{
		return NULL;
	}
	
	q->first = popped->next;
	popped->next = NULL;
	q->length--;
	return popped->value;
}

//Func #5
int get_queue_length(Queue q)
{
	return q.length;
}

//Func #6
void * get_first_value(Queue q)
{
	return q.first->value;
}

/* DEBUG FUNCTION */
void print_queue(Queue l)
{
	Node * current = l.first;
	while (current != NULL)
	{
		printf("%d\n", (*current).value);
		current = (*current).next;
	}
}