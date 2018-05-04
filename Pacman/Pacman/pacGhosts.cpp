#include "pacGhosts.h"



Ghost::Ghost()
{
}


Ghost::~Ghost()
{
}


void Ghost::UpdateTargetTile()
{
	// PURE VIRTUAL FUNCTION
}


pac::Result Ghost::MoveTo(Tile target)
{
	/*
	Geist wird teleportiert:
	Zeichen wird an neue Position gezeichnet, Zeichen an alter Position wird zurückgesetzt
	Variablen werden aktuallisiert

	falls eine Wand im Weg ist, wird ein entsprechender Error ausgegeben
	*/

	return pac::Result::SUCCESS;
}


void Ghost::FollowCurrentPath()
{
	/*
	Mit Hilfe von lastTile wird bestimmt in welche Richtung sich der Geist mit moveTo bewegt

	falls Richtung nicht feststellbar ist, wird ein error ausgegeben, ansonsten entsprechende errors von moveTo
	*/
}


void Ghost::TakeNextPathTo(Tile target)
{
	/*
	Mit Hilfe von 4 Vektoren wird entschieden, in welcher Richtung die kürzeste Luftlinie ist. Dorthin bewegt sich der Geist mit
	moveTo um 1 Feld

	Errors von moveTo und invalid target usw

	wird an Kreuzungen aufgerufen
	*/
}


void Ghost::SwapDirection()
{
	/*
	Wird aufgerufen, wenn die Phase wechselt, mit Hilfe von Abänderung von lastTile sodass followCurrentPath in die andere Richtung wirkt
	*/
}

Tile Ghost::GetCurrentTile() const
{
	return currentTile;
}

Tile Ghost::GetTargetTile() const
{
	return targetTile;
}
