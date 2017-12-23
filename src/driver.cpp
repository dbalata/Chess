#include <iostream>
#include <stdio.h>
#include "pieces.h"
#include "piece.h"
#include "board.h"

int main()
{
	Board *b = new Board();

	b->print();
	
	std::cout << "Press enter to exit.";
	getchar();
	return 0;
}