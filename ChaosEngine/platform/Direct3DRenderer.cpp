#include "platform/Direct3DRenderer.h"

CHAOS_ENGINE_BEGIN

Renderer* Renderer::_instance;

Renderer::Renderer()
{
	_direct3D = Direct3DCreate9(D3D_SDK_VERSION);
	_direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &_displayMode);

	createDevice();
	createDeviceUI();
	setRenderStates();
	setFOV();
}

Renderer::~Renderer()
{
	_direct3D->Release();
	_device->Release();
	_deviceUI->Release();

	_direct3D = NULL;
	_device = NULL;
	_deviceUI = NULL;
}

bool Renderer::createDevice()
{
	HWND hwnd = Window::instance()->getHwnd();
	CE_CLEAR(&_deviceAttributes);
	HRESULT result;

	setDeviceAttributes();
	result = _direct3D->CreateDevice(D3DADAPTER_DEFAULT,
									D3DDEVTYPE_HAL,
									hwnd,
									D3DCREATE_HARDWARE_VERTEXPROCESSING,
									&_deviceAttributes,
									&_device);

	return true;
}

bool Renderer::createDeviceUI()
{
	HRESULT result;

	result = D3DXCreateSprite(_device, &_deviceUI);

	if (FAILED(result))
	{
		return false;
	}

	return true;
}

bool Renderer::setRenderStates()
{
	_device->SetRenderState(D3DRS_ALPHATESTENABLE, true);
	_device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
	_device->SetRenderState(D3DRS_ALPHAREF, 100);
	_device->SetRenderState(D3DRS_LIGHTING, TRUE);
	_device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	_device->SetRenderState(D3DRS_SPECULARENABLE, TRUE);
	_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE );
	_device->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_COLORVALUE( 1.0f, 1.0f, 1.0f, 1.0f ) );

	_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	_device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	_device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP );
	_device->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP );

	return true;
}

bool Renderer::setFOV()
{
	_aspect = FLOAT(_deviceAttributes.BackBufferWidth/ _deviceAttributes.BackBufferHeight);
	D3DXMatrixPerspectiveFovLH(&_projectionMatrix, FOVY, _aspect, NEAR_Z, FAR_Z); //Should we move this to Camera class?
	_device->SetTransform(D3DTS_PROJECTION, &_projectionMatrix);

	return true;
}

bool Renderer::setDeviceAttributes()
{
	HWND hwnd = Window::instance()->getHwnd();

	/*_deviceAttributes.Windowed = FALSE;
	_deviceAttributes.SwapEffect = D3DSWAPEFFECT_DISCARD;
	_deviceAttributes.hDeviceWindow = hwnd; 
	_deviceAttributes.BackBufferFormat = D3DFMT_X8R8G8B8;
	_deviceAttributes.BackBufferWidth = SCREEN_HEIGHT; 
	_deviceAttributes.BackBufferHeight = SCREEN_WIDTH; 
	_deviceAttributes.EnableAutoDepthStencil = true;
	_deviceAttributes.AutoDepthStencilFormat = D3DFMT_D16;*/

	_deviceAttributes.Windowed                   = true;
	_deviceAttributes.SwapEffect                 = D3DSWAPEFFECT_DISCARD;
	_deviceAttributes.MultiSampleQuality         = 0;
	_deviceAttributes.MultiSampleType            = D3DMULTISAMPLE_NONE;
	_deviceAttributes.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	_deviceAttributes.BackBufferFormat           = D3DFMT_UNKNOWN;
	_deviceAttributes.BackBufferCount            = 1;
	_deviceAttributes.BackBufferHeight           = SCREEN_HEIGHT;
	_deviceAttributes.BackBufferWidth            = SCREEN_WIDTH;
	_deviceAttributes.hDeviceWindow              = hwnd;
	_deviceAttributes.EnableAutoDepthStencil     = true;
	_deviceAttributes.AutoDepthStencilFormat     = D3DFMT_D16;
	_deviceAttributes.Flags                      = 0;
	_deviceAttributes.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

	return true;
}

void Renderer::startRender()
{
	_device->Clear(0, NULL,D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	_device->BeginScene();
}

void Renderer::stopRender()
{
	_device->EndScene();
	_device->Present(NULL,NULL,NULL,NULL);
}

void Renderer::setTransform(Math::matrix* view)
{
	_device->SetTransform(D3DTS_VIEW, view);
}

LPDIRECT3DDEVICE9 Renderer::getDevice()
{
	return _device;
}

Renderer* Renderer::instance()
{
	if (!_instance)
		_instance = new Renderer();

	return _instance;
}

void Renderer::release()
{
	//delete this;
}

CHAOS_ENGINE_END