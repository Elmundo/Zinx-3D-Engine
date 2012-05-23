#include "Input\Input.h"

void Input::onKeyDown(WPARAM wParam){
	isKeyDown = true;
	
	switch(wParam){
	
	case VK_UP:
		keyboardBuffer[KeyboardEnum::UP] = true;
		return;
	case VK_LEFT:
		keyboardBuffer[KeyboardEnum::LEFT] = true;
		return;
	case VK_RIGHT:
		keyboardBuffer[KeyboardEnum::RIGHT] = true;
		return;
	case VK_DOWN:
		keyboardBuffer[KeyboardEnum::DOWN]= true;
		return;
	case 0x57:
		keyboardBuffer[KeyboardEnum::W] = true;
		return;
	case 0x53:
		keyboardBuffer[KeyboardEnum::S] = true;
		return;
	case 0x41:
		keyboardBuffer[KeyboardEnum::A] = true;
		return;
	case 0x44:
		keyboardBuffer[KeyboardEnum::D] = true;
		return;
	case 0x54:
		keyboardBuffer[KeyboardEnum::T] = true;
		return;
	case 0x59:
		keyboardBuffer[KeyboardEnum::Y] = true;
		return;
	}
}

void Input::onKeyUp(WPARAM wParam){
	isKeyDown = false;

	switch(wParam){

	case VK_UP:
		keyboardBuffer[KeyboardEnum::UP] = false;
		return;
	case VK_LEFT:
		keyboardBuffer[KeyboardEnum::LEFT] = false;
		return;
	case VK_RIGHT:
		keyboardBuffer[KeyboardEnum::RIGHT] = false;
		return;
	case VK_DOWN:
		keyboardBuffer[KeyboardEnum::DOWN]= false;
		return;
	case 0x57:
		keyboardBuffer[KeyboardEnum::W] = false;
		return;
	case 0x53:
		keyboardBuffer[KeyboardEnum::S] = false;
		return;
	case 0x41:
		keyboardBuffer[KeyboardEnum::A] = false;
		return;
	case 0x44:
		keyboardBuffer[KeyboardEnum::D] = false;
		return;
	case 0x54:
		keyboardBuffer[KeyboardEnum::T] = false;
		return;
	case 0x59:
		keyboardBuffer[KeyboardEnum::Y] = false;
		return;
	}
}

void Input::onMouseMove(POINT cursor){

	dx = cursor.x - mousePos.x;
	dy = cursor.y - mousePos.y;

	mousePos.x = cursor.x;
	mousePos.y = cursor.y;
}

POINT Input::getMousePos(){
	return mousePos;
}

float Input::getMouseDx(){
	float temp = dx;
	dx = 0;
	return(temp);
}

float Input::getMouseDy(){
	float temp = dy;
	dy = 0;
	return(temp);
}

bool Input::getKeyState(KeyboardEnum keyPressed){

	if(keyboardBuffer[keyPressed])
		return true;
	else
		return false;
}