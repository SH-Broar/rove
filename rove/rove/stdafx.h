// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <atlimage.h>
#include <iostream>
#include <fstream>
#include <string>

//
                                // ���� �ν��Ͻ��Դϴ�.

#define TOTAL_ENDING_NUMBER 30
enum SceneNumber{SN_splash,SN_title,SN_opening,SN_diary};


//

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#ifdef _DEBUG
#ifdef UNICODE

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#endif

#endif