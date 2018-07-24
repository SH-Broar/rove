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

void fxText(HDC & memDC, std::string name, int cx, int cy, int Line,int startTime, int stdTime, int t, int ot)
{
	if ((t-ot) > startTime)
	{
		int c = 255 - (t - ot - startTime) * 15;
		if (c < 0)
			c = 0;
		if ((t - ot - startTime) * 15 > stdTime * 15)
		{
			c = (t - ot - startTime) * 15 - stdTime * 15;
			if (c > 255)
				c = 255;
		}
		SetTextColor(memDC, RGB(c, c, c));
		std::ifstream dataFile(name);
		std::string Inbuff;
		for (int i = 1; i < Line; i++)
			std::getline(dataFile, Inbuff);
		std::getline(dataFile, Inbuff);
		USES_CONVERSION;
		std::wstring tmp(A2W(Inbuff.c_str()));
		TextOut(memDC, cx, cy, tmp.c_str(), tmp.length());
	}
}

void fxText(HDC & memDC, std::string name, int cx, int cy, int Line, int dxLine, int startTime, int stdTime, int t, int ot)
{

	if ((t - ot) > startTime)
	{
		int c = 255 - (t - ot - startTime) * 15;
		if (c < 0)
			c = 0;
		if ((t - ot - startTime) * 15 > stdTime * 15)
		{
			c = (t - ot - startTime) * 15 - stdTime * 15;
			if (c > 255)
				c = 255;
		}
		SetTextColor(memDC, RGB(c, c, c));
		std::ifstream dataFile(name);
		std::string Inbuff;
		int line = 0;
		for (int i = 1; i < Line; i++)
			std::getline(dataFile, Inbuff);
		for (int k = 0; k < dxLine; k++)
		{
			std::getline(dataFile, Inbuff);
			USES_CONVERSION;
			std::wstring tmp(A2W(Inbuff.c_str()));
			TextOut(memDC, cx, cy + line * 24, tmp.c_str(), tmp.length());
			line++;
		}
	}
}

xText::xText(HDC & memDC, std::string text, int cx, int cy, int startTime, int t, int ot)
{
	this->memDC = memDC;
	this->text = text;
	this->cx = cx;
	this->cy = cy;
	this->startTime = startTime;
	this->t = t;
	this->ot = ot;
	this->stdTime = 100000;
}

xText::xText(HDC & memDC, std::string text, int cx, int cy, int startTime, int stdTime, int t, int ot)
{
	this->memDC = memDC;
	this->text = text;
	this->cx = cx;
	this->cy = cy;
	this->startTime = startTime;
	this->t = t;
	this->ot = ot;
	this->stdTime = stdTime;
}

void xText::reset(HDC & memDC, std::string text, int cx, int cy, int startTime, int stdTime, int t, int ot)
{
	this->memDC = memDC;
	this->text = text;
	this->cx = cx;
	this->cy = cy;
	this->startTime = startTime;
	this->t = t;
	this->ot = ot;
	this->stdTime = stdTime;
}

void xText::Out()
{
	if ((t - ot) > startTime)
	{
		int c = 255 - (t - ot - startTime) * 15;
		if (c < 0)
			c = 0;
		if ((t - ot - startTime) * 15 > stdTime * 15)
		{
			c = (t - ot - startTime) * 15 - stdTime * 15;
			if (c > 255)
				c = 255;
		}
		SetTextColor(memDC, RGB(c, c, c));
		USES_CONVERSION;
		std::wstring tmp(A2W(text.c_str()));
		TextOut(memDC, cx, cy, tmp.c_str(), tmp.length());
	}
}
