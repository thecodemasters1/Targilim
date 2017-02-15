#include <stdio.h>

/* STRUCTS */
struct Node_rec {
	void * value;
	struct Node_rec * next;
	struct Node_rec * prev;
};

typedef struct Node_rec Node;

struct List_rec {
	Node * first;
	Node * last;
	int length;
	int sum;
};

typedef struct List_rec List;

/* DECLARTIONS */
List initList();
void deleteList(List * l);
Node * add_to_list(List * l, void * value);
void print_list(List l);
void delete_node(List * l, Node * n);
int get_list_length(List l);
Node * get_first_node(List l);
Node * get_last_node(List l);
Node * get_next_node(Node * n);
Node * get_prev_node(Node * n);
void * get_node_value(Node * n);
float get_avg(List l);

int main()
{
	List testList = initList();

	Node * tmp;
	//Add & Delete
	Node * toDelete;
	toDelete = add_to_list(&testList, 54);
	add_to_list(&testList, 32);
	tmp = add_to_list(&testList, 107);
	add_to_list(&testList, 95);

	printf("Before:\n");
	print_list(testList);

	delete_node(&testList, toDelete);

	printf("\n\nAfter:\n");
	print_list(testList);

	//Length, First, Last Test
	printf("\n\nList Length:%d\n", get_list_length(testList));
	printf("First Value:%d\n", get_first_node(testList)->value);
	printf("Last Value:%d\n", get_last_node(testList)->value);

	//Next, Prev Test
	printf("\nNext Value:%d\n", get_next_node(tmp)->value);
	printf("Value:%d\n", get_node_value(tmp));
	printf("Prev Value:%d\n", get_prev_node(tmp)->value);

	//Avg Test
	printf("\nAvg Value:%f\n", get_avg(testList));

	//Delete Test
	deleteList(&testList);
	printf("\nAfter Delete:\n");
	print_list(testList);
	return 0;
}


//Func #1
List initList()
{
	List l;
	l.first = NULL;
	l.last = NULL;
	l.length = 0;
	l.sum = 0;
	return l;
}

//Func #2
void deleteList(List * l)
{
	Node * current = l->first;
	Node * needToDelete;
	while (current != NULL)
	{
		needToDelete = current;
		current = (*current).next;
		needToDelete->next = NULL;
		needToDelete->prev = NULL;
	}
	l->first = NULL;
	l->last = NULL;
	l->length = 0;
	l->sum = 0;
}

//Func #3
Node * add_to_list(List * l, void * value)
{
	Node added;
	added.value = value;
	added.next = NULL;
	if (l->first == NULL)
	{
		//Add node as first
		added.prev = NULL;
		l->first = &added;
		l->last = &added;
	}
	else
	{
		//Add node as last
		added.prev = l->last;
		l->last->next = &added;
		l->last = &added;
	}
	l->length++;
	l->sum += *((int *)&value);
	return &added;
}

//Func #4
void delete_node(List * l, Node * n)
{
	void * value = n->value;
	if (n->prev == NULL) //First node
	{
		l->first = n->next; //Set next node to first
		n->next = NULL; //Point node to null
	}
	else if (n->next == NULL) //Last node
	{
		l->last = n->prev; //Set prev node to last
		n->prev->next = NULL; //Set previous node point to null
	}
	else //Middle node
	{
		n->prev->next = n->next; //Prev node will point to the next node
		n->prev = NULL;
		n->next = NULL;
	}
	l->length--;
	l->sum -= *((int *)&value);
}

//Func #5
int get_list_length(List l)
{
	return l.length;
}

//Func #6
Node * get_first_node(List l)
{
	return l.first;
}

//Func #7
Node * get_last_node(List l)
{
	return l.last;
}

//Func #8
/* Could return null */
Node * get_next_node(Node * n)
{
	return n->next;
}

//Func #9
/* Could return null */
Node * get_prev_node(Node * n)
{
	return n->prev;
}

//Func #10
void * get_node_value(Node * n)
{
	return n->value;
}

//Func #11
float get_avg(List l)
{
	return (float)l.sum / l.length;
}

/* DEBUG FUNCTION */
void print_list(List l)
{
	Node * current = l.first;
	while (current != NULL)
	{
		printf("%d\n", (*current).value);
		current = (*current).next;
	}
}