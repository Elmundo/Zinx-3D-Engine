/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Window.h
Version:     v0.01
Description: Responsible for creating, managing window and windows message architecture

-------------------------------------------------------------------------
History:
- 04-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "Object/Object.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Window: public Object {

private:
	static Window* _instance;
	HWND _hwnd;
	std::string _windowClassName;
	FLOAT _width;
	FLOAT _height;

public:
	Window();
	virtual ~Window();

	bool create(LPCTSTR title, int w, int h);
	LRESULT CALLBACK windowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);
	HWND getHwnd();
	virtual void release();
	static Window* instance();
	void centerWindowPosition();

};

CHAOS_ENGINE_END

#endif