#ifndef PIECE_H
#define PIECE_H

#include "../color.h"
#include <vector>
#include "../pair.h"

class Piece
{
public:
	Color getColor()
	{
		return color;
	}

	void setColor(Color c)
	{
		color = c;
	}

	char getChar()
	{
		return character;
	}

	virtual void move() 
	{
		firstMove = false;
	}

	virtual std::vector<Pair<int> > getValidMoves(int x, int y) = 0;

protected:
	void setChar(char c)
	{
		character = c;
	}	

	bool isFirstMove()
	{
		return firstMove;
	}

private:
	Color color;
	char character;
	bool firstMove;
};

#endif