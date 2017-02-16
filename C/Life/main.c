#include <stdio.h>
#include "grid.h"

void clear_screen();

#define FAILED_TURN -1;

int main()
{
	Grid grid;
	resetGrid(&grid);

	int centerW = GRID_WIDTH / 2;
	int centerH = GRID_HEIGHT / 2;

	//Glider	
	/*
	addCell(centerW, centerH+1, &grid);
	addCell(centerW, centerH-1, &grid);
	addCell(centerW+1, centerH, &grid);
	addCell(centerW+1, centerH+1, &grid);
	addCell(centerW-1, centerH+1, &grid);
	*/

	//Tumbler
	addCell(centerW+1, centerH-1, &grid);
	addCell(centerW+2, centerH-1, &grid);
	addCell(centerW-1, centerH-1, &grid);
	addCell(centerW-2, centerH-1, &grid);

	addCell(centerW+1, centerH+1, &grid);
	addCell(centerW+1, centerH+2, &grid);
	addCell(centerW+2, centerH+3, &grid);
	addCell(centerW+3, centerH+3, &grid);
	addCell(centerW+4, centerH+3, &grid);
	addCell(centerW+4, centerH+2, &grid);
	addCell(centerW+3, centerH+2, &grid);

	addCell(centerW-1, centerH+1, &grid);
	addCell(centerW-1, centerH+2, &grid);
	addCell(centerW-2, centerH+3, &grid);
	addCell(centerW-3, centerH+3, &grid);
	addCell(centerW-4, centerH+3, &grid);
	addCell(centerW-4, centerH+2, &grid);
	addCell(centerW-3, centerH+2, &grid);

	while(1 == 1)
	{
		clear_screen();
		drawGrid(grid);

		printf("Press any key to next turn, enter 'x' to exit\n");
		if (getchar() == 'x')
		{
			break;
		}
		if (doTurn(&grid) == 0)
			return FAILED_TURN;
	}

	
	return 0;
}

void clear_screen()
{
	for (unsigned i = 0; i < 50; i++)
	{
		printf("\n");
	}
}