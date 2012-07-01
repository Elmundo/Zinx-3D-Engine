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
protected:

	Renderer* _renderer;
	ObjectManager* _objectManager;
	ResourceService* _resourceService;

	Model* _model;
	bool _isResourceAvailable;

	Math::matrix _positionMat;
	Math::matrix _combined;

	Math::matrix _scale;
	Math::matrix _translate;
	Math::matrix _rotate;

	Math::vector3 _position;
	Math::vector3 _direction;

	void drawModel();
public:
	GameObject();
	GameObject(std::string modelName);

	virtual ~GameObject();

	Math::matrix position();
	Math::matrix combined();
	Math::matrix scale();
	Math::matrix translate();
	Math::matrix rotate();
	Math::vector3 direction();

	void move(DirectionEnum direction);
	void setResource(std::string modelName);
	virtual void render(); //this could be visit
	void setTransform();
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