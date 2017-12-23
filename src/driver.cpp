#include <iostream>
#include <stdio.h>
#include "pieces.h"
#include "piece.h"
#include "board.h"
#include "pair.h"

Pair<int> getInput(std::string s)
{
	int x, y;
	x = s.at(0) - '0';
	y = s.at(2) - '0';
	return Pair<int>(x, y);
}

int main()
{
	Board *b = new Board();

	while(true)
	{
		b->print();
		std::cout << "Select a piece." << std::endl;
		std::string input;
		std::getline(std::cin, input);
		Pair<int> p = getInput(input);
		int x = p.fst;
		int y = p.snd;
		Piece *pce = b->getPieceAt(x, y);
		std::cout << "Selected type: " << pce->getChar() << std::endl;
	}
	
	std::cout << "Press enter to exit.";
	getchar();
	return 0;
}
