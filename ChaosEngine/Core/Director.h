/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Director.h
Version:     v0.01
Description: Manager which control a lot of thing

-------------------------------------------------------------------------
History:
- 03-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include "Core/Scheduler.h"
#include "Core/Renderer.h"
#include "Core/ObjectManager.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Director: public Object {

private:
	static Director* _instance;
	static bool isFirstStart;

	bool _isPaused;
	UINT _fps;

public:
	Director();
	virtual ~Director();

	void mainLoop();
	bool render();
	void showFPS();
	void end();
	virtual void release();

	static Director* instance();

};

CHAOS_ENGINE_END

#endif