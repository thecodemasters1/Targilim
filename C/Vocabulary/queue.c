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
int add_to_queue(Queue * q, void * value)
{
	Node * added = NULL;
	added = (Node *)malloc(sizeof(Node));
	if (added == NULL)
	{
		printf("Queue Node, not enough memory.");
		return 0;
	}

	added->value = value;
	added->next = NULL;
	if (q->first == NULL)
	{
		//Add node as first
		q->first = added;
		q->last = added;
	}
	else
	{
		//Add node as last
		q->last->next = added;
		q->last = added;
	}
	q->length++;

	return 1;
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

int is_in_queue(Queue q, const char * str)
{
	Node * current = q.first;
	while (current != NULL)
	{
		char * value = (char *)current->value;
		if (strcmp(value, str) == 0)
		{
			return 1;
		}
		current = current->next;
	}
	return 0;
}

Queue * duplicateQueue(Queue q)
{
	Queue * dupe = NULL;

	dupe = malloc(sizeof(Queue));

	if (dupe == NULL)
	{
		printf("No Memory, duplicate!!!");
		return NULL;
	}

	dupe->first = NULL;
	dupe->last = NULL;
	dupe->length = 0;

	Node * current = q.first;
	while (current != NULL)
	{
		char * tmp = NULL;
		tmp = malloc(sizeof(char) * MAX_WORD_LEN);

		if (tmp == NULL)
		{
			printf("No Memory, duplicate!!!");
			return NULL;
		}

		strcpy(tmp, (char *)current->value);

		add_to_queue(dupe, (void *)tmp);
		current = current->next;
	}
	return dupe;
}

/* DEBUG FUNCTION */
void print_queue(Queue l)
{
	Node * current = l.first;
	while (current != NULL)
	{
		printf("%s\n", (*current).value);
		current = (*current).next;
	}
}