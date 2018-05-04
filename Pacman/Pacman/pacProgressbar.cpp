#include "pacProgressbar.h"
#include "pacUtility.h"



Progressbar::Progressbar(short width, short height, short xPos, short yPos, short color)
{
	this->width = (float)width;
	this->height = (float)height;
	this->progress = 0;
	this->position = { xPos, yPos };
	this->color = color;
}

Progressbar::~Progressbar()
{
}

void Progressbar::Print(float startPercentage, float endPercentage, char symbol)
{
	float offset, endPosition;

	if(startPercentage >= 1)
		startPercentage--;
	if (symbol == ' ')				// All to prevent rounding errors
		endPercentage += 3;
	if (endPercentage > 100)
		endPercentage = 100;
	
	offset = this->position.x + (width * (startPercentage / 100));
	endPosition = (this->width * (endPercentage / 100)) - offset + this->position.x;


	SetFontColor(this->color);
	for (int i = 0; i < endPosition; i++)
	{
		SetCursorPosition(offset + i, this->position.y);
		PrintHLine(symbol, this->height);
	}
	SetFontColor(GREY);
}

void Progressbar::SetProgress(short percentage)
{
	short oldProgress = this->progress;
	this->progress = (float)percentage;

	if (progress > oldProgress)
		this->Print(oldProgress, progress, 219);
	else
		this->Print(progress, oldProgress, ' ');
}

void Progressbar::Show(bool showFlag)
{
	if (showFlag)
		this->Print(0, this->progress, 219);
	else
		this->Print(0, 100, ' ');
}

void Progressbar::SetPosition(Position position)
{
	if(progress) this->Show(false);
	this->position = position;
	this->Show(true);
}
