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
#include "Object/IRenderable.h"
#include "resource/ResourceService.h"
#include "Utility/Math.h"
#include "Core/Renderer.h"

CHAOS_ENGINE_BEGIN

enum CHAOS_DLL DirectionEnum{
	FORWARD = 0,
	BACKWARD,
	LEFT,
	RIGHT
};

class ObjectManager;

class CHAOS_DLL GameObject: public Node, public IRenderable{
private:
	Renderer*        _renderer;
	ObjectManager*   _objectManager;
	ResourceService* _resourceService;

	UINT64 _gameObjectID;
	Model* _model;
	Texture* _texture;
	Math::vector3 _position;
	Math::vector3 _direction;
	Math::matrix _final;

	bool _isModelAvailable;
	bool _isTextureAvailable;

	void drawModel();
	void drawTexture();

public:
	GameObject();
	GameObject(std::string modelName, std::string textureName);
	virtual ~GameObject();
	virtual void release();

	inline UINT64 countGameObject();
	inline const UINT64 gameObjectID();
	
	virtual void render();
	void move(DirectionEnum direction);
	void rotate(float angle);
	
	void setResource(std::string modelName, std::string textureName);
	void setTransform();
	void setPosition(Math::vector3 position);
	void setPosition(int x, int y, int z);

	const Math::vector3 position();
	const Math::vector3 direction();
	const Math::matrix final();
};

CHAOS_ENGINE_END
#endif