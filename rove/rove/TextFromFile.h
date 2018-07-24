#pragma once

void fText(HDC& memDC,std::string name,int cx,int cy, int Line);
void fText(HDC& memDC,std::string name,int cx, int cy, int Line, int dxLine);

class fxText {

};

void fxText(HDC & memDC, std::string name, int cx, int cy, int Line, int startTime, int stdTime, int t, int ot);
void fxText(HDC & memDC, std::string name, int cx, int cy, int Line, int dxLine, int startTime, int stdTime, int t, int ot);

class xText
{
private:
	HDC memDC;
	std::string text;
	int cx;
	int cy;
	int startTime;
	int stdTime;
	int t;
	int ot;

public:
	xText(HDC & memDC, std::string text, int cx, int cy, int startTime, int t, int ot);
	xText(HDC & memDC, std::string text, int cx, int cy, int startTime, int stdTime, int t, int ot);
	void reset(HDC & memDC, std::string text, int cx, int cy, int startTime, int stdTime, int t, int ot);
	void Out();
};
