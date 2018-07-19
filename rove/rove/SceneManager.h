#pragma once
#include "PlayerDataClass.h"
#include "resource.h"

class SceneManager
{
private:
	//
	PlayerDataClass player;
	int tick; int otick;
	bool stop;
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
	//
public:
	SceneManager();
	void Oncreate(HINSTANCE hInst);
	void GetClient(HWND hWnd);
	~SceneManager();


	int timeElasped();
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

