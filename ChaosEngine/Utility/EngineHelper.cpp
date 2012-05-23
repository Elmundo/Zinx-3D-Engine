#include "Utility\EngineHelper.h"

// General/Global Methods
bool EngineHelper::loadModel(std::string modelName) {
	GameEngine::getGameEngine()->modelManager->loadModel(modelName);
	return true;
}
bool EngineHelper::loadTexture(std::string textureName){
	GameEngine::getGameEngine()->textureManager->loadTexture(textureName);
	return true;
}
bool EngineHelper::loadSprite(std::string spriteName){
	GameEngine::getGameEngine()->spriteManager->addChild(spriteName);
	return true;
}
bool EngineHelper::addLight(LightEnum type, int x, int y, int z){
	GameEngine::getGameEngine()->pDirect3D->lightManager->addChild(type, x, y, z);
	return true;
}
bool EngineHelper::addChild(Object* objectName){
	GameEngine::getGameEngine()->objectList->push_back(objectName);
	return true;
}
bool EngineHelper::addChild(Object2D* objectName){
	GameEngine::getGameEngine()->spriteList->push_back(objectName);
	return true;
}
int EngineHelper::getWidth(){
	return GameEngine::getGameEngine()->frameWnd->clientWidth;
}
int EngineHelper::getHeight(){
	return GameEngine::getGameEngine()->frameWnd->clientHeight;
}

Camera* EngineHelper::getCamera(){
	return GameEngine::getGameEngine()->camera;
}

bool EngineHelper::getKeyboardState(KeyboardEnum keyboardState){
	return GameEngine::getGameEngine()->frameWnd->input->getKeyState(keyboardState);
}

POINT EngineHelper::getMousePos(){
	return GameEngine::getGameEngine()->frameWnd->input->getMousePos();
}
	
float EngineHelper::getMouseDx(){
	return GameEngine::getGameEngine()->frameWnd->input->getMouseDx();
}

float EngineHelper::getMouseDy(){
	return GameEngine::getGameEngine()->frameWnd->input->getMouseDy();
}

LPD3DXSPRITE EngineHelper::getSpriteDevice(){
	return GameEngine::getGameEngine()->pDirect3D->_spriteDevice;
}

LPDIRECT3DDEVICE9 EngineHelper::getD3DDevice(){
	return GameEngine::getGameEngine()->pDirect3D->pDirect3DDevice;
}