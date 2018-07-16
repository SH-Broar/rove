// rove.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "rove.h"
#include <time.h>
#include <atlimage.h>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	srand((unsigned int)time(NULL));

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ROVE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ROVE));

    MSG msg;

    // 기본 메시지 루프입니다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(WHITE_BRUSH);
    //wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ROVE);
	wcex.lpszMenuName	= NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_BORDER | WS_CAPTION | WS_SYSMENU,
      CW_USEDEFAULT, 0, 600, 600, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//


// 전역으로 사용하는 변수
int Scene;
int tick; int otick;
bool stop;
RECT clientRECT;
bool create;

//splash 씬에서 사용하는 변수
CImage Logo;
CImage rove;

int timeElasped()
{
	return (tick - otick) / 10;
}

void createScene()
{
	if (create == false)
	{
		switch (Scene)
		{
		case 0:
			stop = true;
			break;
		case 1:
			Logo.Destroy();
			tick = 0; otick = 0;
			break;
		}
		create = true;
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC totalDC;

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_CREATE:
		Logo.LoadFromResource(hInst, IDC_LOGO);
		rove.LoadFromResource(hInst, IDB_TITLE);
		GetClientRect(hWnd, &clientRECT);
		Scene = 0;
		tick = 0; otick = 0;
		stop = false;
		create = false;
		SetTimer(hWnd, 1, 10, NULL);
		break;
    case WM_PAINT:
        {
		PAINTSTRUCT ps;
		totalDC = BeginPaint(hWnd, &ps);
		HDC memDC = CreateCompatibleDC(totalDC);
		HBITMAP hBitmap = CreateCompatibleBitmap(totalDC,600,600);
		SelectObject(memDC, (HBITMAP)hBitmap);
		HDC alphaDC = CreateCompatibleDC(totalDC);
		HBITMAP alphaBitmap = CreateCompatibleBitmap(totalDC, 600, 600);
		SelectObject(alphaDC, (HBITMAP)alphaBitmap);
		
		Rectangle(memDC, -10, 0, 600, 600);
		Rectangle(alphaDC, -10, -10, 600, 600);

		//HBITMAP 
		switch (Scene)
		{
		case 0: // splash
			createScene();
			if (timeElasped() > 7 && timeElasped() < 15)
				Logo.AlphaBlend(memDC, clientRECT.right / 2 - Logo.GetWidth() / 2, clientRECT.bottom / 2 - Logo.GetHeight() / 2, (tick-70) * 3);
			if (timeElasped() >= 15 && timeElasped() < 25)
				Logo.Draw(memDC, clientRECT.right/2 - Logo.GetWidth() / 2, clientRECT.bottom / 2 - Logo.GetHeight() / 2);
			if (timeElasped() >= 25 && timeElasped() < 33)
				Logo.AlphaBlend(memDC, clientRECT.right / 2 - Logo.GetWidth() / 2, clientRECT.bottom / 2 - Logo.GetHeight() / 2, 255 - (tick - 250) * 3);

			if (timeElasped() >= 40 && timeElasped() < 48)
				rove.AlphaBlend(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2,(tick-400) * 3);

			else if (timeElasped() >= 48)
			{
				rove.Draw(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2-(timeElasped()-48)*4);

				if (timeElasped() > 55)
				{
					Scene = 1;
					create = false;
				}
			}
			
			break;
		case 1: // title
			createScene();
			
			if ((tick - otick) * 20 < 255)
			{
				rove.AlphaBlend(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2 - 32, (tick - otick) * 20);
			}
			else //처음 들어올 때 효과음
			{
				rove.Draw(memDC, clientRECT.right / 2 - rove.GetWidth() / 2, clientRECT.bottom / 2 - rove.GetHeight() / 2 - 32);
				if ((timeElasped()/3)%2 == 1)
				TextOut(memDC, 210, 500, L"P r e s s   k e y   t o   S t a r t", lstrlen(L"P r e s s   k e y   t o   S t a r t"));
			}
			break;
		}
		
		BitBlt(totalDC, 0, 0, 600, 600, memDC, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
        }
        break;
	case WM_TIMER:
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
			
			InvalidateRect(hWnd, NULL, false);
		}
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
			switch (Scene)
			{
			case 0:
				Scene = 1;
				create = false;
				break;
			}
		}
		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
