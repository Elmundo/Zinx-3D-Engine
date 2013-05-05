#include "Core/Director.h"
#include "Core/Window.h"
#include "Camera/Camera.h"

USING_CHAOS_ENGINE;

Director* Director::_instance;
bool Director::isFirstStart = true;

Director::Director()
{
	_isPaused = false;
}

Director::~Director()
{
	
}

void Director::release()
{
	Window::instance()->release();
	Renderer::instance()->release();
	Camera::instance()->release();
	Scheduler::instance()->release();
	ObjectManager::instance()->release();

	Object::release();
}

void Director::mainLoop()
{
	if (!_isPaused)
		Scheduler::instance()->tick();

	render();
}

bool Director::render(){
	
	Renderer::instance()->startRender();
		
		ObjectManager::instance()->visit(); //TODO: this could be a root node object?

	Renderer::instance()->stopRender();
	return true;
}

void Director::showFPS()
{
	//Show(_fps);
}

void Director::end()
{
	this->release();
}

Director* Director::instance()
{
	if (!_instance)
		_instance = new Director();

	return _instance;
}