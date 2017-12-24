#include "../color.h"
#include <vector>
#include "../pair.h"
#include "piece.h"
#include "pieces.h"
#include "../board.h"
#include <algorithm>

using std::vector;

Pawn::Pawn(Color c, Board *b)
{
	setColor(c);
	setChar('p');
	board = b;
}

vector<Pair<int> > Pawn::getValidMoves(int x, int y)
{
	int yInc = (getColor() == blue) ? 1 : -1;
	int newY = y + yInc;
	vector<Pair<int> > ls;
	ls.push_back(Pair<int>(x, newY));

	Color inv = (getColor() == red) ? blue : red;

	// Pawns can move diagonally if they are capturing a piece while doing so.
	if (board->isWithinBounds(x - 1, newY) && board->getPieceAt(x - 1, newY)->getColor() == inv) ls.push_back(Pair<int>(x, y - 1));
	if (board->isWithinBounds(x + 1, newY) && board->getPieceAt(x + 1, newY)->getColor() == inv) ls.push_back(Pair<int>(x, y + 1));

	// Pawns can move 2 spaces forward on their first turn.
	if (isFirstMove()) ls.push_back(Pair<int>(x, y + (2 * yInc)));

	std::remove_if(ls.begin(), ls.end(), [&](Pair<int> p) { bool b = board->isWithinBounds(p); return !b; });
	return ls;
}