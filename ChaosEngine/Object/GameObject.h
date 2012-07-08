/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   GameObject.h
Version:     v0.01
Description: 

-------------------------------------------------------------------------
History:
- 12-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "Object/Node.h"
#include "resource/ResourceService.h"
#include "Utility/Math.h"
#include "Core/Renderer.h"

CHAOS_ENGINE_BEGIN

class ObjectManager;
enum DirectionEnum;

class CHAOS_DLL GameObject: public Node{

private:
	Renderer*        _renderer;
	ObjectManager*   _objectManager;
	ResourceService* _resourceService;

protected:
	Model* _model;
	Math::vector3 _position;
	Math::vector3 _direction;

	bool _isResourceAvailable;

	void drawModel();
public:
	GameObject();
	GameObject(std::string modelName);

	virtual ~GameObject();

	Math::vector3 direction();
	void move(DirectionEnum direction);
	void setResource(std::string modelName);
	void setTransform();
	virtual void render(); //this could be visit
	virtual void release();
	
};

enum CHAOS_DLL DirectionEnum{
	FORWARD = 0,
	BACKWARD,
	LEFT,
	RIGHT
};

CHAOS_ENGINE_END
#endif