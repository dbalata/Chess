#include "board.h"
#include "pieces.h"
#include <iostream>
#include <windows.h>

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
		grid[HEIGHT - 2][i] = new Pawn(black, this);
	}
}

void Board::print()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

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
			char c = grid[i][j]->getChar();
			if(c == 'x') SetConsoleTextAttribute(console, 8);
			else if(grid[i][j]->getColor() == white) SetConsoleTextAttribute(console, 1);
			else if(grid[i][j]->getColor() == black) SetConsoleTextAttribute(console, 4);
			std::cout << c;
			SetConsoleTextAttribute(console, 15);
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}