#pragma once
#ifndef LIGHT_H
#define LIGHT_H

#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
#include <windows.h>
#include "Light\LightEnum.h"
#include "Utility\Math.h"

class CHAOS_DLL Light{
public:
	//D3D Light Object
	D3DLIGHT9 m_Light;
	//ID of the light
	DWORD m_ObjectIndex;
	//D3D Device
	LPDIRECT3DDEVICE9 m_d3d;
	//Position light
	Math::vector3 m_Position;
	//Direction light
	Math::vector3 m_Direction;

	Light(LPDIRECT3DDEVICE9 pDirect3DDevice, Math::vector3 position, LightEnum lightType){
		
		m_Position = position;

		if(lightType == LIGHT_POINT)
			initPointLight();
		else if(lightType == LIGHT_DIRECTIONAL)
			initDirectionalLight();
		else if(lightType == LIGHT_SPOT)
			initSpotLight();
		//else if(lightType == LIGHT_SPECULAR)
			//initSpecularLight();
		
	}

	bool initPointLight();
	bool initDirectionalLight();
	//bool initSpecularLight();
	bool initSpotLight();
		
};

#endif