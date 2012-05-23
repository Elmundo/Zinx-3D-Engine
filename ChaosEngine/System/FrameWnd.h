#pragma once

#ifndef FRAMEWND_H
#define FRAMEWND_H

#include <Windows.h>
#include <iostream>
#include "Input\Input.h"


class CHAOS_DLL FrameWnd{
public:
	int clientWidth;
	int clientHeight;
	bool fullScreen;
	Input* input;

	//Creating the windows
	WNDCLASSEX wndclass;
	HWND hWnd;

	FrameWnd(HINSTANCE hInstance, int height, int width){
		//Init the window
		initWindow(hInstance, height, width);

		input = new Input();
	}

	virtual ~FrameWnd(){};
	
	HWND initWindow(HINSTANCE hInstance, int height, int width);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);
};


#endif

