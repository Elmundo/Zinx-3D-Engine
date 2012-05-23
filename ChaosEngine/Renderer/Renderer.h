#ifndef RENDERER_H
#define RENDERER_H

#include "System\Direct3D.h"
#include "Display\ModelManager.h"
#include "Display\SpriteManager.h"
#include "Display\TextureManager.h"
#include "SkyBox.h"

#include "Object\Object.h"
#include "Object\Object2D.h"

#include <Utility\Macros.h>

class CHAOS_DLL Renderer{
private:
	LPDIRECT3DDEVICE9 _d3d;
	LPD3DXSPRITE      _spriteDevice;

	ModelManager* _modelManager;
	SpriteManager* _spriteManager;
	TextureManager* _textureManager;

	std::vector<Object*>* _objectList;
	std::vector<Object2D*>* _spriteList;
	SkyBox* _skyBox; //Temporary
	
public:

	Renderer(ModelManager* modelManager, SpriteManager* spriteManager, TextureManager* textureManager,
			 std::vector<Object*>* objectList, std::vector<Object2D*>* spriteList,
			 LPDIRECT3DDEVICE9 d3d, LPD3DXSPRITE spriteDevice){
		_d3d           = d3d;
		_modelManager   = modelManager;
		_spriteManager  = spriteManager;
		_textureManager = textureManager; 
		
		_objectList    = objectList;
		_spriteList    = spriteList;
		_skyBox = new SkyBox(_d3d);


	}

	void render(){
		_d3d->Clear(0, NULL,D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
		_d3d->BeginScene();
			//_modelManager->draw();
			modelRender();
			_spriteManager->draw();
			_skyBox->RenderSkyBox();
		_d3d->EndScene();
		_d3d->Present(NULL,NULL,NULL,NULL);
	}
	
	void spriteRender(){
	
	}

	void modelRender(){
		std::vector<Object*>::iterator  obj;
		std::vector<Texture>::iterator tex;
		std::vector<Model>::iterator   mod;

		std::vector<Texture> textureList   = _textureManager->m_Textures;
		std::vector<Model>   modelList     = _modelManager->m_Models;
		std::vector<Object*>*  objectList  = _objectList;


		////m_objectList gelmiyo...
		////TODO: obj[0] tuhaflýk var
		for(obj = objectList->begin(); obj != objectList->end(); ++obj){

			_d3d->SetTransform(D3DTS_WORLD, &(*obj)->m_Coord);
		
			for(tex = textureList.begin(); tex != textureList.end(); ++tex){

				if(!(*obj)->m_TextureName.compare(tex->m_TextureName.c_str())) {
					tex->draw();

					for(mod = modelList.begin(); mod != modelList.end(); ++mod){

						if(!(obj[0]->m_Name.compare(mod->m_ModelName.c_str())) ){

							mod->draw();
							break;
						}
					}
				}
			}
		}
	}
	
};

#endif