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
	for (int i = 0; i < 30; i++)
		ending[i] = false;
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
void SceneManager::mouseXY(LPARAM lParam)
{
	MouseX = LOWORD(lParam);
	MouseY = HIWORD(lParam);
}
void SceneManager::CreateScene()
{
	switch (player.NowScene)
	{
	case SN_splash:
		stop = true;
		tickn = 1;
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
		tick = 0; otick = 0;
		open_textNum = 0;
		open_textPreTime;
		open_storyNum = 0;
		open_tutorial_choice = 0;
		break;
	case SN_diary:
	{
		tick = 0; otick = 0;
		cursorPos = 0; cursorLine = 0;
		d_saveFile.open("Save\\Diary");
		std::string tmp;
		for (int i = 0; i < 30; i++)
		{
			Inbuff = "";
			tmp = "";
			while (d_saveFile >> tmp)
			{
				if (tmp == ".")
					break;
				else
					Inbuff = Inbuff + tmp;
			}
			switch (i + 1)
			{
			case 1:
				if (Inbuff.compare("ThisisfinalcurtaincallbeforetheFINALE") == 0) ending[i] = true;
				break;
			case 2:
				if (Inbuff.compare("test") == 0) ending[i] = true;
				break;
			case 3:
				if (Inbuff.compare("") == 0) ending[i] = true;
				break;
			case 4:
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 5:					
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 6:					
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 7:					
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 8:					
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 9:					
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 10:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 11:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 12:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 13:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 14:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 15:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 16:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 17:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 18:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 19:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 20:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 21:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 22:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 23:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 24:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 25:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 26:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 27:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 28:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 29:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;				
			case 30:				
				if (Inbuff.compare("5") == 0) ending[i] = true;
				break;
			}
		}
		d_saveFile.close();
	}
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

		/*if (tick >= INT_MAX - 1)
		{
			otick = -(tick - otick);
			tick = 0;
		}*/
	}
	if (wParam == 99) //Debug
	{
		system("cls");
		printf("r o v e\n");
		printf("copyrightⓒ 2018 NULL-SCAPE\n\n");
		printf("CurrentScene : %d\n", player.NowScene);
		printf("tick : %d , otick : %d\n\n", tick, otick);
		printf("pas %d end %d int %d ext %d / ind %d nai %d opt %d res %d\n", player.stat.passion, player.stat.endurence, player.stat.intelligent, player.stat.extroverted, player.stat.independent, player.stat.naive, player.stat.optimism, player.stat.resistance);
		printf("\n");
		if (player.NowScene == SN_diary)
		{
			printf("▽save sentences\n");
			d_saveFile.open("Save\\Diary");
			std::string tmp;
			for (int i = 0; i < 30; i++)
			{
				Inbuff = "";
				tmp = "";
				while (d_saveFile >> tmp)
				{
					if (tmp == ".")
						break;
					else
						Inbuff = Inbuff + tmp;
				}

				if (i % 2 == 1)
					std::cout << Inbuff << std::endl;
				else
					std::cout << Inbuff << "  ";

			}
			d_saveFile.close();
		}
	}
}

