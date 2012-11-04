#include "Camera/Camera.h"
#include "Core/Renderer.h"

CHAOS_ENGINE_BEGIN

Camera* Camera::_instance;

Camera::Camera()
{
	_renderer = Renderer::instance();

	_right		    = Math::vector3(1,0,0);
	_up		    	= Math::vector3(0,1,0);
	_look			= Math::vector3(0,0,1);
	_cameraPosition = Math::vector3(0,20,0);

	setView();
}

Camera* Camera::instance()
{
	if (!_instance)
		_instance = new Camera();

	return _instance;
}

void Camera::setView()
{
	Math::normalize(&_look, &_look);

	Math::cross(&_up, &_look, &_right);
	Math::normalize(&_up, &_up);

	Math::cross(&_right, &_up, &_look);
	Math::normalize(&_right, &_right);

	//Why so serious?
	float x = -Math::dot(&_right, &_cameraPosition);
	float y = -Math::dot(&_up, &_cameraPosition);
	float z = -Math::dot(&_look, &_cameraPosition);

	(_view)(0, 0) = _right.x;
	(_view)(0, 1) = _up.x;
	(_view)(0, 2) = _look.x;
	(_view)(0, 3) = 0.0f;

	(_view)(1, 0) = _right.y;
	(_view)(1, 1) = _up.y;
	(_view)(1, 2) = _look.y;
	(_view)(1, 3) = 0.0f;

	(_view)(2, 0) = _right.z;
	(_view)(2, 1) = _up.z;
	(_view)(2, 2) = _look.z;
	(_view)(2, 3) = 0.0f;

	(_view)(3, 0) = x;
	(_view)(3, 1) = y;
	(_view)(3, 2) = z;
	(_view)(3, 3) = 1.0f;
	
	//Transform the view state
	_renderer->setTransform(&_view);
}

void Camera::pitch( float angle )
{
	Math::matrix transform;
	Math::rotation(&transform, &_right, angle);

	// rotate up and look around right vector
	Math::transformCoord(&_up,&_up, &transform);
	Math::transformCoord(&_look,&_look, &transform);

	setView();
}

void Camera::yaw( float angle )
{
	Math::matrix transform;
	Math::rotationY(&transform, angle);

	// rotate right and look around up or y-axis
	Math::transformCoord(&_right,&_right, &transform);
	Math::transformCoord(&_look,&_look, &transform);

	setView();
}

void Camera::roll( float angle )
{
	//later
}

void Camera::walk( float unit )
{
	_cameraPosition += _look * unit;

	setView();
}

void Camera::strafe( float unit )
{
	_cameraPosition += _right * unit;

	setView();
}

void Camera::fly( float unit )
{
	_cameraPosition += _up * unit;

	setView();
}

Math::matrix Camera::view()
{
	return _view;
}

Math::vector3 Camera::right()
{
	return _right;
}

Math::vector3 Camera::up()
{
	return _up;
}

Math::vector3 Camera::look()
{
	return _look;
}

Math::vector3 Camera::cameraPosition()
{
	return _cameraPosition;
}

void Camera::release()
{
	Object::release();
}

Camera::~Camera()
{

}

CHAOS_ENGINE_END

