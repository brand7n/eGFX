// eGFX_Test.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "eGFX_Test.h"
#include "stdint.h"

#include "eGFX.h"
#include "eGFX_Driver_Win32.h"
#include <strsafe.h>

#define MAX_LOADSTRING 100

extern void eGFX_TestDrawLoop(uint32_t Mode);
extern void eGFX_InitTestDrawLoop(uint32_t Mode);

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_EGFX_TEST, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EGFX_TEST));
	
	eGFX_InitDriver();

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EGFX_TEST));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = NULL;// MAKEINTRESOURCE(IDC_EGFX_TEST);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

 
   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//


HBRUSH BlackBrush;
HBRUSH PixelOffBrush;
HBRUSH PixelBrush[256];

 RECT clientRect;
 RECT PixelRect;


 float BorderWidth = 10;

 float PixelFill = 0.9f;// fraction of a cell filled with color
 
 float PixelSizeX = 3;// fraction of a cell filled with color
 float PixelSizeY = 3;// fraction of a cell filled with color
 
 float SimulatedDisplayWidth;
 int32_t SimulatedDisplayHeight;

 float StartX;
 float StartY;

 HDC bufDC;
 HBITMAP bufBMP;
 int32_t BackBufferWidth;
 int32_t BackBufferHeight;
 uint32_t DrawTestMode = 0;
 TCHAR TitleBarBuffer[512];
 LPCTSTR pszFormat = TEXT("Draw Test Mode: %d");

 eGFX_PixelState PS = 0;

