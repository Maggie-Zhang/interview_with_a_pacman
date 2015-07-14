// LINK THIS WITH WINMM.LIB

#include "stdafx.h"
#include "conio.h"
#include "windows.h"

class Game
{

public:
	long timeoutc;	// Validity of user input
	char c;			// User input
	long t;			// Game time
	short pos;		// Monster position
	short oldpos;	// Old monster position
	long mupdt;		// Monster next update time
};

// To position the console cursor position
void GotoXY( short x, short y ) 
{ 
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };

	SetConsoleCursorPosition( hStdout, position );
} 

void InitGame(Game& game)
{
	// To remove the console visible cursor
	CONSOLE_CURSOR_INFO l_Struct;
	l_Struct.dwSize = 1;
	l_Struct.bVisible = false;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ; 
	SetConsoleCursorInfo(hStdout, &l_Struct);

	game.c = ' ';
	game.pos = 0;

	game.t = timeGetTime();
}

// To read the console input in a non-blocking way
void GetUserInput(Game& game)
{
	if (_kbhit())
		game.c = _getch();
}

// Perform all the non-user updates
void PerformAI(Game& game)
{
	// Time to update AI !
	if (game.t > game.mupdt)
	{
		game.oldpos = game.pos;
		game.pos = (game.pos + 1) % 10;
		game.mupdt = game.t + 1000;
	}
}

int PickANumberAnyNumber() 
{
	return rand();
}

// Refresh the game output
void DrawGame(const Game& game)
{
	// Draw something
	GotoXY(5,5);
	printf("%s: %c at %d", (game.c == 'K') ?  "LEFT!" : "CAR", game.c, game.t);

	// Draw pacman if position changed
	if (game.oldpos != game.pos)
	{
		GotoXY(game.oldpos, 10);
		printf(" ");
		GotoXY(game.pos, 10);
		printf("*");
	}
}

// Determine if the game end condition
bool IsGameFinished(const Game& game)
{
	return (game.c == 'q');
}

// Display the game results
void DisplayResults(const Game& game)
{
	// Clear screen
	system("cls");

	printf("** Whatever wins! ** \n\n");
	printf("<press a key to continue>\n");

	_getch();
}

// Un-init the game
void TerminateGame(Game& game)
{

}

int _tmain(int argc, _TCHAR* argv[])
{
	Game game;

	InitGame(game);

	while (!IsGameFinished(game))
	{
		// Get game time
		game.t = timeGetTime();

		GetUserInput(game);
		PerformAI(game);
		DrawGame(game);
	}

	DisplayResults(game);

	TerminateGame(game);

	return 0;
}

