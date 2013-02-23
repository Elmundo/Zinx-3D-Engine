/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Texture.h
Version:     v0.01
Description: 

-------------------------------------------------------------------------
History:
- 20-08-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "Core/Renderer.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Texture: public Object{
public:
	LPDIRECT3DTEXTURE9 texture;
	std::string name;
	
	Texture(std::string name);
	virtual ~Texture();

	virtual void release();
};

CHAOS_ENGINE_END

#endif