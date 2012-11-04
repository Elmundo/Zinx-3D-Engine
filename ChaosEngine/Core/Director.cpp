#include "Core/Director.h"
#include "Core/Window.h"
#include "Camera/Camera.h"

//Delete later
#include "SkyBox.h"

USING_CHAOS_ENGINE;

Director* Director::_instance;
bool Director::isFirstStart = true;
SkyBox* skybox; //TODO: delete

Director::Director()
{
	skybox = new SkyBox(); //TODO: delete
	_isPaused = false;
}

void Director::mainLoop()
{
	if (!_isPaused)
		Scheduler::instance()->tick();

	render();
}

bool Director::render(){
	
	Renderer::instance()->startRender();
		
		skybox->RenderSkyBox(); //TODO: delete
		ObjectManager::instance()->visit();

	Renderer::instance()->stopRender();
	return true;
}

Director* Director::instance()
{
	if (!_instance)
		_instance = new Director();

	return _instance;
}

void Director::showFPS()
{
	//Show(_fps);
}

void Director::end()
{
	this->release();
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

Director::~Director()
{
	// Do some stuff
}

