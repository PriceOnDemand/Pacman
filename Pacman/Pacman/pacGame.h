#pragma once

#include "pacError.h"
#include "pacIO.h"
#include <Windows.h>


class Game
{
private:
	struct
	{
		short loopDelay;
		short tickDelay;
	} config;
	
	class Inputs : public InputManager
	{
		void KeyEventProc(KEY_EVENT_RECORD);
		void MouseEventProc(MOUSE_EVENT_RECORD);
	} inputs;


	bool isRunning;

	bool RunTick();
	void RunAnimationFrame();

public:
	Game();
	~Game();

	pac::Result Initialize();
	pac::Result Run();
};