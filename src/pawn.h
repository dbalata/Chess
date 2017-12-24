#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include "piece.h"
#include "pair.h" 

class Pawn : public Piece
{
public:
	Pawn(Color c);
	std::vector<Pair<int> > getValidMoves(int x, int y);
};
#endif