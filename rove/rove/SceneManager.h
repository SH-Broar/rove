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
	int MouseX; int MouseY;
	bool stop;
	bool ending[30];
	RECT clientRECT;
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
	//
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

