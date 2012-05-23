#include "Display\Texture.h"

Texture::Texture(std::string textureName, LPDIRECT3DDEVICE9 d3d){
	//Assign the name of texture to m_textureName member.
	m_TextureName = textureName;
	m_d3d = d3d;

	//Create texture from file
	HRESULT hr = D3DXCreateTextureFromFileA(m_d3d, m_TextureName.c_str(), &m_Texture);
}

void Texture::draw(){
	m_d3d->SetTexture(0, m_Texture);
}

void Texture::release(){
	
	delete m_Texture;

	m_Texture = NULL;
	m_d3d     = NULL;
}