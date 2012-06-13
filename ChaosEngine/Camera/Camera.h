/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Camera.h
Version:     v0.01
Description: 

-------------------------------------------------------------------------
History:
- 03-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Object/GameObject.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Camera: public Object{
private:
	static Camera* _instance;
	Math::matrix _view;
	Math::vector3 _right;
	Math::vector3 _up;
	Math::vector3 _look;
	Math::vector3 _cameraPosition;

public:
	Camera();
	virtual ~Camera();

	void setView();
	void pitch(float angle);
	void yaw(float angle);
	void roll(float angle);
	void walk(float unit);
	void strafe(float unit);
	void fly(float angle);

	Math::matrix view();
	Math::vector3 right();
	Math::vector3 up();
	Math::vector3 look();
	Math::vector3 cameraPosition();

	virtual void release();
	static Camera* instance();
};

CHAOS_ENGINE_END

#endif