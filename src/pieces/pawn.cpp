#include "../color.h"
#include <vector>
#include "../pair.h"
#include "piece.h"
#include "pieces.h"
#include "../board.h"

using std::vector;

Pawn::Pawn(Color c, Board *b)
{
	setColor(c);
	setChar('p');
}

vector<Pair<int> > Pawn::getValidMoves(int x, int y)
{
	int yInc = (getColor() == blue) ? 1 : -1;
	int newY = y + yInc;
	vector<Pair<int> > ls;
	ls.push_back(Pair<int>(x, newY));
	if (isFirstMove()) ls.push_back(Pair<int>(x, y + (2 * yInc)));
	return ls;
}