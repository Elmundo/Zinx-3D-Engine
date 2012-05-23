#include "Camera\Camera.h"

void Camera::setViewMatrix()
{
	// Keep Camera's axes orthogonal to each other:
	//D3DXVec3Normalize(&look, &look);
	//My Design, from utiliy
  	Math::normalize(&look, &look);
  
  	Math::cross(&up, &look, &right);
  	Math::normalize(&up, &up);
  	
  	Math::cross(&right, &up, &look);
  	Math::normalize(&right, &right);
  	
  	//Burayý anlamadým
  	float x = -Math::dot(&right, &pos);
  	float y = -Math::dot(&up, &pos);
  	float z = -Math::dot(&look, &pos);
  
  	(*matrixView)(0, 0) = right.x;
  	(*matrixView)(0, 1) = up.x;
  	(*matrixView)(0, 2) = look.x;
  	(*matrixView)(0, 3) = 0.0f;
  	
  	(*matrixView)(1, 0) = right.y;
  	(*matrixView)(1, 1) = up.y;
  	(*matrixView)(1, 2) = look.y;
  	(*matrixView)(1, 3) = 0.0f;
  	
  	(*matrixView)(2, 0) = right.z;
  	(*matrixView)(2, 1) = up.z;
  	(*matrixView)(2, 2) = look.z;
  	(*matrixView)(2, 3) = 0.0f;
  	
  	(*matrixView)(3, 0) = x;
  	(*matrixView)(3, 1) = y;
  	(*matrixView)(3, 2) = z;
  	(*matrixView)(3, 3) = 1.0f;
	
	//Transform the view state
	pDirect3DDevice->SetTransform(D3DTS_VIEW, matrixView);
}

//Kameranýn yukarý aþaðý bakmasý
void Camera::pitch(float angle)
{
	Math::matrix T;
	Math::rotation(&T, &right, angle * SystemTime::deltaTime);
	
	// rotate up and look around right vector
	Math::transformCoord(&up,&up, &T);
	Math::transformCoord(&look,&look, &T);

	setViewMatrix();
}
//Kameranýn saða sola bakmasý
void Camera::yaw(float angle)
{
	Math::matrix T;
	// rotate around world y (0, 1, 0) always for land object
	if(cameraType == LANDOBJECT )
		Math::rotationY(&T, angle * SystemTime::deltaTime);
	
	// rotate around own up vector for aircraft
	if( cameraType == AIRCRAFT )
		Math::rotationY(&T, angle * SystemTime::deltaTime);
		//D3DXMatrixRotationAxis(&T, &up, angle * SystemTime::deltaTime);
	
	// rotate right and look around up or y-axis
	Math::transformCoord(&right,&right, &T);
	Math::transformCoord(&look,&look, &T);
	
	setViewMatrix();
}

void Camera::roll(float angle)
{
	// only roll for aircraft type
	if( cameraType == AIRCRAFT )
	{
		Math::matrix T;
		Math::rotation(&T, &look, angle * SystemTime::deltaTime);
		
		// rotate up and right around look vector
		Math::transformCoord(&right,&right, &T);
		Math::transformCoord(&up,&up, &T);

		setViewMatrix();
	}
}
//Ýleri-Geri hareketi
void Camera::walk(float units)
{
	// move only on xz plane for land object
	if(cameraType == LANDOBJECT)
		//pos += D3DXVECTOR3(look.x, 0.0f, look.z) * units * SystemTime::deltaTime;
		pos += look * units * SystemTime::deltaTime;
	if( cameraType == AIRCRAFT )
		pos += look * units * SystemTime::deltaTime;

	setViewMatrix();
}
//Saða-sola gitme hareketi
void Camera::strafe(float units)
{
	// move only on xz plane for land object
	if( cameraType == LANDOBJECT )
		//pos += Math::vector3(right.x, 0.0f, right.z) * units * SystemTime::deltaTime;
		pos += right * units * SystemTime::deltaTime;
	if( cameraType == AIRCRAFT )
		pos += right * units * SystemTime::deltaTime;

	setViewMatrix();
}

void Camera::fly(float units)
{
	if( cameraType == AIRCRAFT || cameraType == LANDOBJECT)
		pos += up * units * SystemTime::deltaTime;

	setViewMatrix();
}

//i'm not using this method yet
void Camera::normalize(){

	//Normalize the cam
	right = Math::vector3(1,0,0);
	up    = Math::vector3(0,1,0);
	look  = Math::vector3(0,0,1);
	pos   = Math::vector3(0,0,0);

	setViewMatrix();
}

Camera* Camera::getCamera(){
	return this;
}

Math::vector3* Camera::getCameraPosition(){
	return &pos;
}