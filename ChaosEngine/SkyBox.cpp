#include "SkyBox.h"

CHAOS_ENGINE_BEGIN

SkyBox::SkyBox(){
	
	_renderer = Renderer::instance()->getDevice();

	TTexVertex SkyboxMesh[24] =
	{
		// Front quad, NOTE: All quads face inward
		{-50000.0f, -50000.0f,  50000.0f,  0.0f, 1.0f },
		{-50000.0f,  50000.0f,  50000.0f,  0.0f, 0.0f },
		{ 50000.0f, -50000.0f,  50000.0f,  1.0f, 1.0f },
		{ 50000.0f,  50000.0f,  50000.0f,  1.0f, 0.0f },
	
		// Back quad
		{ 50000.0f, -50000.0f, -50000.0f,  0.0f, 1.0f },
		{ 50000.0f,  50000.0f, -50000.0f,  0.0f, 0.0f },
		{-50000.0f, -50000.0f, -50000.0f,  1.0f, 1.0f },
		{-50000.0f,  50000.0f, -50000.0f,  1.0f, 0.0f },
	
		// Left quad
		{-50000.0f, -50000.0f, -50000.0f,  0.0f, 1.0f },
		{-50000.0f,  50000.0f, -50000.0f,  0.0f, 0.0f },
		{-50000.0f, -50000.0f,  50000.0f,  1.0f, 1.0f },
		{-50000.0f,  50000.0f,  50000.0f,  1.0f, 0.0f },
	
		// Right quad
		{ 50000.0f, -50000.0f,  50000.0f,  0.0f, 1.0f },
		{ 50000.0f,  50000.0f,  50000.0f,  0.0f, 0.0f },
		{ 50000.0f, -50000.0f, -50000.0f,  1.0f, 1.0f },
		{ 50000.0f,  50000.0f, -50000.0f,  1.0f, 0.0f },

		// Top quad
		{-50000.0f,  50000.0f,  50000.0f,  0.0f, 1.0f },
		{-50000.0f,  50000.0f, -50000.0f,  0.0f, 0.0f },
		{ 50000.0f,  50000.0f,  50000.0f,  1.0f, 1.0f },
		{ 50000.0f,  50000.0f, -50000.0f,  1.0f, 0.0f },
	
		// Bottom quad
		{-50000.0f, -50000.0f, -50000.0f,  0.0f, 1.0f },
		{-50000.0f, -50000.0f,  50000.0f,  0.0f, 0.0f },
		{ 50000.0f, -50000.0f, -50000.0f,  1.0f, 1.0f },
		{ 50000.0f, -50000.0f,  50000.0f,  1.0f, 0.0f }
	};

	// Why did I use an HRESULT instead of a bool or int?  Well since DirectX is
	// written in COM the typical return values are HRESULTs.
	HRESULT hRet;


	// Create our vertex buffer ( 24 vertices (4 verts * 6 faces) )
    _renderer->CreateVertexBuffer( sizeof(TTexVertex) * 24, 0, D3DFVF_XYZ | D3DFVF_TEX1,
                                             D3DPOOL_MANAGED, &pSkyboxVertexBuffer, NULL );

	void *pVertices = NULL;

	// Copy the skybox mesh into the vertex buffer.  I initialized the whole mesh array
	// above in global space.
	pSkyboxVertexBuffer->Lock( 0, sizeof(TTexVertex) * 24, (void**)&pVertices, 0 );
    memcpy( pVertices, SkyboxMesh, sizeof(TTexVertex) * 24 );
    pSkyboxVertexBuffer->Unlock();

	// Load Textures.  I created a global array just to keep things simple.  The order of the images
	// is VERY important.  The reason is the skybox mesh (g_SkyboxMesh[]) array was created above
	// in this order. (ie. front, back, left, etc.)
    hRet  = D3DXCreateTextureFromFile( _renderer, ("Resource/SkyBox_Front.jpg") , &pSkyTextures[0] );
    hRet |= D3DXCreateTextureFromFile( _renderer, ("Resource/SkyBox_Back.jpg")  , &pSkyTextures[1] );
    hRet |= D3DXCreateTextureFromFile( _renderer, ("Resource/SkyBox_Left.jpg")  , &pSkyTextures[2] );
    hRet |= D3DXCreateTextureFromFile( _renderer, ("Resource/SkyBox_Right.jpg") , &pSkyTextures[3] );
    hRet |= D3DXCreateTextureFromFile( _renderer, ("Resource/SkyBox_Top.jpg")   , &pSkyTextures[4] );
    hRet |= D3DXCreateTextureFromFile( _renderer, ("Resource/SkyBox_Bottom.jpg"), &pSkyTextures[5] );
}

bool SkyBox::RenderSkyBox(){

	// Set up rendering states for the sky box
	//pDirect3DDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );
    //pDirect3DDevice->SetRenderState( D3DRS_ZWRITEENABLE, false );
	//pDirect3DDevice->SetRenderState( D3DRS_LIGHTING, false );

	// Render the sky box
    _renderer->SetFVF( D3DFVF_XYZ | D3DFVF_TEX1 );
    _renderer->SetStreamSource( 0, pSkyboxVertexBuffer, 0, sizeof(TTexVertex));
    
	// Set the world matrix to identity for the skybox
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	//CAMERA YI TAKÝP ETSÝN SKYBOX
	_renderer->SetTransform(D3DTS_WORLD, &matWorld );

    // Render the 6 faces of the skybox
	// DrawPrimitive is used to draw polygons when the vertices are stored in a device resource 
	// called a vertex buffer. Vertex buffers are blocks of memory allocated by the device that
	// we use to store vertex data.
    for ( ULONG i = 0; i < 6; ++i )
    {
		// Set the texture for this primitive
        _renderer->SetTexture( 0, pSkyTextures[i] );

		// Render the face (one strip per face from the vertex buffer)  There are 2 primitives per face.
        _renderer->DrawPrimitive( D3DPT_TRIANGLESTRIP, i * 4, 2 );

    } // Next side

		// Must turn lighting back on for the teapot
	// Set up rendering states for the sky box
    //pDirect3DDevice->SetRenderState( D3DRS_ZWRITEENABLE, true );
	//pDirect3DDevice->SetRenderState( D3DRS_LIGHTING, true );

	return true;
}

CHAOS_ENGINE_END