#pragma once
#include <stdio.h>
#define GRID_WIDTH 75
#define GRID_HEIGHT 20

#define CHAR_CELL (char)219
#define CHAR_DEAD ' '

#define IN_BOUNDS(x, y) (x > 0 && x < GRID_WIDTH && y > 0 && y < GRID_HEIGHT)

struct Grid {
	int cells[GRID_WIDTH][GRID_HEIGHT];
};

typedef struct Grid Grid;
void resetGrid(Grid * g);
void drawGrid(Grid g);
void addCell(int x, int y, Grid * g);
void killCell(int x, int y, Grid * g);
int get_amount_of_neighbors(int argX, int argY, Grid g);
int doTurn(Grid * g);
void doCellAlive(int x, int y, Grid * g, Grid dupe);
void doCellDead(int x, int y, Grid * g, Grid dupe);