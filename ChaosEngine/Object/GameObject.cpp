#include "Object/GameObject.h"
#include "Core/ObjectManager.h"
#include <math.h>
#include "d3dx9math.h"

CHAOS_ENGINE_BEGIN

GameObject::GameObject()
{
	_renderer        = Renderer::instance();
	_objectManager   = ObjectManager::instance();
	_resourceService = ResourceService::instance(); 

	_isResourceAvailable = false;
	_position.x = _position.y = _position.z = _direction.y = 0.0f;
	_direction.x = 1.0f;
	_direction.z = 1.0f;

	_objectManager->addChild(this);
}

void GameObject::setResource(std::string modelName){
	_model = _resourceService->getModel(modelName);
	if(_model)
		_isResourceAvailable = true;
}

void GameObject::render()
{
	setTransform();
	drawModel();
}

void GameObject::setTransform()
{
	Math::matrix translation;
	Math::matrix rotation;

	Math::translation(&translation, _position.x, _position.y, _position.z);
	Math::rotationY(&rotation, D3DXToRadian(_direction.y));
	Math::multiply(&translation, &rotation, &translation);

	_renderer->getDevice()->SetTransform(D3DTS_WORLD, &translation);
}

void GameObject::drawModel()
{
	if(!_isResourceAvailable || !_model->mesh)
		return;

	HRESULT result;

	for (UINT i = 0; i < _model->materialNum; ++i)
	{ 
		result = _renderer->getDevice()->SetMaterial(&_model->materials[i]);
		result = _model->mesh->DrawSubset(i);
	}
}

void GameObject::move(DirectionEnum direction){

	if (direction == DirectionEnum::BACKWARD) {

		_direction.x = -MOVE_RATE;
		_position.x -= _direction.x * -sin(D3DXToRadian(_direction.y));
		_position.z += _direction.x * cos(D3DXToRadian(_direction.y));

	}else if (direction == DirectionEnum::FORWARD) {

		_direction.x = MOVE_RATE;
		_position.x -= _direction.x * -sin(D3DXToRadian(_direction.y));
		_position.z += _direction.x * cos(D3DXToRadian(_direction.y));

	}else if (direction == DirectionEnum::RIGHT) {

		_direction.y += 5.0f;

	}else if (direction == DirectionEnum::LEFT) {

		_direction.y -= 5.0f;
	}

}

void GameObject::release()
{
	_objectManager->removeChild(this);

	Node::release();
}

GameObject::~GameObject() {}

/*
 *	Getter & Setter
 */
Math::vector3 GameObject::direction(){ return _direction;}

CHAOS_ENGINE_END