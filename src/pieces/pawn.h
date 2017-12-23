#include <vector>
#include "piece.h"
#include "../pair.h"

class Pawn : public Piece
{
public:
	Pawn(Color c);
	char getChar();
	std::vector<Pair<int> > getValidMoves(int x, int y);
};