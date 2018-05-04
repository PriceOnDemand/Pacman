#include "pacGame.h"
#include <chrono>
#include <thread>


Game::Game()
{
}


Game::~Game()
{
}


bool Game::RunTick()
{
	/*
	In Jedem Tick wird die neue Spielerposition neu Berechnet und Funktionen wie followPath und ähnliches werden aufgerufen -> Die map wird aktualisiert
	Wird das Spiel in diesem Tick verloren, liefert die Funktion eine 0.
	*/

	return false;
}

void Game::RunAnimationFrame()
{
	/*
	Wird Multithreading nicht unterstützt, wird in jedem Schleifendurchlauf geschaut ob ein neuer Frame berechnet werden muss.
	*/
}


pac::Result Game::Initialize()
{
	/*
	Die Config-Datei wird ausgelesen und die entsprechenden Variablen werden initialisiert
	Das erste Menu wird aus data geladen
	Sprache wird geladen usw

	Klappt etwas nicht wird ein Error ausgeöst
	*/

	return pac::Result::SUCCESS;
}




pac::Result Game::Run()
{
	if (this->isRunning) return pac::Result();

	this->isRunning = true;
	std::chrono::high_resolution_clock::time_point lastTick = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point lastAnimationFrame = std::chrono::high_resolution_clock::now();

	// GAMELOOP
	while (this->isRunning)
	{
		inputs.check();

		if (lastTick + std::chrono::milliseconds(config.tickDelay) <= std::chrono::high_resolution_clock::now())
		{
			this->isRunning = RunTick();
			lastTick = std::chrono::high_resolution_clock::now();
		}
		if (lastAnimationFrame + std::chrono::milliseconds(config.tickDelay) <= std::chrono::high_resolution_clock::now())
		{
			RunAnimationFrame();
			lastAnimationFrame = std::chrono::high_resolution_clock::now();
		}

		std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(config.loopDelay));
	}

	return pac::Result::SUCCESS;
}


void Game::Inputs::KeyEventProc(KEY_EVENT_RECORD keyInfo)
{
}

void Game::Inputs::MouseEventProc(MOUSE_EVENT_RECORD mouseInfo)
{
}
