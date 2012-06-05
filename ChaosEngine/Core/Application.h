/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Application.h
Version:     v0.10
Description: Manage the whole project

-------------------------------------------------------------------------
History:
- 2012-03-06   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Core/Window.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Application: public Object{

private:
	static Application* _instance;
	LARGE_INTEGER       _renderInterval;
	HINSTANCE           _windowInstance;

public:
	Application();
	virtual ~Application();

	virtual bool initInstance();
	virtual bool applicationLaunched();

	int run();
	void setRenderInterval(double interval);
	static Application* instance();
};

CHAOS_ENGINE_END

#endif
