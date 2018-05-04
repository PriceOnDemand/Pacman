#pragma once

#include "pacTile.h"
#include <windows.h>
#include <vector>



class InputManager
{
private:
	HANDLE cursor;
	DWORD numEventsCaught, consoleMode, i;
	INPUT_RECORD eventBuffer[128];

public:
	InputManager();

	void check();
	virtual void KeyEventProc(KEY_EVENT_RECORD) = 0;
	virtual void MouseEventProc(MOUSE_EVENT_RECORD) = 0;
};


Position GetRelativeMousePosition();