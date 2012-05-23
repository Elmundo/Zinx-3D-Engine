#ifndef DIRECT3D_H
#define DIRECT3D_H

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include <iostream>
#include "Camera\Camera.h"
//#include "Menu.h"   //Temporary
#include "Physics\RayPicking.h" //Temporary
#include "Utility\SystemTime.h"
//#include "SkyBox.h"  //Temporary
#include "System\FrameWnd.h"
#include "Display\SpriteManager.h"//Temporary
#include "Light\LightManager.h" //Temporary

#include "Display\ModelManager.h"
#include "Renderer\Renderer.h"
#include <Utility\Macros.h>

//TEMPORARY
#define	NEAR_Z		1.0f
#define FAR_Z		90000.0f

/*DIRECT3D ISLEMLERINI DE IOManager gibi GraphicsManager adlý bir sýnýfa almak gerekiyo
Bu sayade oyun motoru yapý olarak daha sade olacaktýr*/

/**************************************************/
/*  WILL NOT BE IN THE GAME ENGINE                */
/*  JUST USED TO TRY SOMETHING IF IT IS GOING     */
/*  TO BE OR ANOTHER REASONS                      */
/*                                                */
/**************************************************/

//Silinmesi gereken objeler
//LPDIRECT3D9 pDirect3D; //Just use to crate d3ddevice object - COM
//LPDIRECT3DDEVICE9 pDirect3DDevice; //Necessary Evil!!

class CHAOS_DLL Direct3D{
public:	
	//Handle Windows
	HWND hWnd;
	//Instance of the application
	HINSTANCE hInstance;
	//DirectX objects
	LPDIRECT3D9 pDirect3D; //Just use to crate d3ddevice object - COM
	LPDIRECT3DDEVICE9 pDirect3DDevice; //Necessary Evil!!
	LPD3DXSPRITE _spriteDevice;

	D3DPRESENT_PARAMETERS d3dpp; //Attributes of the Direct3DDevice
	D3DVIEWPORT9 viewPort;
	//Projection Matrix
	D3DXMATRIX matrixProjection;
	//FullScreen
	bool isFullScreen;
	//FrameWnd
	FrameWnd* frameWnd;

	Renderer* renderer;

	ModelManager* modelManager;
	SpriteManager* spriteMananger;
	LightManager* lightManager;
	SkyBox* pSkyBox;

	//Mouse inputs class
	//Mouse...
	//Keyboard inputs class
	//Keyboard...

	//Function Pointer for gameLoop - Not Working
	//void (*FunctionPointer)();

	Direct3D(HINSTANCE hInstance, FrameWnd* frameWnd){
		
		this->hWnd = frameWnd->hWnd;
		this->hInstance = hInstance;
		this->frameWnd = frameWnd;

		isFullScreen = true;
		
		//Create the direct3d Device object
		pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);
		
		D3DDISPLAYMODE Mode;
		pDirect3D->GetAdapterDisplayMode( 0, &Mode );
		ZeroMemory(&d3dpp, sizeof(d3dpp));
		
		//Toggle the screen
		toggleFullScreen();

		//FOV
		FLOAT fAspect = FLOAT(d3dpp.BackBufferWidth/ d3dpp.BackBufferHeight);

		HRESULT hr = pDirect3D->CreateDevice(D3DADAPTER_DEFAULT,
								D3DDEVTYPE_HAL,
								hWnd,
								D3DCREATE_HARDWARE_VERTEXPROCESSING,
								&d3dpp,
								&pDirect3DDevice);
		
		//Init sprite device
		D3DXCreateSprite(pDirect3DDevice, &_spriteDevice);

		//Set the render states
		setRenderStates();
		
		//Camera class'ýna tanýþmasý gerekiyor; kamera ile ilgili
		D3DXMatrixPerspectiveFovLH(&matrixProjection, 45.0f, fAspect, NEAR_Z, FAR_Z);
		pDirect3DDevice->SetTransform(D3DTS_PROJECTION, &matrixProjection);
		
		/**************************************************/
		/*                                                */
		/* OYUN MOTORUNA DAHÝL OLACAK BÜTÜN SINIFLAR      */
		/* BURADA ÝLKLENDÝRÝLÝYOR                        */
		/*                                                */
		/**************************************************/

		//Temporary situation - Create a directional light
		
		
		//pDirectionalLight = new Light(pDirect3DDevice);
		//Init the game engine objects
		//pMenu           = new Menu(pDirect3DDevice, pGameCamera, pIOManager);// GÝDÝCÝ
		//pRayPicking     = new RayPicking(hWnd, pDirect3DDevice, pGameCamera, pRayDraw);	
		pSkyBox         = new SkyBox(pDirect3DDevice);// GÝDÝCÝ
		//GEÇÝCÝÝÝÝ

		//USE THESE WHEN RESIZE THE WINDOW
		//Setting the Projection poperties                     //These parameters could bi variable or constant
		//resizeViewport(0, 0, frameWnd->clientWidth, frameWnd->clientHeight);
		//Set the light
		//pDirect3DDevice->SetLight(0, &pDirectionalLight->light);
	}

	void setRenderStates();
	//Funcitons
	HRESULT Render();

	/*These rutin stuff
	/*********************/
	/* resetDevice
	/* lostDevice
	/* releaseDevice
	/*********************/
	HRESULT resetDevice(int width, int height); //Fullscreen moda geçerken kullanýlacak
	HRESULT resizeViewport(int x, int y, int width, int height); //Viewport u tekrardan ayarlýyo, pencere resize olduðunda
	
	bool isDeviceLost();
	/*Sanal fonksiyon tanýmlanmasýnýn nedeni, bu metodlar, bu sýnýftan yeni bir sýnýf türetildiðinde
	o sýnýfta tanýmlanacak olan onLostDevice() ve onResetDevice() metodlarý çaðrýlacaktýr.
	Eðer virtual olmasaydý yeni türetilen sýnýfta tanýmlansa bile onLostDevice() metodu ebeveyn sýnýftakinden çaðrýlacaktý
	*/
	void onLostDevice();//Henüz implement edilmediler
	void onResetDevice();//Henüz implement edilmediler
	
	void toggleFullScreen();

	~Direct3D() {
		//Release the COM and other Direct3D objects
		pDirect3D->Release();
		pDirect3DDevice->Release();

		pDirect3D = NULL;
		pDirect3DDevice = NULL;
	}

	void release(){
		pDirect3D->Release();
		pDirect3DDevice->Release();

		pDirect3D = NULL;
		pDirect3DDevice = NULL;
	}

};

#endif



