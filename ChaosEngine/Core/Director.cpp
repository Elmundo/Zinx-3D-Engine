#include "Core/Director.h"
#include "Core/Window.h"
#include "Camera/Camera.h"

//Delete later
#include "SkyBox.h"

CHAOS_ENGINE_BEGIN

Director* Director::_instance;
bool Director::isFirstStart = true;
SkyBox* skybox; //delete

Director::Director()
{
	skybox = new SkyBox(); //delete
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
		
		ObjectManager::instance()->visit();
		skybox->RenderSkyBox();

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

CHAOS_ENGINE_END