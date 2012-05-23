#include "Display\SpriteManager.h"

SpriteManager::SpriteManager(std::vector<Object2D*> *spriteList, LPD3DXSPRITE spriteDevice, LPDIRECT3DDEVICE9 d3d){
	
	_d3d = d3d;
	_spriteList = spriteList;

	_SpriteDevice = spriteDevice;
}

void SpriteManager::draw(){
	
	std::vector<Object2D*>::iterator obj;
	std::vector<Sprite>::iterator   spt;


	_SpriteDevice->Begin(D3DXSPRITE_ALPHABLEND);

		for(obj = _spriteList->begin(); obj != _spriteList->end(); ++obj){
			_SpriteDevice->SetTransform(&(*obj)->m_PosMatrix);
			
			for(spt = _Sprites.begin(); spt != _Sprites.end(); ++spt){
				if(!((*obj)->m_Name.compare(spt->_SpriteName.c_str())) ){
					_SpriteDevice->Draw(spt->_Texture, 0, new Math::vector3(0,0,0), &(*obj)->m_Pos, D3DCOLOR_XRGB(255, 255, 255));
				}
			}
		}

		_SpriteDevice->Flush();
	_SpriteDevice->End();
}

bool SpriteManager::addChild(std::string spriteName){

	_Sprites.push_back(Sprite(_d3d, spriteName));
	
	return true;
}

bool SpriteManager::removeChild(std::string spriteName){

	std::vector<Sprite>::iterator i;

	for(i = _Sprites.begin(); i != _Sprites.end(); ++i){
		if(!(i->_SpriteName.compare(spriteName.c_str())) ){
			
			i->release();
			_Sprites.erase(i);
			break;
		}
	}

	return true;
}