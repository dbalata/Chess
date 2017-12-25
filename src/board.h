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

	void movePiece(Pair<int> init, Pair<int> dest);

	bool isValidMove(int x, int y, Color c)
	{
		Color inv = (c == red) ? blue : red;
		return isWithinBounds(x, y) && 
			(getPieceAt(x, y)->getColor() == inv || getPieceAt(x, y)->getColor() == empty);
	}

	Piece* getPieceAt(int x, int y)
	{
		return grid[y][x];
	}

	Piece* getPieceAt(Pair<int> p)
	{
		return getPieceAt(p.fst, p.snd);
	}

	bool isWithinBounds(int x, int y)
	{
		bool b = x >= 0 && x < BoardDim::WIDTH && y >= 0 && y < BoardDim::HEIGHT;
		return b;
	}

	bool isWithinBounds(Pair<int> p)
	{
		return isWithinBounds(p.fst, p.snd);
	}

	void placePiece(int x, int y, Piece *p)
	{
		grid[y][x] = p;
	}

private:
	void placePieces();
};

#endif