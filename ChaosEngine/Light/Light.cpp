#include "Light\Light.h"
#include "Light\LightManager.h"

bool Light::initPointLight(){

	D3DXCOLOR color(0.9,2,2,1);
	
	::ZeroMemory(&m_Light, sizeof(m_Light));

	m_Light.Type      = D3DLIGHT_POINT;
	
	m_Light.Ambient   = color * 0.3f;
	m_Light.Diffuse   = color * 2.0f;
	m_Light.Specular  = color * 1.0f;
	
	m_Light.Position  = m_Position;
	m_Light.Range        = 1000.0f;
	m_Light.Falloff      = 0.2f;
	m_Light.Attenuation0 = 1.0f;
	m_Light.Attenuation1 = 0.0f;
	m_Light.Attenuation2 = 0.0f;

	m_ObjectIndex = LightManager::m_StaticIndex;

	return true;
}

bool Light::initDirectionalLight(){

	D3DXCOLOR color(0.9,2,2,1);
	Math::vector3 direction(0.0f, -0.707f, 0.707f);

	::ZeroMemory(&m_Light, sizeof(m_Light));

	m_Light.Type      = D3DLIGHT_DIRECTIONAL;

	m_Light.Ambient   = color * 0.4f;
	m_Light.Diffuse   = color;
	m_Light.Specular  = color * 0.6f;
	m_Light.Direction = direction;
	
	m_Light.Direction = direction;
	m_Light.Range        = 500.0f;
	m_Light.Falloff      = 1.0f;
	m_Light.Attenuation0 = 1.0f;
	m_Light.Attenuation1 = 0.0f;
	m_Light.Attenuation2 = 0.0f;
	
	m_Light.Theta        = 0.5f;
	m_Light.Phi          = 0.7f;

	m_ObjectIndex = LightManager::m_StaticIndex;

	return true;
}

bool Light::initSpotLight(){

	D3DXCOLOR color(0.9,2,2,1);
	Math::vector3 direction(0.0f, 0.0f, 1.0f);

	::ZeroMemory(&m_Light, sizeof(m_Light));

	m_Light.Type      = D3DLIGHT_SPOT;
	
	m_Light.Ambient   = color * 0.4f;
	m_Light.Diffuse   = color;
	m_Light.Specular  = color * 0.6f;
	
	m_Light.Position  = m_Position;
	m_Light.Direction = direction;
	m_Light.Range        = 500.0f;
	m_Light.Falloff      = 1.0f;
	m_Light.Attenuation0 = 1.0f;
	m_Light.Attenuation1 = 0.0f;
	m_Light.Attenuation2 = 0.0f;
	m_Light.Theta        = 0.5f;
	m_Light.Phi          = 0.7f;

	m_ObjectIndex = LightManager::m_StaticIndex;

	return true;
}