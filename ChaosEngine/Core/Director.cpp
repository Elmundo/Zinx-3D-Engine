#include "Core/Director.h"

CHAOS_ENGINE_BEGIN

Director* Director::_instance;
bool Director::isFirstStart = true;

void Director::mainLoop()
{
	if (_isPaused)
	{
		//Scheduler::instance()->tick();
	}

	render();
}

bool Director::render(){
	/*
	for (int i=0; itemList.length; ++i)
	{
		Object* object = (Object*)itemList[i];
		if (object->hasChild)
		{
			//object->render();
		}
	}
	*/
	return true;

}
Director* Director::instance()
{
	return _instance;
}

void Director::showFPS()
{
	//Show(_fps);
}

Director::~Director()
{
	// Do some stuff
}

CHAOS_ENGINE_END