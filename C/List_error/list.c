#include <stdio.h>
#include "list.h"

struct Node_rec {
	void * value;
	struct Node_rec * next;
	struct Node_rec * prev;
};

struct List_rec {
	Node * first;
	Node * last;
	int length;
	int sum;
};

List initList()
{
	List l;
	l.first = NULL;
	l.last = NULL;
	l.length = 0;
	l.sum = 0;
	return l;
}