#include "../color.h"
#include <vector>
#include "../pair.h"
#include "piece.h"
#include "pawn.h"

using std::vector;

Pawn::Pawn(Color c)
{
	setColor(c);
	setChar('p');
}

vector<Pair<int> > Pawn::getValidMoves(int x, int y)
{
	int yInc = (Pawn::getColor() == white) ? -1 : 1;
	int newY = y + yInc;
	vector<Pair<int> > ls;

	ls.push_back(Pair<int>(x, newY));
}