#define MY_TIMER_1 0


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	int32_t x,y;
	// vars
	
	int32_t i;
	

	switch (message)
	{
		
	case WM_KEYUP:
		switch (wParam)
		{
		case VK_UP:
			
			DrawTestMode++;
			DrawTestMode&=0x1F;
			eGFX_InitTestDrawLoop(DrawTestMode);
			InvalidateRect(hWnd, NULL, TRUE);
			break;

		case VK_DOWN:

			DrawTestMode--;
			DrawTestMode &= 0x1F;
			eGFX_InitTestDrawLoop(DrawTestMode);
			InvalidateRect(hWnd, NULL, TRUE);
			break;

	
		case 0x31:
			PixelFill = 1.0f;// fraction of a cell filled with color
			PixelSizeX = wParam - 0x30;
			PixelSizeY = wParam - 0x30;
			break;
		case 0x32:

			PixelFill = 1.0f;// fraction of a cell filled with color
			PixelSizeX = wParam - 0x30;
			PixelSizeY = wParam - 0x30;
			break;
		case 0x33:
		case 0x34:
		case 0x35:
		case 0x36:
			PixelFill = 0.9f;// fraction of a cell filled with color
			PixelSizeX = wParam - 0x30;
			PixelSizeY = wParam - 0x30;
			break;

		}
		break;


	case WM_CREATE:

		BlackBrush = CreateSolidBrush(RGB(0,0,0));
		
		for(i=0;i<256;i++)
		{
			PixelBrush[i] = CreateSolidBrush(RGB(0,i,0));
		}

		PixelOffBrush = CreateSolidBrush(RGB(20, 20, 20));

		SetTimer(hWnd,             // handle to main window 
				MY_TIMER_1,            // timer identifier 
				100,                 // 100msecond interval 
				(TIMERPROC) NULL);     // no timer callback 

		break;
	
		case WM_TIMER: 
 
		switch (wParam) 
		{ 
			case MY_TIMER_1: 
					eGFX_TestDrawLoop(DrawTestMode);
					InvalidateRect(hWnd, NULL, TRUE); 
				 return 0; 
 
			default:
				break;
		} 
		break;

	
	case WM_ERASEBKGND:
		//Magic Code from http://www.catch22.net/tuts/flicker-free-drawing
		return 1;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
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
		break;

	case WM_PAINT:
		
	    StringCbPrintf(TitleBarBuffer, 256 * sizeof(TCHAR), pszFormat, DrawTestMode);
		
		SetWindowText(hWnd, TitleBarBuffer);

		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		
	    BackBufferWidth = clientRect.right - clientRect.left;
		BackBufferHeight = clientRect.bottom - clientRect.top;

		bufDC = CreateCompatibleDC(hdc);
		bufBMP = CreateCompatibleBitmap(hdc, BackBufferWidth, BackBufferHeight);
		SelectObject(bufDC, bufBMP);

		
		SimulatedDisplayWidth  = clientRect.right - clientRect.left - (2 * BorderWidth);
		SimulatedDisplayHeight = clientRect.bottom - clientRect.top - (2 * BorderWidth);
	//	PixelSizeX = (SimulatedDisplayWidth / (float)eGFX_BackBuffer.SizeX);
		//PixelSizeY = (SimulatedDisplayHeight / (float)eGFX_BackBuffer.SizeY);

		//PixelSizeX = 6;// (SimulatedDisplayWidth / (float)eGFX_BackBuffer.SizeX);
	//	PixelSizeY = 6;// (SimulatedDisplayHeight / (float)eGFX_BackBuffer.SizeY);

		BitBlt(bufDC, 0, 0, BackBufferWidth, BackBufferHeight, NULL, 0, 0, BLACKNESS);

		 //Here is out GFX_Dump
			

			for(y=0;y<eGFX_BackBuffer.SizeY;y++)
			{
				for (x = 0; x<eGFX_BackBuffer.SizeX; x++)
				{
					
					switch (eGFX_BackBuffer.Type)
					{
						case eGFX_IMAGE_PLANE_1BPP:

							PixelRect.left = (int32_t)(((float)clientRect.left + (float)BorderWidth + (x * PixelSizeX)));
							PixelRect.top = (int32_t)(((float)clientRect.top + (float)BorderWidth + (y * PixelSizeY)));

							PixelRect.right = (int32_t)(((float)PixelRect.left + (PixelSizeX * PixelFill)));
							PixelRect.bottom = (int32_t)(((float)PixelRect.top + (PixelSizeY * PixelFill)));
							
							if (eGFX_GetPixel(&eGFX_BackBuffer, x, y) > 0)
								FillRect(bufDC, &PixelRect, PixelBrush[0xFF]);
							else
								FillRect(bufDC, &PixelRect, PixelOffBrush);

							break;


						case eGFX_IMAGE_PLANE_4BPP:

							PixelRect.left = (int32_t)(((float)clientRect.left + (float)BorderWidth + (x * PixelSizeX)));
							PixelRect.top = (int32_t)(((float)clientRect.top + (float)BorderWidth + (y * PixelSizeY)));

							PixelRect.right = (int32_t)(((float)PixelRect.left + (PixelSizeX * PixelFill)));
							PixelRect.bottom = (int32_t)(((float)PixelRect.top + (PixelSizeY * PixelFill)));
							
							PS = (eGFX_GetPixel(&eGFX_BackBuffer, x, y));
							if (PS > 0)
								FillRect(bufDC, &PixelRect, PixelBrush[(PS&0xF)<<4]);
							else
								FillRect(bufDC, &PixelRect, PixelOffBrush);

							break;

						case eGFX_IMAGE_PLANE_8BPP:

							PixelRect.left = (int32_t)(((float)clientRect.left + (float)BorderWidth + (x * PixelSizeX)));
							PixelRect.top = (int32_t)(((float)clientRect.top + (float)BorderWidth + (y * PixelSizeY)));

							PixelRect.right = (int32_t)(((float)PixelRect.left + (PixelSizeX * PixelFill)));
							PixelRect.bottom = (int32_t)(((float)PixelRect.top + (PixelSizeY * PixelFill)));

							PS = (eGFX_GetPixel(&eGFX_BackBuffer, x, y));
							if (PS > 0)
								FillRect(bufDC, &PixelRect, PixelBrush[(PS & 0xFF)]);
							else
								FillRect(bufDC, &PixelRect, PixelOffBrush);

							break;


						default:
							break;
					}
					

					}
					
			}
	

	 // present the buffer
	     BitBlt(hdc, 0, 0, BackBufferWidth, BackBufferHeight, bufDC, 0, 0, SRCCOPY);

		DeleteDC(bufDC);
		DeleteObject(bufBMP);  

		EndPaint(hWnd, &ps);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		DeleteObject(BlackBrush);
		DeleteObject(PixelBrush);
		for(i=0;i<256;i++)
			DeleteObject(PixelBrush[i]);

		DeleteObject(PixelOffBrush);

		KillTimer(hWnd, MY_TIMER_1); 
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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

