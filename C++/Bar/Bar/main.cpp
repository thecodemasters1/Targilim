#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Drink.h"
#include "Beer.h"
#include "Redwine.h"
#include "Whitewine.h"

#define SHELF_SIZE 11
int main()
{
	Drink *stock[SHELF_SIZE];
	stock[0] = new Beer("Heineken");
	stock[1] = new Beer("Goldstar");
	stock[2] = new Beer("Maccabi");
	stock[3] = new Beer("Tuborg");
	stock[4] = new Whitewine("Karmel Emerald Rizling", 1986);
	stock[5] = new Whitewine("Golan Smadar", 1989);
	stock[6] = new Whitewine("Yarden Shoshana", 1997);
	stock[7] = new Redwine("Kianti", 1997);
	stock[8] = new Redwine("Yarden Ar Ahermon", 1994);
	stock[9] = new Redwine("Yarden Kaberna Sovanyon", 1997);
	stock[10] = new Redwine("Chadeau Margot", 1997);

	Drink * lastDrink = NULL;
	while (true)
	{
		printf("What can I get you, sir? (0 - list options)\n");
		char * input = new char[3];
		int inputIndex = 0;
		char c;
		while((c = getchar()) != '\n' && inputIndex < 2)
		{
			if (!isdigit(c))
				break;
			input[inputIndex] = c;
			inputIndex++;
		}
		input[inputIndex] = '\0';
		printf("\n");
		int inputNum = atoi(input);
		if(inputNum == 0)
		{
			printf("(0)\tlist options\n");
			for (int i = 0; i < SHELF_SIZE; ++i)
			{
				printf("(%d)\t%s\n", (i+1), stock[i]->getName());
			}
			printf("(99)\tHow did you prepare my last drink?\n");
			printf("(100)\tLeave the bar\n");
		}
		else if (inputNum == 99)
		{
			if (lastDrink == NULL)
			{
				printf("I didn't serve you anything.\n");
			}
			else
			{
				printf("You ordered %s\n", lastDrink->getName());
				printf("%s\n", lastDrink->prepare());
			}
		}
		else if (inputNum == 100)
		{
			printf("Bar is closed. Good night.\n");
			break;
		}
		else if(inputNum < SHELF_SIZE+1 && inputNum > 1)
		{
			lastDrink = stock[inputNum - 1];
			printf("One %s coming up, sir.\n", lastDrink->getName());
		}
		printf("\n");
	}

	delete[] stock;
	delete[] lastDrink;

	return 0;
}
