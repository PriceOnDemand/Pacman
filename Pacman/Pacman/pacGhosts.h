#pragma once

#include "pacTile.h"
#include "pacError.h"


class Ghost
{
private:
	Tile homeTile;
	Tile targetTile;
	Tile lastTile;
	Tile currentTile;

	short movingDelay;
	char coveredChar;

public:
	Ghost();
	~Ghost();

	virtual void UpdateTargetTile();
	pac::Result MoveTo(Tile target);
	void FollowCurrentPath();
	void TakeNextPathTo(Tile target);
	void SwapDirection();

	Tile GetCurrentTile() const;
	Tile GetTargetTile() const;
};




// BEISPIEL:

/*

class : Ghost
{
	void UpdateTargetTile()
	{	
		Individueller target-finding Alogorithmus
	}
}clyde;

*/