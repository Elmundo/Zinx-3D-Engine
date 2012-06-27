#include "Input\InputManager.h"

CHAOS_ENGINE_BEGIN

InputManager* InputManager::_instance;

InputManager::InputManager(){

		for(int i=0; i<256; ++i){
			_keyboardBuffer[i] = false;
			_mouseBuffer[i]    = false;
		}

		//temporary
		_mousePos.x = 400;
		_mousePos.y = 300;

		_prevMousePos.x = 0;
		_prevMousePos.y = 0;

		_dx = 0;
		_dy = 0;

		_isKeyDown = false;
		_isMouseButtonDown = false;
}

void InputManager::onKeyDown(WPARAM wParam){
	_isKeyDown = true;
	
	switch(wParam){
	
	case VK_UP:
		_keyboardBuffer[KeyboardEnum::UP] = true;
		return;
	case VK_LEFT:
		_keyboardBuffer[KeyboardEnum::LEFT] = true;
		return;
	case VK_RIGHT:
		_keyboardBuffer[KeyboardEnum::RIGHT] = true;
		return;
	case VK_DOWN:
		_keyboardBuffer[KeyboardEnum::DOWN]= true;
		return;
	case 0x57:
		_keyboardBuffer[KeyboardEnum::W] = true;
		return;
	case 0x53:
		_keyboardBuffer[KeyboardEnum::S] = true;
		return;
	case 0x41:
		_keyboardBuffer[KeyboardEnum::A] = true;
		return;
	case 0x44:
		_keyboardBuffer[KeyboardEnum::D] = true;
		return;
	case 0x54:
		_keyboardBuffer[KeyboardEnum::T] = true;
		return;
	case 0x59:
		_keyboardBuffer[KeyboardEnum::Y] = true;
		return;
	}
}

void InputManager::onKeyUp(WPARAM wParam){
	_isKeyDown = false;

	switch(wParam){

	case VK_UP:
		_keyboardBuffer[KeyboardEnum::UP] = false;
		return;
	case VK_LEFT:
		_keyboardBuffer[KeyboardEnum::LEFT] = false;
		return;
	case VK_RIGHT:
		_keyboardBuffer[KeyboardEnum::RIGHT] = false;
		return;
	case VK_DOWN:
		_keyboardBuffer[KeyboardEnum::DOWN]= false;
		return;
	case 0x57:
		_keyboardBuffer[KeyboardEnum::W] = false;
		return;
	case 0x53:
		_keyboardBuffer[KeyboardEnum::S] = false;
		return;
	case 0x41:
		_keyboardBuffer[KeyboardEnum::A] = false;
		return;
	case 0x44:
		_keyboardBuffer[KeyboardEnum::D] = false;
		return;
	case 0x54:
		_keyboardBuffer[KeyboardEnum::T] = false;
		return;
	case 0x59:
		_keyboardBuffer[KeyboardEnum::Y] = false;
		return;
	}
}

void InputManager::onMouseMove(POINT cursor){

	_dx = cursor.x - _mousePos.x;
	_dy = cursor.y - _mousePos.y;

	_mousePos.x = cursor.x;
	_mousePos.y = cursor.y;
}

POINT InputManager::getMousePos(){
	return _mousePos;
}

float InputManager::getMouseDx(){
	float temp = _dx;
	_dx = 0;
	return(temp);
}

float InputManager::getMouseDy(){
	float temp = _dy;
	_dy = 0;
	return(temp);
}

bool InputManager::getKeyState(KeyboardEnum keyPressed){

	if(_keyboardBuffer[keyPressed])
		return true;
	else
		return false;
}

InputManager* InputManager::instance()
{
	if (!_instance)
		_instance = new InputManager();

	return _instance;
}

void InputManager::release()
{
	Object::release();
}


InputManager::~InputManager()
{

}

CHAOS_ENGINE_END