#include "stdafx.h"
#include <atlconv.h>
#include "TextFromFile.h"

void fText(HDC &memDC, std::string name, int cx, int cy, int Line)
{
	std::ifstream dataFile(name);
	std::string Inbuff;
	for (int i = 1; i < Line; i++)
		std::getline(dataFile, Inbuff);
	std::getline(dataFile, Inbuff);
	USES_CONVERSION;
	std::wstring tmp(A2W(Inbuff.c_str()));
	TextOut(memDC, cx, cy, tmp.c_str(),tmp.length());
}

void fText(HDC &memDC, std::string name, int cx, int cy, int Line, int dxLine)
{
	std::ifstream dataFile(name);
	std::string Inbuff;
	int line=0;
	for (int i = 1; i < Line; i++)
		std::getline(dataFile, Inbuff);
	for (int k = 0; k < dxLine; k++)
	{
		std::getline(dataFile, Inbuff);
		USES_CONVERSION;
		std::wstring tmp(A2W(Inbuff.c_str()));
		TextOut(memDC, cx, cy+line*24, tmp.c_str(), tmp.length());
		line++;
	}
}

RECT* rfText(HDC &memDC, std::string name, int cx, int cy, int Line)
{
	RECT tmp;
	return &tmp;
}

RECT* rfText(HDC &memDC, std::string name, int cx, int cy, int Line, int dxLine)
{
	RECT tmp;
	return &tmp;
}
