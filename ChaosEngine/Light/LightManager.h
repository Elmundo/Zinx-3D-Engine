#pragma once
#ifndef LIGHT_MANAGER_H
#define LIGHT_MANAGER_H

#include <vector>
#include <iostream>
#include "Light\Light.h"

class CHAOS_DLL LightManager{
public:
	std::vector<Light> m_Lights;
	LPDIRECT3DDEVICE9 m_d3d;
	static DWORD m_StaticIndex;

	LightManager(LPDIRECT3DDEVICE9 d3d):m_d3d(d3d){}

	//Metots
	bool enableLight(bool state, DWORD index);
	bool addChild(Light light);//Bu henüz implement edilmedi
	bool addChild(LightEnum type, int x, int y, int z);

};

#endif