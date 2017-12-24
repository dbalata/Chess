#include <iostream>
#include <stdio.h>
#include "pieces.h"
#include "piece.h"
#include "board.h"
#include "pair.h"
#include <string>
#include <vector>

Pair<int> getInput(std::string s)
{
	int x, y;
	x = s.at(0) - '0';
	y = s.at(2) - '0';
	return Pair<int>(x, y);
}


std::string movesToString(std::vector<Pair<int> > vec)
{
	char cs[100];
	int idx = 0;
	for(Pair<int> p : vec)
	{
		
	}
	return std::string(cs);
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
		std::vector<Pair<int> > moves = pce->getValidMoves(x, y);
		//std::cout << "Availiable moves: " << movesToString(moves);
	}
	
	std::cout << "Press enter to exit.";
	getchar();
	return 0;
}
