#include "pieces.h"
#include <algorithm>

King::King(Color c, Board* b)
{
	setColor(c);
	setChar('K');
	board = b;
}

std::vector<Pair<int> > King::getValidMoves(int x, int y)
{
	std::vector<Pair<int> > moves;

	moves.push_back(Pair<int>(x + 1, y + 0));
	moves.push_back(Pair<int>(x + 1, y + 1));

	moves.push_back(Pair<int>(x + 0, y + 1));
	moves.push_back(Pair<int>(x - 1, y + 1));

	moves.push_back(Pair<int>(x - 1, y + 0));
	moves.push_back(Pair<int>(x - 1, y - 1));

	moves.push_back(Pair<int>(x + 0, y - 1));
	moves.push_back(Pair<int>(x + 1, y - 1));

	auto it = remove_if(moves.begin(), moves.end(), [&](Pair<int> move) {bool b = board->isWithinBounds(move); return !b; });
	moves.erase(it, moves.end());

	it = remove_if(moves.begin(), moves.end(), [&](Pair<int> move) {Color c1 = board->getPieceAt(move)->getColor(); Color c2 = getColor(); return c1 == c2; });
	moves.erase(it, moves.end());

	return moves;
}