#pragma once

class Position
{
public:
	short x;
	short y;
};


class Tile
{
public:
	Tile();
	~Tile();

	Position pos;
};
