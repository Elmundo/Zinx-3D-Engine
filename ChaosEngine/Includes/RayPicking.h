#ifndef RAYPICKING_H
#define RAYPICKING_H

#include <d3d9.h>
#include <d3dx9.h>
//#include "IObject.h"
#include "Camera\Camera.h"
//!!!!!!!!!!!!!!!!!!!!!IObject içerisinden BoundingSphere sýnýfýný çýkarýp, ayrý bir dosyada kullanabilirz
// define near and far planes
//TEMPORARY
#define	NEAR_Z		1.0f
#define FAR_Z		2000.0f

class __declspec(dllexport) Ray{
public:
	D3DXVECTOR3 origin;
	D3DXVECTOR3 direction;
};

class RayPicking{
public:
/*
	LPDIRECT3DDEVICE9 pDirect3DDevice;
	//CAMERA* pGameCamera;
	//Temporary
	HWND hWnd;

	float px;
	float py;
	Ray ray;
	RayDraw* rayDraw;

	RayPicking(HWND hWnd, LPDIRECT3DDEVICE9 pDirect3DDevice, CAMERA* pGameCamera, RayDraw* rayDraw){
		this->hWnd = hWnd;
		this->pDirect3DDevice = pDirect3DDevice;
		this->pGameCamera = pGameCamera;
		this->rayDraw = rayDraw;
	}
	
	//bool intersectionTest(BoundingSphere* sphere,IOBJECT* pIObject, int x, int y);
	D3DXVECTOR3* findTheCoord(IOBJECT* pIObject);
	*/
};


//Only function

//bool IntersectionTest(BoundingSphere* sphere, IOBJECT* pIObject, int x, int y)
#endif