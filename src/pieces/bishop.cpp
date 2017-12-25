#include "pieces.h"
#include <vector>

Bishop::Bishop(Color c, Board *b)
{
	setColor(c);
	setChar('b');
	board = b;
}

std::vector<Pair<int> > Bishop::getValidMoves(int x, int y)
{
	std::vector<Pair<int> > moves;

	Color inv = getColor() == red ? blue : red;

	int i, j;

	// Proceed in each diagonal direction until a bound, friend, or enemy is encountered

	for (i = x + 1, j = y + 1; i < BoardDim::WIDTH && j < BoardDim::HEIGHT; i++, j++)
	{
		if (board->getPieceAt(i, j)->getColor() == getColor()) break;
		else if (board->getPieceAt(i, j)->getColor() == inv)
		{
			moves.push_back(Pair<int>(i, j));
			break;
		}
		else moves.push_back(Pair<int>(i, j));
	}

	for (i = x + 1, j = y - 1; i < BoardDim::WIDTH && j >= 0; i++, j--)
	{
		if (board->getPieceAt(i, j)->getColor() == getColor()) break;
		else if (board->getPieceAt(i, j)->getColor() == inv)
		{
			moves.push_back(Pair<int>(i, j));
			break;
		}
		else moves.push_back(Pair<int>(i, j));
	}

	for (i = x - 1, j = y + 1; i >= 0 && j < BoardDim::HEIGHT; i--, j++)
	{
		if (board->getPieceAt(i, j)->getColor() == getColor()) break;
		else if (board->getPieceAt(i, j)->getColor() == inv)
		{
			moves.push_back(Pair<int>(i, j));
			break;
		}
		else moves.push_back(Pair<int>(i, j));
	}

	for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board->getPieceAt(i, j)->getColor() == getColor()) break;
		else if (board->getPieceAt(i, j)->getColor() == inv)
		{
			moves.push_back(Pair<int>(i, j));
			break;
		}
		else moves.push_back(Pair<int>(i, j));
	}

	return moves;
}