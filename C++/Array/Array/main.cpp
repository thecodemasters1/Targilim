#include <stdio.h>
#include "Array.h"

int main()
{
	Array<int> arr = Array<int>(5);
	arr[0] = 5;
	arr[3] = 2;
	arr.print();
	try
	{
		arr[-1] = 10;
	}
	catch (int e)
	{
		switch (e)
		{
			case OUT_OF_BOUNDS: 
				printf("OUT OF BOUNDS\n");
				break;
		}
	}

	try
	{
		arr[20] = 10;
	}
	catch (int e)
	{
		switch (e)
		{
		case OUT_OF_BOUNDS:
			printf("OUT OF BOUNDS\n");
			break;
		}
	}

	printf("%d\n", *(&arr[2] + 1)); //Ertmetica
	
	return 0;
}