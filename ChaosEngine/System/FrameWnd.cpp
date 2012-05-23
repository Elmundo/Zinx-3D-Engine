#include "System\FrameWnd.h"
#include "System\GameEngine.h"
//#include "resource.h"

LRESULT CALLBACK FrameWnd::WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){		
	
	FrameWnd* frameWnd = reinterpret_cast<FrameWnd*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	
	if(!frameWnd){
		if(uMessage == WM_CREATE){
			//Set userdatas
			frameWnd = (FrameWnd*)(((LPCREATESTRUCT)lParam)->lpCreateParams);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)frameWnd);
			frameWnd->hWnd = hWnd;
			return 0;
		}
		else
			return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}

	switch(uMessage){
		
		case WM_MOVE:
			{
				break;
			}

		//case WM_WINDOWPOSCHANGING:
		//	{
		//		break;
		//	}
		//case WM_PAINT:
		//	{
		//		break;
		//	}
		//case WM_ERASEBKGND:
		//	{
		//		break;
		//	}
		case WM_HSCROLL:
			{
				break;
			}
		case WM_VSCROLL:
			{
				break;
			}

		case WM_CHAR:
			{
				break;
			}

		case WM_KEYDOWN:
			{
				frameWnd->input->onKeyDown(wParam);
				break;
			}
		
		case WM_KEYUP:
			{
				frameWnd->input->onKeyUp(wParam);
				break;
			}

		case WM_MOUSEMOVE:
			{
				//TODO  Düzgün çalýþmýyo, daha sonra tekrardan bak
				// Get the pick ray from the mouse position
				
				/*POINT cursor = {LOWORD(lParam), HIWORD(lParam)};*/
				static POINT cursor;
				POINT cur;
				GetCursorPos(&cur);

				if ((cursor.x != cur.x) || (cursor.y != cur.y))
				{
					LPRECT rect = new RECT;
					GetClientRect(hWnd, rect);

					frameWnd->input->onMouseMove(cursor);
					SetCursorPos(rect->right/2,rect->bottom/2);
					cursor.x = cur.x;
					cursor.y = cur.y;
				}

				/*GetCursorPos( &cursor );
				ScreenToClient(hWnd, &cursor );*/
				break;
			}
		case WM_LBUTTONDOWN:
			{
				break;
			}
		
		case WM_LBUTTONUP:
			{
				break;
			}

		case WM_LBUTTONDBLCLK:
			{
				break;
			}

		case WM_MBUTTONDOWN:
			{
				break;
			}

		case WM_MBUTTONUP:
			{
				break;
			}

		case WM_MBUTTONDBLCLK:
			{
				break;
			}

		case WM_RBUTTONDOWN:
			{
				break;
			}

		case WM_RBUTTONUP:
			{
				break;
			}

		case WM_RBUTTONDBLCLK:
			{
				break;
			}

		case WM_MOUSEWHEEL:
			{
				break;
			}

		case WM_MOUSEACTIVATE:
			{
				break;
			}

		case WM_ACTIVATEAPP:
			{
				break;
			}

		case WM_ACTIVATE:
			{
				break;
			}

		case WM_NCACTIVATE:
			{
				break;
			}

		case WM_SIZE:
			{
				/*gameEngine->frameWnd->clientHeight = HIWORD(lParam);
				gameEngine->frameWnd->clientWidth  = LOWORD(lParam);

				gameEngine->pDirect3D->resizeViewport(0, 
													  0, 
													  gameEngine->frameWnd->clientWidth,
													  gameEngine->frameWnd->clientHeight);*/

				break;
			}
		case WM_SIZING:
			{
				break;
			}
			
			//Menüden herhangi bir tuþa basýldýðýnda...
		case WM_COMMAND:
			{

				/*if(LOWORD(wParam) == ID_FILE_NEW40001)
					::MessageBoxA(0,"New",0,0);
				if(LOWORD(wParam) == ID_FILE_QUIT)
					::MessageBoxA(0, "Quit",0,0);	*/			
				break;
			}
		case WM_NOTIFY:
			{
				break;
		    }

		
		case WM_CLOSE:
            {
                DestroyWindow(hWnd);
				PostQuitMessage(0);
                break;
            }
		case WM_DESTROY:
			{
				//InputMessage sýnýfýna giriyo, kontrol et
				//delete gameEngine->pDirect3D;
				GameEngine::endGame = 1;
				PostQuitMessage(0);

				break;
			}
		default: return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}	
	return DefWindowProc(hWnd, uMessage, wParam, lParam);;

}
HWND FrameWnd::initWindow(HINSTANCE hInstance, int height = 600, int width = 800){
	
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW |CS_VREDRAW;

	wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wndclass.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wndclass.hIcon = LoadIcon(hInstance, IDI_QUESTION);
	wndclass.hIconSm = LoadIcon(hInstance, IDI_QUESTION);
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = (WNDPROC)FrameWnd::WndProc;
	wndclass.lpszClassName = "Baris";
	wndclass.lpszMenuName = "MENU";
	
	if(!RegisterClassEx(&wndclass)) exit(1);

	/*hWnd = CreateWindowEx(NULL,
                        wndclass.lpszClassName,
                        "Game Engine - Level Editor",
                        WS_EX_TOPMOST | WS_POPUP,    // fullscreen values
                        0, 0,    // the starting x and y positions should be 0
                        WIDTH, HEIGHT,
                        NULL,
                        NULL,
                        hInstance,
                        NULL);
	
	*/
	hWnd = CreateWindowEx(NULL,
						wndclass.lpszClassName,
						"Game Engine - Level Editor",
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, 
						CW_USEDEFAULT,
						width,
						height,
						NULL,
						NULL,
						hInstance,
						this);
	
	//Get the window's client width and height
	LPRECT rect = new RECT;
	GetClientRect(hWnd, rect);

	clientWidth  = rect->right;
	clientHeight = rect->bottom;

	ShowCursor(false);

	if(!hWnd) exit(1);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	return 0;
}
