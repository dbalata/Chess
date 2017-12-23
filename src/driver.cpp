#include <iostream>
#include <stdio.h>
#include "pawn.h"
#include "piece.h"

int main()
{
	Pawn pc(black);

	Piece *pce = &pc;
	
	std::cout << pce->getChar() << std::endl;
	
	std::cout << "Press enter to exit.";
	getchar();
	return 0;
}