void SceneManager::KeyManager(WPARAM wParam)
{
	switch (player.NowScene)
	{
	case SN_splash:
	{
		switch (wParam)
		{
		case VK_RETURN:
			ChangeScene(SN_title);
			break;
		}
	}
	break;
	case SN_title:
	{
		switch (wParam)
		{
		case VK_RETURN:
			if (title_menuSelect)
			{
				switch (title_choice)
				{
				case 0:
					ChangeScene(SN_opening);
					rove.Destroy();
					break;
				case 1:
					player.PlayerLoadFromFile();
					rove.Destroy();
					break;
				case 2:
					ChangeScene(SN_diary);
					break;
				}

			}
			else
				title_keydown = true;

			break;
		case VK_UP:
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
		case VK_DOWN:
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
		}
	}
	break;

	case SN_diary:
	{
		switch (wParam)
		{
		case VK_RETURN:
			ChangeScene(SN_title);
			break;
		case VK_UP:
			if (cursorPos == 0)
			{
				if (cursorLine == 0)
				{

				}
				else
				{
					cursorPos = 4;
					cursorLine--;
				}
			}
			else
			{
				cursorPos--;
			}
			break;
		case VK_DOWN:
			if (cursorPos == 4)
			{
				if (cursorLine == 5)
				{

				}
				else
				{
					cursorPos = 0;
					cursorLine++;
				}
			}
			else
			{
				cursorPos++;
			}
			break;
		case VK_LEFT:
			if (cursorLine > 0)
				cursorLine--;
			break;
		case VK_RIGHT:
			if (cursorLine < 5)
				cursorLine++;
			break;
		}

	}
	break;
	case SN_opening:
	{
		switch (wParam)
		{
		case VK_RETURN:
			tick = tick + 41;
			if (tick > 150 && open_storyNum == 0)
			{
				if (open_tutorial_choice)
					//ChangeScene();
					1;
				else
				{
					open_storyNum = 1;
					tick = 0; otick = 0;
				}
			}
			break;
		case VK_LEFT:
			if (open_storyNum == 0)
			{
				if (open_tutorial_choice)
					open_tutorial_choice = 0;
				else
					open_tutorial_choice = 1;
			}
			break;
		case VK_RIGHT:
			if (open_storyNum == 0)
			{
				if (open_tutorial_choice)
					open_tutorial_choice = 0;
				else
					open_tutorial_choice = 1;
			}
			break;
		}
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
		
		if (title_blink > 5)
		{
			title_textOn = true;
			

			if (title_choice == 0)
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 - 60, L">", lstrlen(L">"));
				SetTextColor(memDC, RGB(160, 160, 160));
				TextOut(memDC, clientRECT.right / 2 - 40, clientRECT.bottom / 2 + 40, L"계 속 하 기", lstrlen(L"계 속 하 기"));
				TextOut(memDC, clientRECT.right / 2 - 56, clientRECT.bottom / 2 + 210, L"여 행 의  기 록", lstrlen(L"여 행 의  기 록"));
				SetTextColor(memDC, RGB(0, 0, 0));
				TextOut(memDC, clientRECT.right / 2 - 80, clientRECT.bottom / 2 - 60, L"처 음 부 터  시 작 하 기", lstrlen(L"처 음 부 터  시 작 하 기"));
			}
			else if (title_choice == 1)
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 + 40, L">", lstrlen(L">"));
				SetTextColor(memDC, RGB(160, 160, 160));
				TextOut(memDC, clientRECT.right / 2 - 80, clientRECT.bottom / 2 - 60, L"처 음 부 터  시 작 하 기", lstrlen(L"처 음 부 터  시 작 하 기"));
				TextOut(memDC, clientRECT.right / 2 - 56, clientRECT.bottom / 2 + 210, L"여 행 의  기 록", lstrlen(L"여 행 의  기 록"));
				SetTextColor(memDC, RGB(0, 0, 0));
				TextOut(memDC, clientRECT.right / 2 - 40, clientRECT.bottom / 2 + 40, L"계 속 하 기", lstrlen(L"계 속 하 기"));
			}
			else
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 + 210, L">", lstrlen(L">"));
				SetTextColor(memDC, RGB(160, 160, 160));
				TextOut(memDC, clientRECT.right / 2 - 80, clientRECT.bottom / 2 - 60, L"처 음 부 터  시 작 하 기", lstrlen(L"처 음 부 터  시 작 하 기"));
				TextOut(memDC, clientRECT.right / 2 - 40, clientRECT.bottom / 2 + 40, L"계 속 하 기", lstrlen(L"계 속 하 기"));
				SetTextColor(memDC, RGB(0, 0, 0));
				TextOut(memDC, clientRECT.right / 2 - 56, clientRECT.bottom / 2 + 210, L"여 행 의  기 록", lstrlen(L"여 행 의  기 록"));
			}
		}
		else
		{
			if (title_choice)
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 + 40, L">", lstrlen(L">"));
				SetTextColor(memDC, RGB(160, 160, 160));
				TextOut(memDC, clientRECT.right / 2 - 80, clientRECT.bottom / 2 - 60, L"처 음 부 터  시 작 하 기", lstrlen(L"처 음 부 터  시 작 하 기"));
				SetTextColor(memDC, RGB(0, 0, 0));
				TextOut(memDC, clientRECT.right / 2 - 40, clientRECT.bottom / 2 + 40, L"계 속 하 기", lstrlen(L"계 속 하 기"));
			}
			else
			{
				TextOut(memDC, clientRECT.right / 2 - 110, clientRECT.bottom / 2 - 60, L">", lstrlen(L">"));
				SetTextColor(memDC, RGB(160, 160, 160));
				TextOut(memDC, clientRECT.right / 2 - 40, clientRECT.bottom / 2 + 40, L"계 속 하 기", lstrlen(L"계 속 하 기"));
				SetTextColor(memDC, RGB(0, 0, 0));
				TextOut(memDC, clientRECT.right / 2 - 80, clientRECT.bottom / 2 - 60, L"처 음 부 터  시 작 하 기", lstrlen(L"처 음 부 터  시 작 하 기"));
				
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
			}
		}
	}
}

