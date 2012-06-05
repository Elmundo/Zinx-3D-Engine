#pragma once

#include <d3dx9.h>
#include <d3d9.h>
//#include "Camera\Camera.h"
#include <Utility\Macros.h>

class CHAOS_DLL SkyBox{
public:
	
	struct TTexVertex{
		float x, y, z;
		float tu, tv;
	};


	LPDIRECT3DVERTEXBUFFER9 pSkyboxVertexBuffer;

	LPDIRECT3DTEXTURE9 pSkyTextures[6];

	LPDIRECT3DDEVICE9 pDirect3DDevice;

	D3DXMATRIX* pCoordMatrix;


	//Methods
	SkyBox(LPDIRECT3DDEVICE9 pDirect3DDevice);
	bool RenderSkyBox();

};



