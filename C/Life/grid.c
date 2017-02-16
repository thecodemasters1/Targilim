#include "grid.h"
void resetGrid(Grid * g)
{
	for (unsigned y = 0; y < GRID_HEIGHT; y++)
	{
		for (unsigned x = 0; x < GRID_WIDTH; x++)
		{
			g->cells[x][y] = 0;
		}
	}
}

void drawGrid(Grid g)
{
	for (unsigned y = 0; y < GRID_HEIGHT; y++)
	{
		printf("<");
		for (unsigned x = 0; x < GRID_WIDTH; x++)
		{
			printf("%c", g.cells[x][y] == 1 ? CHAR_CELL : CHAR_DEAD);
		}
		printf(">\n");
	}
}

void addCell(int x, int y, Grid * g)
{
	g->cells[x][y] = 1;
}

void killCell(int x, int y, Grid * g)
{
	g->cells[x][y] = 0;
}

int get_amount_of_neighbors(int argX, int argY, Grid g)
{
	int amount = 0;

	int y;
	int x;
	for (x = argX - 1, y = argY - 1; x <= argX+1 && IN_BOUNDS(x, y); x++)//Check up row
	{
		if(g.cells[x][y] == 1)
		{
			amount++;
		}
	}

	for (x = argX - 1, y = argY; x <= argX + 1 && IN_BOUNDS(x, y); x++)//Check mid row
	{
		if (g.cells[x][y] == 1 && x != argX)
		{
			amount++;
		}
	}

	for (x = argX - 1, y = argY + 1; x <= argX + 1 && IN_BOUNDS(x, y); x++)//Check bottom row
	{
		if (g.cells[x][y] == 1)
		{
			amount++;
		}
	}
	return amount;
}

int doTurn(Grid * g)
{
	//duplicate grid
	Grid * dupe = NULL;
	dupe = (Grid *)malloc(sizeof(Grid));

	if(dupe == NULL)
	{
		printf("Not Enough Memory, doTurn()\n");
		return 0;
	}

	for (unsigned y = 0; y < GRID_HEIGHT; y++)
	{
		for (unsigned x = 0; x < GRID_WIDTH; x++)
		{
			dupe->cells[x][y] = g->cells[x][y];
		}
	}

	//Run turn
	for (unsigned y = 0; y < GRID_HEIGHT; y++)
	{
		for (unsigned x = 0; x < GRID_WIDTH; x++)
		{
			if (g->cells[x][y] == 1)
			{
				doCellAlive(x, y, g, *dupe);
			}
			else
			{
				doCellDead(x, y, g, *dupe);
			}
		}
	}
	return 1;
}

void doCellAlive(int x, int y, Grid * g, Grid dupe)
{
	int nNeigh = get_amount_of_neighbors(x, y, dupe);
	if (nNeigh != 3 && nNeigh != 2)
	{
		killCell(x, y, g);
	}
}

void doCellDead(int x, int y, Grid * g, Grid dupe)
{
	int nNeigh = get_amount_of_neighbors(x, y, dupe);
	if (nNeigh == 3)
	{
		//Make Cell
		addCell(x, y, g);
	}
	
}