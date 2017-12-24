#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include "piece.h"
#include "pair.h"
#include "board.h"

class EmptyTile : public Piece
{
public:
	EmptyTile()
	{
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
public:
	Knight(Color c);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

class Bishop : public Piece
{
public:
	Bishop(Color c);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

class King : public Piece
{
public:
	King(Color c);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

class Queen : public Piece
{
public:
	Queen(Color c);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};

#endif