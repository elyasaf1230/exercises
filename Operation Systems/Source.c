#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>

//callback function for the window.
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
	//for 3:
	PCWSTR buffer[256];

	/******************************** windows class *****************************/
	//initialization
	WNDCLASS wc = { 0 };
	
	//we have no specific style
	wc.style = 0;

	//handle function
	wc.lpfnWndProc = WndProc;

	//we don't need any extra bytes
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	//we will use black background
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	//we will the default curser icon
	wc.hCursor = LoadCursor(NULL, IDC_APPSTARTING);

	//setting the name of the class
	wc.lpszClassName = TEXT("Boring Window Class");

	//menu? not for us! 
	wc.lpszMenuName = NULL;

	// hInstance from WinMain
	wc.hInstance = hInstance;

	//register the class
	RegisterClass(&wc);
	/************************************* end ***********************************/

	/******************************** create window ******************************/
	HWND hWnd = CreateWindow(
		/*the class*/
		TEXT("Boring Window Class"),

		/*the name of the window*/
		TEXT("Boring Window"),

		/*normal style*/
		WS_OVERLAPPEDWINDOW,

		/*position of the window*/
		0, 0,

		/*size of the window*/
		500, 250,

		/*there is no parent, it is the first and only (Adam)*/
		NULL,

		/*there is now menu*/
		NULL,

		/*instance*/
		hInstance,

		/*parameter to pass on creation*/
		NULL
		);
	/************************************ end ************************************/

	//showing the new windows.
	ShowWindow(hWnd, nCmdShow);

	//part3:
	GetWindowsDirectory(buffer, 256);
	MessageBox(hWnd, buffer, TEXT("Malicious Info"), MB_OK);

	MSG msg;

	//looooooop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//for part 1:
	static UINT count = 0;
	wchar_t buffer[256];

	//for part 2:
	HANDLE WINAPI hFile;
	DWORD bytesWritten;
	SYSTEMTIME lt;

	switch (msg)
	{
//part 1:
		//when pressing the right button - count up
	case WM_RBUTTONDOWN:
		++count;
		return 0;
		//when pressing the left button - changing the title of the window
	case WM_LBUTTONDOWN:
		wsprintfW(buffer, L"%d", count);
		SetWindowText(hWnd, buffer);
		return 0;
//part 2:
	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
		{
			//get current time: 
			GetLocalTime(&lt);

			//set the buffer to write:
			sprintf(buffer, "%d:%d:%d %d/%d/%d", lt.wHour, lt.wMinute, lt.wSecond, lt.wDay, lt.wMonth, lt.wYear);

			//openning file
			hFile = CreateFile(
				/*File Name*/
				TEXT(".\myDate.log"),

				/*open for writing*/
				GENERIC_WRITE,

				/*no share modes*/
				0,

				/*no security, we are the kings of security!*/
				NULL,

				/*don't care about old data, just open file and write to it*/
				CREATE_ALWAYS,

				/*we don't want the file to feel spacial...*/
				0,

				/*"This parameter can be NULL" (msdn 2017)*/
				NULL
				);

			//check if the handle is valid
			if (hFile == INVALID_HANDLE_VALUE)
				return 0; //and cry :(

			//writing to the file:
			WriteFile(hFile, buffer, strlen(buffer), &bytesWritten, NULL);

			//closing the file
			CloseHandle(hFile);

		}

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
	
}