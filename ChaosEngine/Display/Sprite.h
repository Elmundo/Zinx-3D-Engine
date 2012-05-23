#ifndef SPRITE_H
#define SPRITE_H

#include <d3dx9.h>
#include <d3d9.h>
#include <iostream>
#include "Utility\Math.h"
#include <Utility\Macros.h>

//#include "Direct3D.h"

#pragma once

class CHAOS_DLL Sprite{
public:
	LPDIRECT3DTEXTURE9 _Texture;
	RECT _SpriteRect;
	std::string _SpriteName;
	D3DXIMAGE_INFO _ImageInfo;

	//OBJECTS ARE IMPORTED FROM OUTSIDE
	//Direct3D Device
	LPDIRECT3DDEVICE9 _d3d;

	//METHODS
	Sprite(LPDIRECT3DDEVICE9 d3d, std::string stringName);
	void release();
};

#endif

