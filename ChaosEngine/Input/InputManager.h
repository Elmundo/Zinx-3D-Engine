/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Input.h
Version:     v0.01
Description: Responsible for creating, managing window and windows message architecture

-------------------------------------------------------------------------
History:
- 04-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Object/Object.h"
#include "Input/InputEnum.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL InputManager: Object{
private:
	static InputManager* _instance;

	bool _keyboardBuffer[256];
	bool _mouseBuffer[256];

	bool _isKeyDown;
	bool _isMouseButtonDown;

	POINT _mousePos;
	POINT _prevMousePos;

	float _dx;
	float _dy;
public:
	InputManager();
	virtual ~InputManager();

	static InputManager* instance();
	void onKeyDown(WPARAM wParam);
	void onKeyUp(WPARAM wParam);
	void onMouseMove(POINT cursor);
	POINT getMousePos();
	float getMouseDx();
	float getMouseDy();
	bool getKeyState(KeyboardEnum keyPressed);
	
	virtual void release();
};

CHAOS_ENGINE_END

#endif