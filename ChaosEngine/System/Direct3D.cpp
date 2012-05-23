#include "System\Direct3D.h"

//Temporary
//extern int xPos;
//extern int yPos;

//Temporary
//Bu render Ýþlemi de GraphicsManager sýnýfnýn metodu olacak
void Direct3D::setRenderStates(){
	
	pDirect3DDevice->SetRenderState(D3DRS_ALPHATESTENABLE, true);
	pDirect3DDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
	pDirect3DDevice->SetRenderState(D3DRS_ALPHAREF, 100);
		
	pDirect3DDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	pDirect3DDevice->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	pDirect3DDevice->SetRenderState(D3DRS_SPECULARENABLE, TRUE);
		
	// Turn off culling, so we see the front and back of the triangle
	pDirect3DDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );
	/*
	// Turn off D3D lighting, since we are providing our own vertex colors
	//pDirect3DDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	pDirect3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	pDirect3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
	pDirect3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	//Enable the lighting
	//pDirect3DDevice->SetRenderState(D3DRS_FILLMODE ,D3DFILL_WIREFRAME);
	pDirect3DDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	pDirect3DDevice->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(50, 0, 10));//3D cismin rengini belirliyo
	pDirect3DDevice->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	pDirect3DDevice->SetRenderState(D3DRS_SPECULARENABLE, TRUE);

	//TERRAIN YAPISINDAKÝ DOKU SIKIÞTIRMASINI YAPIYOR
	pDirect3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	pDirect3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	pDirect3DDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

	// What about the ugly seams inbetween the cube face textures?  Well we need to get rid of them
	// somehow.
	pDirect3DDevice->SetSamplerState( 0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP );
	pDirect3DDevice->SetSamplerState( 0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP );
	*/
	//pDirect3DDevice->SetRenderState( D3DRS_AMBIENT, D3DCOLOR_COLORVALUE( 1.0f, 1.0f, 1.0f, 1.0f ) );
		
		
	//TERRAIN YAPISINDAKÝ DOKU SIKIÞTIRMASINI YAPIYOR
	pDirect3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	pDirect3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	pDirect3DDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

	//SKYBOX daki köþelerde oluþan artifektleri kapatýyo
	// What about the ugly seams inbetween the cube face textures?  Well we need to get rid of them
	// somehow.
	pDirect3DDevice->SetSamplerState( 0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP );
	pDirect3DDevice->SetSamplerState( 0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP );
	//!!!IMPORTANT!!!
	//This renderstate enables the ambient light
	pDirect3DDevice->SetRenderState( D3DRS_AMBIENT, D3DCOLOR_COLORVALUE( 1.0f, 1.0f, 1.0f, 1.0f ) );
}

HRESULT Direct3D::Render(){
	
	//Clear the screen
	//D3DCOLOR_XRGB(  0,   0,   0) == Black
	//D3DCOLOR_XRGB(255, 255, 255) == White
	pDirect3DDevice->Clear(0, NULL,D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	//Begin the drawing operations
	pDirect3DDevice->BeginScene();
	renderer->render();
	//End the drawing operations
	pDirect3DDevice->EndScene();
	pDirect3DDevice->Present(NULL,NULL,NULL,NULL);

	return S_OK;
}

HRESULT Direct3D::resetDevice(int width, int height){

	d3dpp.BackBufferCount =1;
	d3dpp.BackBufferHeight = height;
	d3dpp.BackBufferWidth = width;
	
	//Direct3D yi yeni özelliklerine göre resetliyo
	HRESULT hr = pDirect3DDevice->Reset(&d3dpp);
	//if(FAILED(hr))
		//return false;

	return true;
}

HRESULT Direct3D::resizeViewport(int x, int y, int width, int height){
	
	viewPort.X = x;
	viewPort.Y = y;
	viewPort.Width = width;
	viewPort.Height = height;
	viewPort.MaxZ = 1.0f;
	viewPort.MinZ = 0.0f;

	HRESULT hr = pDirect3DDevice->TestCooperativeLevel();
	
	if(SUCCEEDED(hr)){
		//Use this resetDevice for toggling to fullscreen mode...
		//Reseting the device and also sets the size of backbuffer of viewPort
		//resetDevice(width, height);

		pDirect3DDevice->SetViewport(&viewPort);

		D3DXMatrixPerspectiveFovLH(&matrixProjection, 45.0f, (float)width/(float)height, 1.0f, FAR_Z);
		pDirect3DDevice->SetTransform(D3DTS_PROJECTION, &matrixProjection);

	}
	return true;
}

bool Direct3D::isDeviceLost(){
	
    // Returns true if lost, false otherwise.

	// Get the state of the graphics device.
    HRESULT hr = pDirect3DDevice->TestCooperativeLevel();

    // If the device is lost and cannot be reset yet, then
    // sleep for a bit and we'll try again on the next
    // message loop cycle.
    if( hr == D3DERR_DEVICELOST )
    {
        Sleep(20);
        return true;
    }
    // Driver error, exit.
    else if( hr == D3DERR_DRIVERINTERNALERROR )
    {
        MessageBox(0, "Internal Driver Error...Exiting", 0, 0);
        PostQuitMessage(0);
        return true;
    }
    // The device is lost but we can reset and restore it.
    else if( hr == D3DERR_DEVICENOTRESET )
    {
        //onLostDevice();
        pDirect3DDevice->Reset(&d3dpp);
        //onResetDevice();
        // Not lost anymore.
        return false;
    }
    else
        // Not lost anymore.
        return false;
}

//ARIZALI
void Direct3D::toggleFullScreen(){
	
	if(isFullScreen){
		d3dpp.Windowed                   = true;
		d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD;
		d3dpp.MultiSampleQuality         = 0;
		d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
		d3dpp.BackBufferFormat           = D3DFMT_UNKNOWN;
		d3dpp.BackBufferCount            = 1;
		d3dpp.BackBufferHeight           = frameWnd->clientHeight;
		d3dpp.BackBufferWidth            = frameWnd->clientWidth;
		d3dpp.hDeviceWindow              = hWnd;
		d3dpp.EnableAutoDepthStencil     = true;
		d3dpp.AutoDepthStencilFormat     = D3DFMT_D16;
		d3dpp.Flags                      = 0;
		d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

		//pDirect3DDevice->Reset(&d3dpp);
	
		isFullScreen = true;
	}
	else{
		d3dpp.Windowed = FALSE;    // program fullscreen, not windowed
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
		d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;    // set the back buffer format to 32-bit
		d3dpp.BackBufferWidth = 800;    // set the width of the buffer
		d3dpp.BackBufferHeight = 600;    // set the height of the buffer
		d3dpp.EnableAutoDepthStencil = true;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

//		pDirect3DDevice->Reset(&d3dpp);
		
		isFullScreen = false;
	}
}

	
