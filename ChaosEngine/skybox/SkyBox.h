#ifndef __SKYBOX_H__
#define __SKYBOX_H__

#include <d3dx9.h>
#include <d3d9.h>
//#include "Camera\Camera.h"
#include <Utility/Macros.h>
#include "Core/Renderer.h"
#include "Object/IRenderable.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL SkyBox: public IRenderable{
public:
	
	struct TTexVertex{
		float x, y, z;
		float tu, tv;
	};


	LPDIRECT3DVERTEXBUFFER9 pSkyboxVertexBuffer;

	LPDIRECT3DTEXTURE9 pSkyTextures[6];

	LPDIRECT3DDEVICE9 _renderer;

	D3DXMATRIX* pCoordMatrix;

	//Methods
	SkyBox();
	void render();
};

CHAOS_ENGINE_END

#endif


