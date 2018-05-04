#include "pacUtility.h"


HANDLE cursor = GetStdHandle(STD_OUTPUT_HANDLE);
HWND console = GetConsoleWindow();
CONSOLE_FONT_INFOEX font;
CONSOLE_SCREEN_BUFFER_INFO sbInfo;
CONSOLE_CURSOR_INFO cursorInfo;
WORD background = 0x0000;

int G_fontsize = 10;
int G_RectXInPxl = 10, G_RectYInPxl = 10;
int G_RectXInCh = 80, G_RectYInCh = 25;


void SetConsoleSize(int length, int higth)
{
	RECT r;
	GetWindowRect(console, &r);

	G_RectXInCh = length;
	G_RectYInCh = higth;

	length = length * G_fontsize / 2.1 + 33;
	higth = higth * G_fontsize + 53;

	G_RectXInPxl = length;
	G_RectYInPxl = higth;

	MoveWindow(console, r.left, r.top, length, higth, TRUE);
}


void SetCodePage(short pageID)
{
	SetConsoleOutputCP(pageID);
	SetConsoleCP(pageID);
}


void SetFontSize(short size)
{
	font.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	GetCurrentConsoleFontEx(cursor, false, &font);
	font.dwFontSize.Y = size;
	SetCurrentConsoleFontEx(cursor, false, &font);

	G_fontsize = size;
}


void SetFontColor(WORD colorID)
{
	SetConsoleTextAttribute(::GetStdHandle(STD_OUTPUT_HANDLE), background + colorID);
}


void ShowConsoleCursor(bool flag)
{
	GetConsoleCursorInfo(cursor, &cursorInfo);
	cursorInfo.bVisible = flag;
	SetConsoleCursorInfo(cursor, &cursorInfo);
}

pac::Result SetCursorPosition(short xPos, short yPos)
{
	if (SetConsoleCursorPosition(cursor, { xPos, yPos }))
		return pac::Result::SUCCESS;
	return pac::Result::FAILURE;
}

pac::Result GetCursorPosition(short &xPos, short &yPos)
{
	if (GetConsoleScreenBufferInfo(cursor, &sbInfo))
	{
		xPos = sbInfo.dwCursorPosition.X;
		yPos = sbInfo.dwCursorPosition.Y;
		return pac::Result::SUCCESS;
	}
	else
	{
		POST_DEBUG_MESSAGE(-1, "Failed to load ScreenbufferInfo");
		return pac::Result::FAILURE;
	}
}

void PrintLine(char symbol, short length)
{
	for (int i = 0; i < length; i++)
	{
		putchar(symbol);
	}
}

void PrintHLine(char symbol, short length)
{
	short xPos, yPos;
	GetCursorPosition(xPos, yPos);

	for (int i = 0; i < length; i++)
	{
		SetCursorPosition(xPos, yPos + i);
		putchar(symbol);
	}
}