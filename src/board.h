#include "pieces/piece.h"

#ifndef BOARD_H
#define BOARD_H

namespace BoardDim
{
	const int WIDTH = 8;
	const int HEIGHT = 8;
}

class Board
{
	Piece* grid[BoardDim::WIDTH][BoardDim::HEIGHT];

public:
	Board();

	void print();

	bool isWithinBounds(Pair<int> p)
	{
		return isWithinBounds(p.fst, p.snd);
	}

	Piece* getPieceAt(int x, int y)
	{
		return grid[y][x];
	}

	bool isWithinBounds(int x, int y)
	{
		return x >= 0 && x < BoardDim::WIDTH && y >= 0 && y < BoardDim::HEIGHT;
	}

	void placePiece(int x, int y, Piece *p)
	{
		grid[y][x] = p;
	}

	void movePiece(Pair<int> init, Pair<int> dest);

private:
	void placePieces();
};

#endif