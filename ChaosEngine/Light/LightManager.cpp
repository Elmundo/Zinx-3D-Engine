#include "Light\LightManager.h"

//Init LightManager class's static object to zero
DWORD LightManager::m_StaticIndex = 0;

bool LightManager::enableLight(bool state, DWORD index){

	m_d3d->LightEnable(index, state);

	return true;
}

bool LightManager::addChild(LightEnum type, int x, int y, int z){

	Math::vector3 pos(x,y,z);
	m_Lights.push_back(Light(m_d3d, pos, LIGHT_POINT));

	m_d3d->SetLight(m_StaticIndex, &m_Lights[m_StaticIndex].m_Light);
	m_d3d->LightEnable(m_StaticIndex, true);

	m_StaticIndex++;

	return true;
}
