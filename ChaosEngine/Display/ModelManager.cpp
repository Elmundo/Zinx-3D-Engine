#include "Display\ModelManager.h"

ModelManager::ModelManager(std::vector<Texture>* textures,
	                       std::vector<Object*>*  objectList,
						   LPDIRECT3DDEVICE9    d3d){
	
	m_textures   = textures;
	m_objectList = objectList;
	m_d3d        = d3d;
}

void ModelManager::draw(){

	std::vector<Object*>::iterator  obj;
	std::vector<Texture>::iterator tex;
	std::vector<Model>::iterator   mod;

	//m_objectList gelmiyo...
	//TODO: obj[0] tuhaflýk var
	for(obj = m_objectList->begin(); obj != m_objectList->end(); ++obj){

		m_d3d->SetTransform(D3DTS_WORLD, &obj[0]->m_Coord);
		
		for(tex = m_textures->begin(); tex != m_textures->end(); ++tex){

			if(!(obj[0]->m_TextureName.compare(tex->m_TextureName.c_str())) ){
				tex->draw();

				for(mod = m_Models.begin(); mod != m_Models.end(); ++mod){

					if(!(obj[0]->m_Name.compare(mod->m_ModelName.c_str())) ){

						mod->draw();
						break;
					}
				}
			}
		}
	}
}

bool ModelManager::loadModel(std::string modelName){
	
	m_Models.push_back(Model(modelName, m_d3d));
	return true;
}

bool ModelManager::removeModel(std::string modelName){

	std::vector<Model>::iterator i;

	for(i = m_Models.begin(); i != m_Models.end(); ++i){
		if(!(i->m_ModelName.compare(modelName.c_str())) ){
			
			i->release();
			m_Models.erase(i);
			break;
		}
	}

	return true;
}

	
