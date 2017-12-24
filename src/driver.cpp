#include <iostream>
#include <stdio.h>
#include "pieces/pieces.h"
#include "pieces/piece.h"
#include "board.h"
#include "pair.h"
#include <string>
#include <vector>
#include <sstream>

Pair<int> getInput(std::string s)
{
	int x, y;
	x = s.at(0) - '0';
	y = s.at(2) - '0';
	return Pair<int>(x, y);
}

std::string movesToString(std::vector<Pair<int> > vec)
{
	std::stringstream ss;
	int idx = 0;
	for(Pair<int> p : vec)
	{
		ss << idx++ << ": (" << p.fst << ", " << p.snd << ")" << std::endl;
	}
	return ss.str();
}

int main(void)
{
	Board *b = new Board();

	while(true)
	{
		b->print();
		std::cout << "Select a piece." << std::endl;
		std::string input;
		std::getline(std::cin, input);

		if (input.size() != 3) continue;

		Pair<int> pieceLoc = getInput(input);
		int x = pieceLoc.fst;
		int y = pieceLoc.snd;
		Piece *pce = b->getPieceAt(x, y);

		if (pce->getChar() == 'x') continue;

		std::cout << "Selected type: " << pce->getChar() << std::endl;
		std::vector<Pair<int> > moves = pce->getValidMoves(x, y);
		std::cout << "Availiable moves: " << std::endl << movesToString(moves) << std::endl;

		int selection;
		std::cin >> selection;
		Pair<int> pieceMoveLoc = moves[selection];
		b->movePiece(pieceLoc, pieceMoveLoc);
	}
	
	std::cout << "Press enter to exit.";
	getchar();
	return 0;
}
