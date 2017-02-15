#pragma once
#include <stdio.h>
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