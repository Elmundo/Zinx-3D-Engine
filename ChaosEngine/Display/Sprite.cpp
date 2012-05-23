#include "Display\Sprite.h"

//Get the Sprite
Sprite::Sprite(LPDIRECT3DDEVICE9 d3d, std::string stringName){
	
	_d3d        = d3d;
	_SpriteName = stringName;

	D3DXGetImageInfoFromFile(_SpriteName.c_str(), &_ImageInfo);
	D3DXCreateTextureFromFile(_d3d, _SpriteName.c_str(), &_Texture);
	
	_SpriteRect.left   = 0;
	_SpriteRect.top    = 0;
	_SpriteRect.bottom = _ImageInfo.Height;
	_SpriteRect.right  = _ImageInfo.Width;

}

void Sprite::release(){
	//TODO
}