#pragma once

#ifndef GENERAL_METHODS
#define GENERAL_METHODS 

#include "System\GameEngine.h"
#include <iostream>
#include <string>

namespace GE{

	// General/Global Methods
	bool loadModel(std::string modelName);
	
	bool loadTexture(std::string textureName);

	bool loadSprite(std::string spriteName);
	
	bool addLight(LightEnum type, int x, int y, int z);
	
	bool addChild(Object* objectName);

	bool addChild(Object2D* objectName);

	int getWidth();

	int getHeight();

	//Camera methods
	Camera* getCamera();

	//Input methods
	bool getKeyboardState(KeyboardEnum keyboardState);
	POINT getMousePos();
	float getMouseDx();
	float getMouseDy();
}

#endif
