#define _CRT_SECURE_NO_WARINGS 1
#include "initialisation.h"
#include "check.h"
#include "draw.h"
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <easyx.h>

int main()
{
	char arr[3][3];
	char current = 'X';
	initialisation(arr);
	ExMessage msg;
	bool running = true;
	while (running)
	{
		DWORD start = GetTickCount();
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				int x = msg.x;
				int y = msg.y;
				int ix = x / 200;
				int iy = y / 200;
				if (arr[ix][iy] == '#')
				{
					arr[ix][iy] = current;
				}
				if (current == 'X')
				{
					current = 'O';
				}
				else
				{
					current = 'X';
				}
			}
		}
		HWND hwn = GetHWnd();
		char ar[10] = { current };
		SetWindowText(hwn, ar);
		cleardevice();
		drawboard();
		drawpiece(arr);
		if (checkwin(arr) == 'X')
		{
			MessageBox(GetHWnd(), _T("X win"), _T("GG"), MB_OK);
			running = false;
		}
		if (checkwin(arr) == 'O')
		{
			MessageBox(GetHWnd(), _T("O win"), _T("GG"), MB_OK);
			running = false;
		}
		else if (checkwin(arr) == '1')
		{
			MessageBox(GetHWnd(), _T("a draw"), _T("GG"), MB_OK);
			running = false;
		}
		FlushBatchDraw();
		DWORD over = GetTickCount();
		if ((over - start) < 1000/60)
		{
			Sleep(1000 / 60 - (over - start));
		}
	}
	EndBatchDraw();
	return 0;
}








////////////////////////////////////////////////////////////////////
//                          _ooOoo_                               //
//                         o8888888o                              //
//                         88" . "88                              //
//                         (| ^_^ |)                              //
//                         O\  =  /O                              //
//                      ____/`---'\____                           //
//                    .'  \\|     |//  `.                         //
//                   /  \\|||  :  |||//  \                        //
//                  /  _||||| -:- |||||-  \                       //
//                  |   | \\\  -  /// |   |                       //
//                  | \_|  ''\---/''  |   |                       //
//                  \  .-\__  `-`  ___/-. /                       //
//                ___`. .'  /--.--\  `. . ___                     //
//              ."" '<  `.___\_<|>_/___.'  >'"".                  //
//            | | :  `- \`.;`\ _ /`;.`/ - ` : | |                 //
//            \  \ `-.   \_ __\ /__ _/   .-` /  /                 //
//      ========`-.____`-.___\_____/___.-`____.-'========         //
//                           `=---='                              //
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        //
//         佛祖保佑       永无BUG     永不修改                      //
////////////////////////////////////////////////////////////////////