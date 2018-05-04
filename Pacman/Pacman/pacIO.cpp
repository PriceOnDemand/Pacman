#include "pacIO.h"
#include "pacError.h"


InputManager::InputManager()
{
	cursor = GetStdHandle(STD_INPUT_HANDLE);
	if (cursor == INVALID_HANDLE_VALUE)
		POST_DEBUG_MESSAGE(-1, "Invalid Handle Value, GetStdHandle failed.");

	// Quickedit deaktivieren
	consoleMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(cursor, consoleMode))
		POST_DEBUG_MESSAGE(-1, "Failed to set Console Mode (Couldn't deaktivate Quickedit)");

	// Fenster und Mouse inputs aktivieren
	consoleMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(cursor, consoleMode))
		POST_DEBUG_MESSAGE(-1, "Failed to activate mouse or window inputs");
}

void InputManager::check()
{
	if (!ReadConsoleInput(cursor, eventBuffer, 128, &numEventsCaught))
		POST_DEBUG_MESSAGE(-1, "Failed to Read Console Input");

	// 
	for (i = 0; i < numEventsCaught; i++)
	{
		switch (eventBuffer[i].EventType)
		{
		case KEY_EVENT:
			KeyEventProc(eventBuffer[i].Event.KeyEvent);
			break;

		case MOUSE_EVENT:
			MouseEventProc(eventBuffer[i].Event.MouseEvent);
			break;
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Position GetRelativeMousePosition()
{
	/*
	Berechnung der aktuellen Mausposition (Coordinaten-Skalierung entspricht der der Zeichen in der Konsole)
	aus:

	Tatsächliche Mausposition in Pixel,
	Fensterposition und Größe,
	Schriftgröße,
	Evtl Schriftart
	*/

	return Position();
}
