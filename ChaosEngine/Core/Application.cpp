#include "Core/Application.h"
#include "Log/Log.h"
#include "Utility/ClassHelper.h"
#include "resource/ResourceService.h"

CHAOS_ENGINE_BEGIN

// Singleton design variable
Application* Application::_instance;

Application::Application(){
	
	_windowInstance = GetModuleHandle(NULL);
	_renderInterval.QuadPart = 0;
	_instance = this;

}

int Application::run(){
	
	Log::instance()->info(ClassHelper::getClassName(this), "run", "ChaosEngine v0.1" );

	MSG msg;
	LARGE_INTEGER frequency;
	LARGE_INTEGER now;
	LARGE_INTEGER last;

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&last);

	Window* wnd = new Window();// Windows::instance();
	if(!wnd->create((LPCSTR)"ChaosEngine v0.1", 640, 480))
		return 1;

	Camera* camera = Camera::instance();
	if (!camera)
		return 1;

	// Call initInstance and applicationLaunched methods here
	if (!initInstance() || !applicationLaunched())
		return 0;

	if(_renderInterval.QuadPart == 0)
		setRenderInterval(1.0 / 60);

	while(1){

		if (!PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			QueryPerformanceCounter(&now);

			if (now.QuadPart - last.QuadPart > _renderInterval.QuadPart)
			{
				last.QuadPart = now.QuadPart;
				Director::instance()->mainLoop();
			}
			else{
				Sleep(0);
			}
			continue;
		}

		if(msg.message == WM_QUIT){
			break;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;

}

void Application::setRenderInterval( double interval ){

	LARGE_INTEGER frequency;

	QueryPerformanceFrequency(&frequency);
	_renderInterval.QuadPart = (LONGLONG)(interval * frequency.QuadPart);
}

Application* Application::instance(){
	return _instance;
}

bool Application::initInstance()
{
	ResourceService::instance()->loadResource("troll2.X");

	GameObject* gameObject = new GameObject("troll2.X");

	return true;
}

bool Application::applicationLaunched()
{
	//Override this method
	return true;
}

Application::~Application()
{
	// do some stuff
}

CHAOS_ENGINE_END