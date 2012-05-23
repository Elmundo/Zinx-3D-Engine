#include "System\GameEngine.h"

//Static Direct3D object initialization
//irect3D* GameEngine::pDirect3D = 0;

//Static GameEngine object initialization
GameEngine* GameEngine::pGameEngine = NULL;
int GameEngine::endGame = 0;

//GameEngine objesini Ýlklendirmek için kullanýlýyo
GameEngine* GameEngine::getInstance(HINSTANCE hInstance){
	
	if(!pGameEngine)
		pGameEngine = new GameEngine(hInstance);
	
	return pGameEngine;
}

// Get game engine pointer
GameEngine* GameEngine::getGameEngine(){
	return pGameEngine;
}

bool GameEngine::loadModel(std::string modelName) {
	GameEngine::getGameEngine()->modelManager->loadModel(modelName);
	return true;
}
bool GameEngine::loadTexture(std::string textureName){
	GameEngine::getGameEngine()->textureManager->loadTexture(textureName);
	return true;
}
bool GameEngine::loadSprite(std::string spriteName){
	GameEngine::getGameEngine()->spriteManager->addChild(spriteName);
	return true;
}
bool GameEngine::addLight(LightEnum type, int x, int y, int z){
	//GameEngine::getGameEngine()->pDirect3D->light->addChild(type, x, y, z);
	return true;
}
bool GameEngine::addChild(Object* objectName){
	GameEngine::getGameEngine()->objectList->push_back(objectName);
	return true;
}
bool GameEngine::addChild(Object2D* objectName){
	GameEngine::getGameEngine()->spriteList->push_back(objectName);
	return true;
}
int GameEngine::getWidth(){
	return GameEngine::getGameEngine()->frameWnd->clientWidth;
}
int GameEngine::getHeight(){
	return GameEngine::getGameEngine()->frameWnd->clientHeight;
}

Camera* GameEngine::getCamera(){
	return GameEngine::getGameEngine()->camera;
}

bool GameEngine::getKeyboardState(KeyboardEnum keyboardState){
	return GameEngine::getGameEngine()->frameWnd->input->getKeyState(keyboardState);
}

POINT GameEngine::getMousePos(){
	return GameEngine::getGameEngine()->frameWnd->input->getMousePos();
}

float GameEngine::getMouseDx(){
	return GameEngine::getGameEngine()->frameWnd->input->getMouseDx();
}

float GameEngine::getMouseDy(){
	return GameEngine::getGameEngine()->frameWnd->input->getMouseDy();
}





