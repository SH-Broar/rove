#pragma once
#include "PlayerDataClass.h"
#include "resource.h"
#include "TextFromFile.h"

class SceneManager
{
private:
	//
	PlayerDataClass player;
	int tick; int otick;
	int tickn;
	int MouseX; int MouseY;
	bool stop;
	bool ending[30];
	RECT clientRECT;
	HWND hDesktopwnd = GetDesktopWindow();
	HDC hDesktopdc = GetWindowDC(hDesktopwnd);
	//splash
	CImage Logo;
	CImage rove;
	//title
	bool title_keydown;
	int title_blink;
	bool title_menuSelect;
	int title_choice;
	bool title_textOn;
	//diary
	std::ifstream d_saveFile;
	std::string Inbuff;
	int cursorPos;
	int cursorLine;
	//opening
	int open_textPreTime[100];
	int open_textNum;
	int open_storyNum;
	int open_tutorial_choice;
	POINT open_textXY[10];
public:
	SceneManager();
	void Oncreate(HINSTANCE hInst);
	void GetClient(HWND hWnd);
	~SceneManager();

	int timeElasped();
	void mouseXY(LPARAM lParam);
	void CreateScene();
	void ChangeScene(SceneNumber n);
	void Timer(WPARAM wParam);
	void KeyManager(WPARAM wParam);
	//
	void SceneDispatch(HDC& memDC);
	void splash(HDC& memDC);
	void title(HDC& memDC);
	void diary(HDC& memDC);
	void opening(HDC& memDC);
};

