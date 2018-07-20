#pragma once

void fText(HDC& memDC,std::string name,int cx,int cy, int Line);
void fText(HDC& memDC,std::string name,int cx, int cy, int Line, int dxLine);
RECT* rfText(HDC& memDC, std::string name, int cx, int cy, int Line);
RECT* rfText(HDC& memDC, std::string name, int cx, int cy, int Line, int dxLine);
//void fText(std::string name, int NumberFind);