/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   ResourceService.h
Version:     v0.01
Description: Responsible for creating, managing window and windows message architecture

-------------------------------------------------------------------------
History:
- 13-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __RESOURCE_SERVICE_H__
#define __RESOURCE_SERVICE_H__

#include "resource/Model.h"
#include "resource/Texture.h"
#include "Object/Node.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL ResourceService: public Object{
private:
	static ResourceService* _instance;
	std::vector<Model*> _modelList;
	std::vector<Texture*> _textureList;

public:
	ResourceService();
	virtual ~ResourceService();

	bool loadResource(std::string resourceName);
	bool loadTextureResource(std::string textureName);
	bool removeResource(std::string resourceName);
	Model* loadModel(std::string name);
	Texture* loadTexture(std::string name);

	Model* getModel(std::string name);
	Texture* getTexture(std::string name);

	static ResourceService* instance();
	virtual void release();

private:
	

};

CHAOS_ENGINE_END

#endif