#include "pieces.h"
#include <vector>

Queen::Queen(Color c, Board *b)
{
	setColor(c);
	setChar('q');
	board = b;
}

std::vector<Pair<int> > Queen::getValidMoves(int x, int y)
{
	std::vector<Pair<int> > moves;

	// Queen moves are a combination of rook and bishop

	Rook r(getColor(), board);
	Bishop b(getColor(), board);

	std::vector<Pair<int> > rMoves = r.getValidMoves(x, y);
	std::vector<Pair<int> > bMoves = b.getValidMoves(x, y);

	moves.reserve(rMoves.size() + bMoves.size());
	moves.insert(moves.end(), rMoves.begin(), rMoves.end());
	moves.insert(moves.end(), bMoves.begin(), bMoves.end());

	return moves;
}