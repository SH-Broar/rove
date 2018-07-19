#include "stdafx.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{

}
void SceneManager::Oncreate(HINSTANCE hInst)
{
	player.NowScene = SN_splash;
	tick = 0; otick = 0;
	stop = false;
	Logo.LoadFromResource(hInst, IDC_LOGO);
	rove.LoadFromResource(hInst, IDB_TITLE);
	
}

void SceneManager::GetClient(HWND hWnd)
{
	GetClientRect(hWnd, &clientRECT);
}

SceneManager::~SceneManager()
{

}

int SceneManager::timeElasped()
{
	return (tick - otick) / 10;
}

void SceneManager::CreateScene()
{
	switch (player.NowScene)
	{
		case SN_splash:
			stop = true;
			break;
		case SN_title:
			Logo.Destroy();
			tick = 0; otick = 0;
			title_keydown = false;
			title_blink = 0;
			title_menuSelect = false;
			title_choice = false;
			title_textOn = false;
			break;
		case SN_opening:
			break;
		case SN_diary:
			tick = 0; otick = 0;
			break;
	}
}

void SceneManager::ChangeScene(SceneNumber n)
{
	player.NowScene = n;
	CreateScene();
}

void SceneManager::Timer(WPARAM wParam)
{
	if (wParam == 1) //Time Master
	{

		if (stop == true)
			tick++;
		if (stop == false)	// 전역 bool변수 stop을 true로 바꾸면 체크 시작
			otick = tick;

		if (tick >= INT_MAX - 1)
		{
			otick = -(tick - otick);
			tick = 0;
		}
	}
	if (wParam == 99)
	{
		system("cls");
		printf("r o v e\n");
		printf("copyrightⓒ 2018 NULL-SCAPE\n\n");
		printf("CurrentScene : %d\n", player.NowScene);
		printf("tick : %d , otick : %d\n\n", tick, otick);
		printf("pas %d end %d int %d ext %d / ind %d nai %d opt %d res %d\n", player.stat.passion, player.stat.endurence, player.stat.intelligent, player.stat.extroverted, player.stat.independent, player.stat.naive, player.stat.optimism, player.stat.resistance);
	}
}

void SceneManager::KeyManager(WPARAM wParam)
{
	switch (wParam)
	{
	case VK_RETURN:
		switch (player.NowScene)
		{
		case SN_splash:
			ChangeScene(SN_title);
			break;
		case SN_title:
			if (title_menuSelect)
			{
				switch (title_choice)
				{
				case 0:
					player.PlayerLoadFromFile();
					break;
				case 1:
					ChangeScene(SN_opening);
					break;
				case 2:
					ChangeScene(SN_diary);
					break;

				}

			}
			else
				title_keydown = true;

			break;
		}
		break;
	case VK_UP:
		switch (player.NowScene)
		{
		case SN_title:
			if (title_menuSelect)
			{
				if (title_textOn)
				{
					if (title_choice == 0)
						title_choice = 2;
					else if (title_choice == 1)
						title_choice = 0;
					else
						title_choice = 1;
				}
				else
				{
					if (title_choice)
						title_choice = 0;
					else
					{
						title_choice = 1;
						title_blink++;
					}
				}

			}
			break;
		}
		break;
	case VK_DOWN:
		switch (player.NowScene)
		{
		case SN_title:
			if (title_menuSelect)
			{
				if (title_textOn)
				{
					if (title_choice == 0)
						title_choice = 1;
					else if (title_choice == 1)
						title_choice = 2;
					else
						title_choice = 0;
				}
				else
				{
					if (title_choice)
						title_choice = 0;
					else
					{
						title_choice = 1;
						title_blink++;
					}
				}
			}
			break;
		}
		break;
	}
}

void SceneManager::SceneDispatch(HDC& memDC)
{
	switch (player.NowScene)
	{
	case SN_splash:
		splash(memDC);
		break;
	case SN_title:
		title(memDC);
		break;
	case SN_opening:
		opening(memDC);
		break;
	case SN_diary:
		diary(memDC);
		break;
	}
}