void SceneManager::diary(HDC& memDC)
{
	MoveToEx(memDC, 0, 100, NULL);
	LineTo(memDC, clientRECT.right, 100);
	MoveToEx(memDC, clientRECT.right / 2 - 135, 0, NULL);
	LineTo(memDC, clientRECT.right / 2 - 135, 100);

	if (ending[cursorPos + cursorLine * 5])
	{
		fText(memDC, "Data\\Diary.txt", clientRECT.right / 2 - 285, 10, cursorPos + cursorLine * 5 + 1);
		fText(memDC, "Data\\Diary.txt", clientRECT.right / 2 - 130, 10, 25+(cursorPos + cursorLine * 5 + 1)*6,3);
	}
	else
	{
		TextOut(memDC, clientRECT.right / 2 - 285, 10, L"? ? ? ? ?", lstrlen(L"? ? ? ? ?"));
		fText(memDC, "Data\\Diary.txt", clientRECT.right / 2 - 130, 10, 25 + (cursorPos + cursorLine* 5 + 1) * 6 + 4);
	}

	for (int i = 0; i < 5; i++) // left
	{
		if (ending[i + (cursorLine / 2) * 10])
			fText(memDC, "Data\\Diary.txt", clientRECT.right / 2 - 220, 200 + 70 * i, i + (cursorLine / 2) * 10 + 1);
		else
			TextOut(memDC, clientRECT.right / 2 - 220, 200 + 70 * i, L"? ? ? ? ?", lstrlen(L"? ? ? ? ?"));
	}
	for (int i = 0; i < 5; i++) // right
	{
		if (ending[5 + i + (cursorLine / 2) * 10])
			fText(memDC, "Data\\Diary.txt", clientRECT.right / 2 + 50, 200 + 70 * i, 5 + i + (cursorLine / 2) * 10);
		else
			TextOut(memDC, clientRECT.right / 2 + 50, 200 + 70 * i, L"? ? ? ? ?", lstrlen(L"? ? ? ? ?"));
	}
	if (cursorLine % 2)
		TextOut(memDC, clientRECT.right / 2 + 40, 200 + 70 * cursorPos, L">", lstrlen(L">"));
	else
		TextOut(memDC, clientRECT.right / 2 - 230, 200 + 70 * cursorPos, L">", lstrlen(L">"));

	WCHAR page[6];
	wsprintf(page, L"%d / 3", cursorLine / 2 + 1);
	TextOut(memDC, clientRECT.right / 2 - 20, clientRECT.bottom - 30, page, lstrlen(page));
}

void SceneManager::opening(HDC& memDC)
{
	//스토리 텍스트
	SetTextAlign(memDC, TA_CENTER);


	switch (open_storyNum)
	{
	case 0:
		xText(memDC, "튜토리얼을  건너뛰시겠습니까?", clientRECT.right / 2, clientRECT.bottom / 2 - 80, 50, tick, otick).Out();

		xText(memDC, "예                      아니오", clientRECT.right / 2, clientRECT.bottom / 2 + 20, 90, tick, otick).Out();

		if (open_tutorial_choice == 0)
			xText(memDC,">", clientRECT.right / 2 + 20, clientRECT.bottom / 2 + 20, 130, tick,otick).Out();
		else
			xText(memDC, ">", clientRECT.right / 2 - 85, clientRECT.bottom / 2 + 20, 130, tick, otick).Out();
		break;
	case 1: // fade out
	{
		HBRUSH hBrush = CreateSolidBrush(RGB(255 - tick*5, 255 -tick*5, 255-tick*5));
		HBRUSH old = (HBRUSH)SelectObject(memDC, hBrush);

		Rectangle(memDC, 0, 0, clientRECT.right, clientRECT.bottom);
		SelectObject(memDC, old);
		DeleteObject(hBrush);

		if (tick * 5 > 254)
		{
			tick = otick = 0;
			open_storyNum = 2;
		}
	}
		break;
	case 2:
	{
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH old = (HBRUSH)SelectObject(memDC, hBrush);
		Rectangle(memDC, 0, 0, clientRECT.right, clientRECT.bottom);
		SelectObject(memDC, old);
		DeleteObject(hBrush);

		SetBkColor(memDC, RGB(0, 0, 0));
		//SetTextColor(memDC, RGB(255, 255, 255));

		//********************************************story**************************************************
		//for (int i = 0; i<25; i++)
			//fxText(memDC, "Data\\opening.txt", clientRECT.right / 2, clientRECT.bottom / 2 - 80, 1 + i * 5, 5, 100 + i * 200, 200, tick, otick,1);
		fxText(memDC, "Data\\opening.txt", clientRECT.right / 2, clientRECT.bottom / 2 - 80, 1, 5, 100, 200, tick, otick, 1);

		//********************************************story**************************************************
		if (tick > 400)
		{
			tick = 0;
			open_storyNum++;
		}
		break;
	}
	case 3: // fade in
	{
		HBRUSH hBrush = CreateSolidBrush(RGB(tick * 5, tick * 5, tick * 5));
		HBRUSH old = (HBRUSH)SelectObject(memDC, hBrush);

		Rectangle(memDC, 0, 0, clientRECT.right, clientRECT.bottom);
		SelectObject(memDC, old);
		DeleteObject(hBrush);

		if (tick * 5 > 254)
		{
			tick = otick = 0;
			open_storyNum = 4;			// 스토리 추가되면 바로 씬 변경으로
		}
		break;
	}

	case 4: // 랜덤배분
		player.stat.HP += rand() % 10;

		player.stat.passion =  rand() % 40 - 20;
		player.stat.endurence =  rand() % 40 - 20;
		player.stat.intelligent =  rand() % 40 - 20;
		player.stat.extroverted =  rand() % 40 - 20;

		player.stat.independent =  rand() % 40 - 20;
		player.stat.naive =  rand() % 40 - 20;
		player.stat.optimism =  rand() % 40 - 20;
		player.stat.resistance =  rand() % 40 - 20;

		break;
	}
	
	//랜덤 텍스트

	//
}
