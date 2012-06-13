#include "Core/Window.h"
#include "Core/Director.h"

CHAOS_ENGINE_BEGIN

//Singleton design object
Window* Window::_instance = 0;

Window::Window()
{
	_instance = this;
	_hwnd = NULL;
}

static LRESULT CALLBACK _WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){

	if (Window::instance() && Window::instance()->getHwnd() == hWnd)
	{
		return Window::instance()->windowProc(hWnd, uMessage, wParam, lParam);
	}
	else
	{
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
}

bool Window::create( LPCTSTR title, int w, int h )
{
	HRESULT result;
	_windowClassName = "ChaosEngine v1.0";

	if (_hwnd)
		return false;

	HINSTANCE hinstance = GetModuleHandle(NULL);
	WNDCLASS wndclass;

	
	ZeroMemory(&wndclass, sizeof(WNDCLASS));
	
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.style = CS_HREDRAW |CS_VREDRAW;

	wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wndclass.hCursor = LoadCursor(hinstance, IDC_ARROW);
	wndclass.hIcon = LoadIcon(hinstance, IDI_QUESTION);
	wndclass.hInstance = hinstance;
	wndclass.lpfnWndProc = _WindowProc;
	wndclass.lpszClassName = (LPSTR)(_windowClassName.c_str());
	wndclass.lpszMenuName = NULL;

	RegisterClass(&wndclass);
	result = HRESULT_FROM_WIN32(GetLastError());

	// create window
	_hwnd = CreateWindowEx(  WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,	// Extended Style For The Window
							wndclass.lpszClassName,						    // Class Name
							title,												// Window Title
							WS_CAPTION | WS_POPUPWINDOW | WS_MINIMIZEBOX,		// Defined Window Style
							CW_USEDEFAULT, CW_USEDEFAULT,		                // Window Position
							w,                                                  // Window Width
							h,                                                  // Window Height
							NULL,												// No Parent Window
							NULL,												// No Menu
							hinstance,											// Instance
							this );

	if (!_hwnd)
	{
		result = HRESULT_FROM_WIN32(GetLastError());
		return false;
	}

	centerWindowPosition();
	ShowWindow(_hwnd, SW_SHOW);
	UpdateWindow(_hwnd);
	
	return true;
	
}

void Window::centerWindowPosition()
{
	// center window position
	RECT desktop;
	RECT application;
	GetWindowRect(GetDesktopWindow(), &desktop);
	GetWindowRect(_hwnd, &application);

	_width = application.right;
	_height = application.bottom;

	UINT offsetX = (desktop.right - _width) /2;
	UINT offsetY = (desktop.bottom - _height) /2; 
	
	SetWindowPos(_hwnd, NULL, offsetX, offsetY, _width, _height, SWP_SHOWWINDOW);
}

LRESULT CALLBACK Window::windowProc( HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam )
{
	PAINTSTRUCT ps;
	switch (uMessage)
	{
	case WM_LBUTTONDOWN:

		break;

	case WM_MOUSEMOVE:

		break;

	case WM_LBUTTONUP:

		break;
	case WM_SIZE:
		switch (wParam)
		{
		case SIZE_RESTORED:
			//CCApplication::sharedApplication().applicationWillEnterForeground();
			break;
		case SIZE_MINIMIZED:
			//CCApplication::sharedApplication().applicationDidEnterBackground();
			break;
		}
		break;
	case WM_KEYDOWN:

		break;
	case WM_KEYUP:

		break;
	case WM_CHAR:
		{
			if (wParam < 0x20)
			{
				if (VK_BACK == wParam)
				{

				}
				else if (VK_RETURN == wParam)
				{

				}
				else if (VK_TAB == wParam)
				{

				}
				else if (VK_ESCAPE == wParam)
				{
					// ESC input
					//CCDirector::sharedDirector()->end();
				}
			}
			else if (wParam < 128)
			{

			}
		}
		break;

	case WM_PAINT:
		BeginPaint(_hwnd, &ps);
		EndPaint(_hwnd, &ps);
		break;

	case WM_CLOSE:
		//CCDirector::sharedDirector()->end();
		Director::instance()->end();
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(_hwnd, uMessage, wParam, lParam);
	}

	return 0;
}

HWND Window::getHwnd()
{
	return _hwnd;
}

Window* Window::instance()
{
	if (!_instance)
		_instance = new Window();

	return _instance;
}

void Window::release(){
	if (_hwnd)
	{
		DestroyWindow(_hwnd);
		_hwnd = NULL;
	}

	UnregisterClass((LPSTR)_windowClassName.c_str(), GetModuleHandle(NULL));
	_windowClassName.clear();

	delete this;
}

Window::~Window()
{
	// do some stuff
}

CHAOS_ENGINE_END