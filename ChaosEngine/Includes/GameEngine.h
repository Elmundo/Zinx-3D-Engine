/*******************************************/
/*                                         */
/*  Game Engine Modified - 06.02.2011      */
/*                                         */
/*******************************************/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <Windows.h>
#include "System\Direct3D.h"
#include "System\FrameWnd.h"

#include "Object\Object.h"
#include "Object\Object2D.h"

#include "Light\LightManager.h"
#include "Display\ModelManager.h"
#include "Display\TextureManager.h"
#include "Display\SpriteManager.h"
#include "Renderer\Renderer.h"
#include "Utility\Macros.h"

#include "Log\Log.h"

#define WIDTH 800
#define HEIGHT 600

class __declspec(dllexport) GameEngine{
private:
	//For Singleton Pattern
	static GameEngine *pGameEngine;
	bool gamePause;
	/*GameEngine classýnýn içerisinde ciddi bir temizleme ve anlaþýlabilir kod düzenlemesi yap*/
	
	GameEngine(HINSTANCE hInstance): gamePause(false)
	{
		msg = new MSG;
		PFGameLoop = NULL;
		
		frameWnd  = new FrameWnd(hInstance, 600, 800);
		pDirect3D = new Direct3D(hInstance, frameWnd);
		camera    = new Camera(pDirect3D->pDirect3DDevice);

		objectList     = new std::vector<Object*>;
		spriteList     = new std::vector<Object2D*>;
		textureManager = new TextureManager(pDirect3D->pDirect3DDevice);
		modelManager   = new ModelManager(&textureManager->m_Textures, objectList, pDirect3D->pDirect3DDevice);
		spriteManager  = new SpriteManager(spriteList, pDirect3D->_spriteDevice, pDirect3D->pDirect3DDevice);

		renderer = new Renderer(modelManager, spriteManager, textureManager, objectList, spriteList, pDirect3D->pDirect3DDevice, pDirect3D->_spriteDevice);

		pDirect3D->modelManager = modelManager;
		pDirect3D->spriteMananger = spriteManager;
		pDirect3D->renderer = renderer;

		Log::instance()->debug(ClassHelper::getClassName(this), "GameEngine()", "SimpleEngine v0.1");
	}

public:
	//Temporary
	static int endGame;

	HWND hWnd;
	MSG* msg;
	/**********************************************/
	//WndProc da okunabilmesi icin böyle yazdým
	//Deðiþebilir static olma durumu
	Direct3D* pDirect3D;
	FrameWnd* frameWnd;
	Camera* camera;
	//ModelManager
	ModelManager* modelManager;
	//TextueManager
	TextureManager* textureManager;
	//SpriteManager
	SpriteManager* spriteManager;
	//FXManager

	//RENDERER
	Renderer* renderer;

	//List that hold the game object list
	//Make this objectManager
	std::vector<Object*>* objectList;
	std::vector<Object2D*>* spriteList;

	void (*PFGameLoop)(GameEngine* pGameEngine);
	/***********************************************/
	//Bu fonksiyonlar Direct3D sýnýfýnýn içerisine de koyulabilir
	int SystemLoop();
	//Getter
	static GameEngine* getInstance(HINSTANCE hInstance);
	static GameEngine* getGameEngine();
	// Use to pause the game application
};
	
#endif