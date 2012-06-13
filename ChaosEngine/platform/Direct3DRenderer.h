/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Direct3DRenderer.h
Version:     v0.01
Description: 

-------------------------------------------------------------------------
History:
- 10-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __DIRECT3D_RENDERER_H__
#define __DIRECT3D_RENDERER_H__

#include "Object/Object.h"
#include "Core/Window.h"
#include "Utility/Math.h"
#include <d3d9.h>
#include <d3dx9core.h>

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Renderer: public Object{

private:
	static Renderer* _instance;
	LPDIRECT3D9 _direct3D;
	LPDIRECT3DDEVICE9 _device;
	LPD3DXSPRITE _deviceUI;

	D3DVIEWPORT9 _viewport;
	D3DPRESENT_PARAMETERS _deviceAttributes;
	D3DDISPLAYMODE _displayMode;

	FLOAT _aspect;
	D3DXMATRIX _projectionMatrix; //Move to Camera component

public:
	Renderer();
	virtual ~Renderer();

	void startRender();
	void stopRender();
	void setTransform(Math::matrix* view);
	LPDIRECT3DDEVICE9 getDevice();

	virtual void release();
	static Renderer* instance();

private:
	bool createDevice();
	bool createDeviceUI();
	bool setRenderStates();
	bool setFOV();
	inline bool setDeviceAttributes();
};

CHAOS_ENGINE_END

#endif