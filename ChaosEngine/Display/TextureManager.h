#pragma once

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <d3d9.h>
#include <string>
#include <iostream>
#include <vector>
#include <Display\Texture.h>

class CHAOS_DLL TextureManager{
public:
	//FUNDAMENTAL MEMBERS
	std::vector<Texture> m_Textures;
	
	//OUTSIDE MEMBERS OR DEPENDENT OBJECTS from Direct3D Class
	LPDIRECT3DDEVICE9 m_d3d;
	
	TextureManager(LPDIRECT3DDEVICE9 d3d):m_d3d(d3d){}

	//METHOTS
	bool loadTexture(std::string textureName);
	bool removeTexture(std::string textureName);
};

#endif 