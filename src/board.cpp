#include "board.h"
#include "pieces/pieces.h"
#include <iostream>
#include <windows.h>

Board::Board()
{
	placePieces();
}

Color Board::movePiece(Pair<int> init, Pair<int> dest)
{
	Piece *p = getPieceAt(init);
	placePiece(init.fst, init.snd, new EmptyTile());
	placePiece(dest.fst, dest.snd, p);
	if (getPieceAt(dest)->getChar() == 'K') return p->getColor();
	return empty;
}

void Board::placePieces()
{
	for(int i = 0; i < BoardDim::WIDTH; i++)
	{
		for(int j = 0; j < BoardDim::HEIGHT; j++)
		{
			grid[i][j] = new EmptyTile();
		}
	}

	for(int i = 0; i < BoardDim::WIDTH; i++)
	{
		grid[1][i] = new Pawn(blue, this);
		grid[BoardDim::HEIGHT - 2][i] = new Pawn(red, this);
	}

	grid[0]						[0] 					= new Rook(blue, this);
	grid[0]						[BoardDim::WIDTH - 1] 	= new Rook(blue, this);
	grid[BoardDim::HEIGHT - 1]	[0] 					= new Rook(red, this);
	grid[BoardDim::HEIGHT - 1]	[BoardDim::WIDTH - 1] 	= new Rook(red, this);	

	grid[0]						[1]						= new Knight(blue, this);
	grid[0]						[BoardDim::WIDTH - 2]	= new Knight(blue, this);
	grid[BoardDim::HEIGHT - 1]	[1]						= new Knight(red, this);
	grid[BoardDim::HEIGHT - 1]	[BoardDim::WIDTH - 2]	= new Knight(red, this);

	grid[0]						[2]						= new Bishop(blue, this);
	grid[0]						[BoardDim::WIDTH - 3]	= new Bishop(blue, this);
	grid[BoardDim::HEIGHT - 1]	[2]						= new Bishop(red, this);
	grid[BoardDim::HEIGHT - 1]	[BoardDim::WIDTH - 3]	= new Bishop(red, this);

	grid[0]						[3]						= new Queen(blue, this);
	grid[BoardDim::HEIGHT - 1]	[BoardDim::WIDTH - 4]	= new Queen(red, this);

	grid[0]						[4]						= new King(blue, this);
	grid[BoardDim::HEIGHT - 1]	[BoardDim::WIDTH - 5]	= new King(red, this);
}

void Board::print()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(console, 0x70);

	std::cout << "  ";

	for(int i = 0; i < BoardDim::WIDTH; i++)
	{
		std::cout << i;
		std::cout << ' ';
	}

	std::cout << std::endl;

	for(int i = 0; i < BoardDim::WIDTH; i++)
	{
		std::cout << i;
		std::cout << ' ';
		for(int j = 0; j < BoardDim::HEIGHT; j++)
		{
			char c = grid[i][j]->getChar();
			if(c == 'x') SetConsoleTextAttribute(console, 0x8 | 0x70);
			else if(grid[i][j]->getColor() == blue) SetConsoleTextAttribute(console, 0x1 | 0x70);
			else if(grid[i][j]->getColor() == red) SetConsoleTextAttribute(console, 0x4 | 0x70);
			std::cout << c;
			SetConsoleTextAttribute(console, 0x70);
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}