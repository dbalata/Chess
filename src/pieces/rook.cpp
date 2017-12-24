#include <vector>
#include "../pair.h"
#include "piece.h"
#include "pieces.h"
#include "../board.h"

using std::vector;

Rook::Rook(Color c, Board *b)
{
	setColor(c);
	setChar('r');
	board = b;
}

vector<Pair<int> > Rook::getValidMoves(int x, int y)
{
	vector<Pair<int> > ls; 
	Color c = getColor();
	Color inv = (c == red) ? blue : red;

	for(int i = x + 1; i < BoardDim::WIDTH; i++)
	{
		if (board->getPieceAt(i, y)->getChar() == 'x') ls.push_back(Pair<int>(i, y));
		else if (board->getPieceAt(i, y)->getColor() == inv)
		{
			ls.push_back(Pair<int>(i, y));
			break;
		}
		else break;
	}

	for (int i = x - 1; i >= 0; i--)
	{
		if (board->getPieceAt(i, y)->getChar() == 'x') ls.push_back(Pair<int>(i, y));
		else if (board->getPieceAt(i, y)->getColor() == inv)
		{
			ls.push_back(Pair<int>(i, y));
			break;
		}
		else break;
	}

	for(int j = y + 1; j < BoardDim::HEIGHT; j++)
	{
		if (board->getPieceAt(x, j)->getChar() == 'x') ls.push_back(Pair<int>(x, j));
		else if (board->getPieceAt(x, j)->getColor() == inv)
		{
			ls.push_back(Pair<int>(x, j));
			break;
		}
		else break;
	}

	for (int j = y - 1; j >= 0; j--)
	{
		if (board->getPieceAt(x, j)->getChar() == 'x') ls.push_back(Pair<int>(x, j));
		else if (board->getPieceAt(x, j)->getColor() == inv)
		{
			ls.push_back(Pair<int>(x, j));
			break;
		}
		else break;
	}
	return ls;
}