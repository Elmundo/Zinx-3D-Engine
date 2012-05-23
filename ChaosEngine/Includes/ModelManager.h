#pragma once 
#ifndef MODEL_MANAGER_H
#define MODEL_MANAGER_H

#include <d3d9.h>
#include <iostream>
#include <string>
#include <vector>
#include "Display\Model.h"
#include "Display\Texture.h"
#include "Object\Object.h"

class __declspec(dllexport) ModelManager{
public:

	//FUNDAMENTAL MEMBERS
	std::vector<Model> m_Models;

	//OUTSIDE MEMBERS
	std::vector<Texture>* m_textures;
	std::vector<Object*>*  m_objectList;
	LPDIRECT3DDEVICE9      m_d3d;

	//METHODS
	ModelManager(std::vector<Texture>* textures,
		         std::vector<Object*>*  objectList,
				 LPDIRECT3DDEVICE9      d3d);


	//Is that logical that drawing the game object in this class?
	void draw();
	
	bool loadModel(std::string modelName);
	bool removeModel(std::string modelName);
};

#endif