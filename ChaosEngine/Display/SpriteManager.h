#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <d3dx9.h>
#include <d3d9.h>
#include <iostream>
#include <vector>
#include "Display\Sprite.h"
#include "Object\Object2D.h"

class CHAOS_DLL SpriteManager{
	
public:
	
	//FUNDAMENTAL
	std::vector<Sprite> _Sprites;
	
	LPD3DXSPRITE _SpriteDevice;
	LPDIRECT3DDEVICE9 _d3d; //OUTSIDE

	//OUTSIDE
	std::vector<Object2D*> *_spriteList;

	//Metots
	SpriteManager(std::vector<Object2D*> *spriteList, LPD3DXSPRITE spriteDevice, LPDIRECT3DDEVICE9 d3d);

	void draw();
	bool addChild(std::string spriteName);
	bool removeChild(std::string spriteName);
};

#endif