#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include "piece.h"
#include "../pair.h"
#include "../board.h"

class EmptyTile : public Piece
{
public:
	EmptyTile()
	{
		setColor(empty);
		setChar('x');
	}
	std::vector<Pair<int> > getValidMoves(int x, int y) { return std::vector<Pair<int> >(); };
};

class Pawn : public Piece
{
	Board *board;
public:
	Pawn(Color c, Board *b);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

class Rook : public Piece
{
	Board *board;
public:
	Rook(Color c, Board *b);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

class Knight : public Piece
{
	Board *board;
public:
	Knight(Color c, Board *b);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

class Bishop : public Piece
{
	Board *board;
public:
	Bishop(Color c, Board *b);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

class King : public Piece
{
	Board *board;
public:
	King(Color c, Board *b);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

class Queen : public Piece
{
	Board *board;
public:
	Queen(Color c, Board *b);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

#endif