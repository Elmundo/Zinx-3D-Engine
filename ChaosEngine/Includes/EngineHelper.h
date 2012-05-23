#ifndef ENGINE_HELPER_H
#define ENGINE_HELPER_H

#include "System\GameEngine.h"
#include <iostream>
#include <string>

class __declspec(dllexport) EngineHelper {
public:
	EngineHelper(){
		// some stuff
	}

	~EngineHelper(){
		// some stuff
	}

	static EngineHelper* getInstance();

	// General/Global Methods
	static bool loadModel(std::string modelName);
	
	static bool loadTexture(std::string textureName);

	static bool loadSprite(std::string spriteName);
	
	static bool addLight(LightEnum type, int x, int y, int z);
	
	static bool addChild(Object* objectName);

	static bool addChild(Object2D* objectName);

	static int getWidth();

	static int getHeight();

	//Camera methods
	static Camera* getCamera();

	//Input methods
	static bool getKeyboardState(KeyboardEnum keyboardState);
	
	static POINT getMousePos();
	
	static float getMouseDx();
	
	static float getMouseDy();

	static LPD3DXSPRITE getSpriteDevice();
	
	static LPDIRECT3DDEVICE9 getD3DDevice();
};

#endif