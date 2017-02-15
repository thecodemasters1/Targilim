#include <stdio.h>
#include "queue.h"

int main()
{
	Queue testQueue = initQueue();
	add_to_queue(&testQueue, 12);
	add_to_queue(&testQueue, 82);
	add_to_queue(&testQueue, 157);

	printf("Before:\n");
	print_queue(testQueue);

	printf("\nPopping:\n");
	printf("%d\n", pop(&testQueue));
	printf("%d\n", pop(&testQueue));
	printf("%d\n", pop(&testQueue));
	printf("\nAfter Popping:\n");
	print_queue(testQueue);

	add_to_queue(&testQueue, 36);
	add_to_queue(&testQueue, 58);
	add_to_queue(&testQueue, 95);
	add_to_queue(&testQueue, 43);
	printf("\nQueue Length:%d\n", get_queue_length(testQueue));

	printf("\nFirst Value:%d\n", get_first_value(testQueue));
	return 0;
}