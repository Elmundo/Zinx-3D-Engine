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

CHAOS_ENGINE_BEGIN

class CHAOS_DLL GameObject: public Node{
private:

	Model* _model;

	Math::matrix _position;
	Math::matrix _combined;

	Math::matrix _scale;
	Math::matrix _translate;
	Math::matrix _rotate;

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

	void render(); //this could be visit
	void setTransform();
	virtual void release();
	
};

CHAOS_ENGINE_END
#endif