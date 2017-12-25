#include "pieces.h"
#include <algorithm>

Knight::Knight(Color c, Board* b)
{
	setColor(c);
	setChar('k');
	board = b;
}

std::vector<Pair<int> > Knight::getValidMoves(int x, int y)
{
	std::vector<Pair<int> > moves;

	moves.push_back(Pair<int>(x + 2, y - 1));
	moves.push_back(Pair<int>(x + 2, y + 1));

	moves.push_back(Pair<int>(x + 1, y - 2));
	moves.push_back(Pair<int>(x - 1, y - 2));

	moves.push_back(Pair<int>(x - 2, y + 1));
	moves.push_back(Pair<int>(x - 2, y - 1));

	moves.push_back(Pair<int>(x + 1, y + 2));
	moves.push_back(Pair<int>(x - 1, y + 2));

	auto it = remove_if(moves.begin(), moves.end(), [&](Pair<int> move) {bool b = false; b = board->isWithinBounds(move); return !b; });
	moves.erase(it, moves.end());

	it = remove_if(moves.begin(), moves.end(), [&](Pair<int> move) {Color c1 = board->getPieceAt(move)->getColor(); Color c2 = getColor(); return c1 == c2; });
	moves.erase(it, moves.end());

	return moves;
}