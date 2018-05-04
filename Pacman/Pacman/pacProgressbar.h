#pragma once

#include "pacTile.h"

class Progressbar
{
	Position position;
	float width;
	float height;
	float progress;
	short color;

	void Print(float startPercentage, float endPercentage, char symbol);
public:
	Progressbar() = delete;
	Progressbar(short width, short height, short xPos, short yPos, short color);
	~Progressbar();

	void SetProgress(short percentage);
	void Show(bool showFlag);
	void SetPosition(Position position);
};

