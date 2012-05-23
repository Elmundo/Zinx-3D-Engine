#ifndef INPUT_H
#define INPUT_H

#include <Windows.h>
#include "Input\InputEnum.h"

class CHAOS_DLL Input{
public:
	bool keyboardBuffer[256];
	bool mouseBuffer[256];

	bool isKeyDown;
	bool isMouseButtonDown;

	POINT mousePos;
	POINT prevMousePos;

	float dx;
	float dy;

	Input(){
	
		for(int i=0; i<256; ++i){
			keyboardBuffer[i] = false;
			mouseBuffer[i]    = false;
		}

		//temporary
		mousePos.x = 400;
		mousePos.y = 300;

		prevMousePos.x = 0;
		prevMousePos.y = 0;

		dx = 0;
		dy = 0;

		isKeyDown = false;
		isMouseButtonDown = false;
	}

	void onKeyDown(WPARAM wParam);
	void onKeyUp(WPARAM wParam);
	void onMouseMove(POINT cursor);
	POINT getMousePos();
	float getMouseDx();
	float getMouseDy();
	bool getKeyState(KeyboardEnum keyPressed);
};

#endif