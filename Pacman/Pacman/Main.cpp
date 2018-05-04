

/*
=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-             
											 ____
											|  _ \    __ _    ___   _ __ ___     __ _   _ __
											| |_) |  / _` |  / __| | '_ ` _ \   / _` | | '_ \
											|  __/  | (_| | | (__  | | | | | | | (_| | | | | |
											|_|      \__,_|  \___| |_| |_| |_|  \__,_| |_| |_|

Project:
Version:
Developers:

[...]

Libraries:
APIs:
Source:

=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-=--o--=-
*/




#include "pacGame.h"
#include "pacError.h"
#include "pacMemory.h"
#include "pacUtility.h"
#include "pacProgressbar.h"


int main(void)
{
	/*Game game;
	Error result;

	result = game.Initialize();
	result.HandleErrorMessage();

	// TODO: Alles mögliche Menu-Zeug
	
	result = game.Run();*/

	ShowConsoleCursor(false);



	SetCursorPosition(0, 28);
	system("pause");

	return 0;
}