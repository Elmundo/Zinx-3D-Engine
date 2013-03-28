/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Application.h
Version:     v0.10
Description: Manage the whole project

-------------------------------------------------------------------------
History:
- 03-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Core/Window.h"
#include "Core/Director.h"
#include "Camera/Camera.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Application: public Object{

private:
	static Application *_instance;
	LARGE_INTEGER       _renderInterval;
	HINSTANCE           _windowInstance;

public:
	Application();
	virtual ~Application();
	virtual void release();

	virtual int run();
	virtual bool initInstance() = 0;
	virtual bool applicationLaunched() = 0;
	void setRenderInterval(double interval);
	
	static Application* instance();
};

CHAOS_ENGINE_END

#endif
