#include <vector>
#include "pair.h"
#include "piece.h"
#include "pieces.h"
#include "board.h"

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

	for(int i = 0; i < BoardDim::WIDTH; i++)
	{
		if(board->getPieceAt(i, y)->getChar() == 'x') ls.push_back(Pair<int>(i, y));
	}

	for(int j = 0; j < BoardDim::WIDTH; j++)
	{
		ls.push_back(Pair<int>(x, j));
	}
	return ls;
}