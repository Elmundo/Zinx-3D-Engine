#include "resource/Texture.h"

CHAOS_ENGINE_BEGIN

Texture::Texture(std::string textureName){
	// Construction method
	//name = textureName;
}

Texture::~Texture(){

}

void Texture::release(){
	
	texture->Release();
	Object::release();
}

CHAOS_ENGINE_END