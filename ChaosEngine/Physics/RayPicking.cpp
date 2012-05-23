#include "Physics\RayPicking.h"
/*
bool RayPicking::intersectionTest(BoundingSphere* sphere, IOBJECT* pIObject, int x, int y){	

	
	//Get the viewPort attributes
	D3DVIEWPORT9 viewPort;
	pDirect3DDevice->GetViewport(&viewPort);

	//Get the Projection Matrix
	D3DXMATRIX projectionMatrix;
	pDirect3DDevice->GetTransform(D3DTS_PROJECTION, &projectionMatrix);
	
	D3DXVECTOR3 vPickRayDir;
    D3DXVECTOR3 vPickRayOrig;

    // Get the pick ray from the mouse position
	POINT ptCursor;
    GetCursorPos( &ptCursor );
    ScreenToClient( hWnd, &ptCursor );


    // Compute the vector of the pick ray in screen space
    D3DXVECTOR3 v;
    v.x =  ( ( ( 2.0f * ptCursor.x ) / viewPort.Width  ) - 1 ) / projectionMatrix._11;
    v.y = -( ( ( 2.0f * ptCursor.y ) / viewPort.Height ) - 1 ) / projectionMatrix._22;
    v.z =  1.0f;

	// Get the View Matrix
	D3DXMATRIX view;
	pDirect3DDevice->GetTransform(D3DTS_VIEW, &view);

    // Get the inverse view matrix
	// transform the ray to world space
	D3DXMATRIX viewInverse;
	D3DXMatrixIdentity(&viewInverse);
	D3DXMatrixInverse(&viewInverse,	NULL, &view);

    // Transform the screen space pick ray into 3D space
	//Camera Space den World Space e geçiþ yapýlýyor..
    vPickRayDir.x  = v.x*viewInverse._11 + v.y*viewInverse._21 + v.z*viewInverse._31;
    vPickRayDir.y  = v.x*viewInverse._12 + v.y*viewInverse._22 + v.z*viewInverse._32;
    vPickRayDir.z  = v.x*viewInverse._13 + v.y*viewInverse._23 + v.z*viewInverse._33;
	
	D3DXVec3Normalize(&vPickRayDir,&vPickRayDir);
    
	vPickRayOrig.x = viewInverse._41;
    vPickRayOrig.y = viewInverse._42;
    vPickRayOrig.z = viewInverse._43;

	// calc origin as intersection with near frustum
	vPickRayOrig += vPickRayDir*NEAR_Z;

	//*****************************/
	//ASIL PICKING IN YAPILDIGI YER//
	//*****************************//
/*	
	// test for intersection
	BOOL bHit = FALSE;
	DWORD dwIndex;
	FLOAT fu;
	FLOAT fv;
	FLOAT dist;
	
	// yes, convert ray to model space
	D3DXVECTOR3 vNear,vDir;
	D3DXMATRIX invMat;
	D3DXMatrixInverse(&invMat,NULL,pIObject->pCoordMatrix);
	
	D3DXVec3TransformCoord(&vNear,&vPickRayOrig,&invMat); //Act as w=1 
	D3DXVec3TransformNormal(&vDir,&vPickRayDir,&invMat);// Act as w=0
	                               //Pos   //Direction
								
	D3DXIntersect(pIObject->pMesh, &vNear, &vDir, &bHit, &dwIndex, &fu, &fv, &dist, NULL, NULL);
	return bHit;
*/
//}

/*
D3DXVECTOR3* RayPicking::findTheCoord(IOBJECT* pIObject){

	//Get the viewPort attributes
	D3DVIEWPORT9 viewPort;
	pDirect3DDevice->GetViewport(&viewPort);
	//Get the Projection Matrix
	D3DXMATRIX projectionMatrix;
	pDirect3DDevice->GetTransform(D3DTS_PROJECTION, &projectionMatrix);
	
	D3DXVECTOR3 vPickRayDir;
    D3DXVECTOR3 vPickRayOrig;
    // Get the pick ray from the mouse position
	POINT ptCursor;
    GetCursorPos( &ptCursor );
    ScreenToClient( hWnd, &ptCursor );
    //Compute the vector of the pick ray in screen space
    D3DXVECTOR3 v;
    v.x =  ( ( ( 2.0f * ptCursor.x ) / viewPort.Width  ) - 1 ) / projectionMatrix._11;
    v.y = -( ( ( 2.0f * ptCursor.y ) / viewPort.Height ) - 1 ) / projectionMatrix._22;
    v.z =  1.0f;
	// Get the View Matrix
	D3DXMATRIX view;
	pDirect3DDevice->GetTransform(D3DTS_VIEW, &view);
    // Get the inverse view matrix
	// transform the ray to world space
	D3DXMATRIX viewInverse;
	D3DXMatrixIdentity(&viewInverse);
	D3DXMatrixInverse(&viewInverse,	NULL, &view);
    // Transform the screen space pick ray into 3D space
	//Camera Space den World Space e geçiþ yapýlýyor..
    vPickRayDir.x  = v.x*viewInverse._11 + v.y*viewInverse._21 + v.z*viewInverse._31;
    vPickRayDir.y  = v.x*viewInverse._12 + v.y*viewInverse._22 + v.z*viewInverse._32;
    vPickRayDir.z  = v.x*viewInverse._13 + v.y*viewInverse._23 + v.z*viewInverse._33;
	D3DXVec3Normalize(&vPickRayDir,&vPickRayDir);
	vPickRayOrig.x = viewInverse._41;
    vPickRayOrig.y = viewInverse._42;
    vPickRayOrig.z = viewInverse._43;
	// calc origin as intersection with near frustum
	vPickRayOrig += vPickRayDir*NEAR_Z;

	//*****************************/
	//ASIL PICKING IN YAPILDIGI YER//
	//*****************************//
	/*
	// test for intersection
	BOOL bHit = FALSE;
	DWORD dwIndex;
	FLOAT fu;
	FLOAT fv;
	FLOAT dist;
	
	// yes, convert ray to model space
	D3DXVECTOR3 vNear,vDir;
	D3DXMATRIX invMat;
	D3DXMatrixInverse(&invMat,NULL,pIObject->pCoordMatrix);
	
	D3DXVec3TransformCoord(&vNear,&vPickRayOrig,&invMat); //Act as w=1 
	D3DXVec3TransformNormal(&vDir,&vPickRayDir,&invMat);// Act as w=0
	                               //Pos   //Direction
								
	float r = D3DXIntersect(pIObject->pMesh, &vNear, &vDir, &bHit, &dwIndex, &fu, &fv, &dist, NULL, NULL);
	
	if(bHit){

		//Bu mesafeyi alýp bi þekilde kullan!!!
		float distance = dist;
		D3DXVECTOR3* deneme = new D3DXVECTOR3(0,0,0);

		*deneme = vNear + (vDir * distance);
		
		return deneme;
	}
	
	


	//return false;
}

*/