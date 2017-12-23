#include "board.h"
#include "pieces.h"
#include <iostream>

Board::Board()
{
	for(int i = 0; i < WIDTH; i++)
	{
		for(int j = 0; j < HEIGHT; j++)
		{
			grid[i][j] = new EmptyTile();
		}
	}

	for(int i = 0; i < WIDTH; i++)
	{
		grid[1][i] = new Pawn(white, this);
		grid[HEIGHT - 2][i] = new Pawn(white, this);
	}
}

void Board::print()
{
	std::cout << "  ";

	for(int i = 0; i < WIDTH; i++)
	{
		std::cout << i;
		std::cout << ' ';
	}

	std::cout << std::endl;

	for(int i = 0; i < WIDTH; i++)
	{
		std::cout << i;
		std::cout << ' ';
		for(int j = 0; j < HEIGHT; j++)
		{
			std::cout << grid[i][j]->getChar();
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}