#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include <iostream>

class __declspec(dllexport) Texture{
public:
	//FUNDAMENTAL MEMBERS
	//The texture buffer
	LPDIRECT3DTEXTURE9 m_Texture;

	//Name of the texture
	std::string m_TextureName;

	//OBJECTS ARE IMPORTED FROM OUTSIDE
	//Direct3D Device
	LPDIRECT3DDEVICE9 m_d3d;

	//METHODS
	Texture(std::string textureName, LPDIRECT3DDEVICE9 d3d);
	void draw();
	void release();
};

#endif