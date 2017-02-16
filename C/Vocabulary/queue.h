#pragma once
#include <stdio.h>
#define MAX_WORD_LEN 128
struct Node_rec {
	void * value;
	struct Node_rec * next;
};

typedef struct Node_rec Node;
struct Queue_rec {
	Node * first;
	Node * last;
	int length;
};
typedef struct Queue_rec Queue;
Queue initQueue();
void deleteQueue(Queue * q);
//void add_to_queue(Queue * q, void * value);
int add_to_queue(Queue * q, void * value);
void print_queue(Queue l);
void * pop(Queue * q);
int get_queue_length(Queue q);
void * get_first_value(Queue q);
int is_in_queue(Queue q, const char * str);
Queue * duplicateQueue(Queue q);
