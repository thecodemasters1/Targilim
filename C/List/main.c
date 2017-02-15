#include <stdio.h>
#include "list.h"

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
