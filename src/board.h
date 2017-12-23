#include "piece.h"

#ifndef BOARD_H
#define BOARD_H

const int WIDTH = 8;
const int HEIGHT = 8;

class Board
{

	Piece* grid[WIDTH][HEIGHT];

public:
	Board();

	void print();

	bool isWithinBounds(int x, int y)
	{
		return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
	}

	Piece* getPieceAt(int x, int y)
	{
		return grid[y][x];
	}
};

#endif