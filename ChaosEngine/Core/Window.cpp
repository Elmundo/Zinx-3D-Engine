#include "Core/Window.h"

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

	if (_hwnd)
		return false;

	HINSTANCE hinstance = GetModuleHandle(NULL);
	WNDCLASS wndclass;

	/*window.style          = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;  
	window.lpfnWndProc    = _WindowProc;					// WndProc Handles Messages
	window.cbWndExtra     = 0;								// No Extra Window Data
	window.hInstance      = hinstance;						// Set The Instance
	window.hIcon          = LoadIcon( NULL, IDI_WINLOGO );	// Load The Default Icon
	window.hCursor        = LoadCursor( NULL, IDC_ARROW );	// Load The Arrow Pointer
	window.hbrBackground  = NULL;                           // No Background Required For GL
	window.lpszMenuName   = NULL;                           // We Don't Want A Menu, are we sure?
	window.lpszClassName  = TEXT("ChaosEngine v0.1");            // Set The Class Name*/

	ZeroMemory(&wndclass, sizeof(WNDCLASS));

	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.style = CS_HREDRAW |CS_VREDRAW;

	wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wndclass.hCursor = LoadCursor(hinstance, IDC_ARROW);
	wndclass.hIcon = LoadIcon(hinstance, IDI_QUESTION);
	wndclass.hInstance = hinstance;
	wndclass.lpfnWndProc = _WindowProc;
	wndclass.lpszClassName = TEXT("Baris");
	wndclass.lpszMenuName = NULL;

	RegisterClass(&wndclass);

	
	
	result = HRESULT_FROM_WIN32(GetLastError());

	// center window position
	RECT rcDesktop;
	GetWindowRect(GetDesktopWindow(), &rcDesktop);
	
	
	// create window
	_hwnd = CreateWindowEx(  WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,	// Extended Style For The Window
							wndclass.lpszClassName,						    // Class Name
							title,												// Window Title
							WS_CAPTION | WS_POPUPWINDOW | WS_MINIMIZEBOX,		// Defined Window Style
							CW_USEDEFAULT, CW_USEDEFAULT,								                // Window Position
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

	ShowWindow(_hwnd, SW_SHOW);
	UpdateWindow(_hwnd);
	return true;
	
}

LRESULT CALLBACK Window::windowProc( HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam )
{
	return DefWindowProc(hWnd, uMessage, wParam, lParam);
}

HWND Window::getHwnd()
{
	return _hwnd;
}

Window* Window::instance()
{
	return _instance;
}

Window::~Window()
{
	// do some stuff
}



CHAOS_ENGINE_END