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
	Color currentTurn = blue;
	std::string colorStrings[] = { "blue", "red" };
	while(true)
	{
		b->print();
		std::cout << colorStrings[currentTurn] << "'s turn." << std::endl;
		std::cout << "Select a piece." << std::endl;
		std::string input;
		std::cin.clear();

		while (input.size() != 3)
		{
			std::getline(std::cin, input);
		}

		Pair<int> pieceLoc = getInput(input);
		int x = pieceLoc.fst;
		int y = pieceLoc.snd;
		Piece *pce = b->getPieceAt(x, y);

		if (pce->getChar() == 'x' || pce->getColor() != currentTurn)
		{
			std::cout << "Invalid." << std::endl;
			continue;
		}

		std::cout << "Selected type: " << pce->getChar() << std::endl;
		std::vector<Pair<int> > moves = pce->getValidMoves(x, y);
		std::cout << "Availiable moves: (-1 to choose a different piece)" << std::endl << movesToString(moves) << std::endl;

		int selection;
		std::cin >> selection;
		if (selection == -1) continue;
		Pair<int> pieceMoveLoc = moves[selection];
		Color result = b->movePiece(pieceLoc, pieceMoveLoc);

		if (result != empty)
		{
			std::cout << result << "has won.";
			break;
		}

		currentTurn = (currentTurn == blue) ? red : blue;
		pce->move();
	}
	
	std::cout << "Press enter to exit.";
	getchar();
	return 0;
}
