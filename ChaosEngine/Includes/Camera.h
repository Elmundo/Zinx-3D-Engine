#ifndef CAMERA_H
#define CAMERA_H

#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
#include <windows.h>
#include "Utility\SystemTime.h"
#include "Utility\Math.h"

class __declspec(dllexport) Camera{
public:
	
	//Bu enum da CameraEnum header dosyasýnýn içerisinde olacka ve include ile dahil edilecek
	enum CameraType{LANDOBJECT, AIRCRAFT};
	
	LPDIRECT3DDEVICE9 pDirect3DDevice;
	CameraType  cameraType;
	
	Math::matrix* matrixView;

	Math::vector3 right;
	Math::vector3 up;
	Math::vector3 look;
	Math::vector3 pos;

	Camera(LPDIRECT3DDEVICE9 pDirect3DDevice,CameraType cType = LANDOBJECT){
		
		this->pDirect3DDevice = pDirect3DDevice;

		cameraType = cType;
		matrixView = new D3DXMATRIX;

		//Init the orthogonal and pos vectors
		right = Math::vector3(1,0,0);
		up    = Math::vector3(0,1,0);
		look  = Math::vector3(0,0,1);
		pos   = Math::vector3(0,0,0);

		setViewMatrix();
	}

	//Additional
	void strafe(float units); //left/right
	void fly(float units);    //up/down
	void walk(float units);   //backward/forward

	void pitch(float angle);  //rotate on right vector
	void roll(float angle);   //rotate on look vector
	void yaw(float angle);    //rotate on up vectors

	void normalize();         //Normalize the vector

	void setViewMatrix();
	void setCameraType(CameraType cameraType);
	
	void getPosition(Math::vector3* pos);
	void setPosition(Math::vector3* pos);
	
	void getRight(Math::vector3* right);
	void getUp(Math::vector3* up);
	void getLook(Math::vector3* look);

	//Getter&Setter
	Camera* getCamera();
	Math::vector3* getCameraPosition();
	Math::vector3* getCameraRight();
	Math::vector3* getCameraUp();

	//Get each matrix 
	Math::matrix* getViewMatrix() const;
	Math::matrix* getProjectionMatrix() const;
	Math::matrix* getWorldMatrix() const;

};

#endif