#include "Display\TextureManager.h"

bool TextureManager::loadTexture(std::string textureName){

	m_Textures.push_back(Texture(textureName, m_d3d));
	return true;
}

bool TextureManager::removeTexture(std::string textureName){

	std::vector<Texture>::iterator i;

	for(i = m_Textures.begin(); i < m_Textures.end(); ++i){
		if(!(i->m_TextureName.compare(textureName.c_str())) ){
			//i->release(); Arýzalý!!
			m_Textures.erase(i);
			break;
		}
	}

	return true;
}

	