void SceneManager::splash(HDC& memDC)
{
	if (timeElasped() > 7 && timeElasped() < 15)
		Logo.AlphaBlend(memDC, clientRECT.right / 2 - Logo.GetWidth() / 2, clientRECT.bottom / 2 - Logo.GetHeight() / 2, (tick - 70) * 3);
	if (timeElasped() >= 15 && timeElasped() < 25)
		Logo.Draw(memDC, clientRECT.right / 2 - Logo.GetWidth() / 2, clientRECT.bottom / 2 - Logo.GetHeight() / 2);
	if (timeElasped() >= 25 && timeElasped() < 33)
		Logo.AlphaBlend(memDC, clientRECT.right / 2 - Logo.GetWidth() / 2, clientRECT.bottom / 2 - Logo.GetHeight() / 2, 255 - (tick - 250) * 3);

	if (timeElasped() >= 40 && timeElasped() < 48)
		rove.AlphaBlend(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2, (tick - 400) * 3);

	else if (timeElasped() >= 48)
	{
		rove.Draw(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2 - (timeElasped() - 48) * 4);

		if (timeElasped() > 55)
		{
			ChangeScene(SN_title);
		}
	}
}

void SceneManager::title(HDC& memDC)
{
	if (title_menuSelect)
	{
		TextOut(memDC, clientRECT.right / 2 - 80, clientRECT.bottom / 2 - 60, L"처 음 부 터  시 작 하 기", lstrlen(L"처 음 부 터  시 작 하 기"));
		TextOut(memDC, clientRECT.right / 2 - 40, clientRECT.bottom / 2 + 40, L"계 속 하 기", lstrlen(L"계 속 하 기"));
		if (title_blink > 5)
		{
			title_textOn = true;
			TextOut(memDC, clientRECT.right / 2 - 56, clientRECT.bottom / 2 + 210, L"여 행 의  기 록", lstrlen(L"여 행 의  기 록"));

			if (title_choice == 0)
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 - 60, L">", lstrlen(L">"));
			}
			else if (title_choice == 1)
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 + 40, L">", lstrlen(L">"));
			}
			else
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 + 210, L">", lstrlen(L">"));
			}
		}
		else
		{
			if (title_choice)
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 + 40, L">", lstrlen(L">"));
			}
			else
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 - 60, L">", lstrlen(L">"));
			}
		}


	}
	else
	{
		if ((tick - otick) * 20 < 255 && title_keydown == false)
		{
			rove.AlphaBlend(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2 - 32, (tick - otick) * 20);
		}
		else if (title_keydown == false) //처음 들어올 때 효과음
		{
			rove.Draw(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2 - 32);
			if ((timeElasped() / 3) % 2 == 1)
				TextOut(memDC, 200, 500, L"P r e s s   E n t e r   t o   S t a r t", lstrlen(L"P r e s s   E n t e r   t o   S t a r t"));
		}
		else if (title_blink < 10)
		{
			rove.Draw(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2 - 32);
			if (((tick - otick)) % 2 == 1)
				TextOut(memDC, 200, 500, L"P r e s s   E n t e r   t o   S t a r t", lstrlen(L"P r e s s   E n t e r   t o   S t a r t"));
			title_blink++;
			if (title_blink >= 10)
				tick = 0; otick = 0;
		}
		else if ((tick - otick) * 20 < 255)
		{
			rove.AlphaBlend(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2 - 32, 255 - ((tick - otick) * 20));
		}
		else
		{
			if (timeElasped() > 3)
			{
				title_menuSelect = true;
				title_blink = 0;
				rove.Destroy();
			}
		}
	}
}

void SceneManager::diary(HDC& memDC)
{
}

void SceneManager::opening(HDC& memDC)
{
}
