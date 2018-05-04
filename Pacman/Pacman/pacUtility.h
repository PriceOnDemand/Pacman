#pragma once

#include "pacError.h"
#include <Windows.h>


// Schriftfarben

#define  DBLACK    0x0000
#define  DBLUE     0x0001
#define  DGREEN    0x0002
#define  DTEAL     0x0003
#define  DRED      0x0004
#define  DPURPLE   0x0005
#define  DGOLD     0x0006
#define  GREY      0x0007
#define  DGREY     0x0008
#define  BLUE      0x0009
#define  GREEN     0x000a
#define  TEAL      0x000b
#define  RED       0x000c
#define  PURPLE    0x000d
#define  YELLOW    0x000e
#define  WHITE     0x000f


// Schriftarten

#define  BOLD      0x000l
#define  STRIKE    0x000m
#define  ULINE     0x000n
#define  ITALIC    0x000o
#define  RESET     0x0007


// Hintergründe

#define  HDBLACK    0x0000
#define  HDBLUE     0x0010
#define  HDGREEN    0x0020
#define  HDTEAL     0x0030
#define  HDRED      0x0040
#define  HDPURPLE   0x0050
#define  HDGOLD     0x0060
#define  HGREY      0x0070
#define  HDGREY     0x0080
#define  HBLUE      0x0090
#define  HGREEN     0x00a0
#define  HTEAL      0x00b0
#define  HRED       0x00c0
#define  HPURPLE    0x00d0
#define  HYELLOW    0x00e0
#define  HWHITE     0x00f0


#define USE_UTILITY_GLOBALS  \
	extern int G_fontsize;	 \
	extern int G_RectXInPxl; \
	extern int G_RectYInPxl; \
	extern int G_RectXInCh;	 \
	extern int G_RectYInCh


// Font
void SetCodePage(short pageID);
void SetFontSize(short size);
void SetFontColor(WORD colorID);


// Cursor
pac::Result SetCursorPosition(short xPos, short yPos);
pac::Result GetCursorPosition(short &xPos, short &yPos);
void ShowConsoleCursor(bool flag);


// Anything else
void PrintLine(char symbol, short length);
void PrintHLine(char symbol, short length);