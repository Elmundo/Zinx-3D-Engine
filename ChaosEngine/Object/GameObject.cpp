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

	_isModelAvailable = false;
	_isTextureAvailable  = false;
	_position.x = _position.y = _position.z = _direction.y = 0.0f;
	_direction.x = 1.0f;
	_direction.z = 1.0f;

	_objectManager->addChild(this);
}

void GameObject::setResource(std::string modelName, std::string textureName=""){
	_model   = _resourceService->getModel(modelName);

	if (textureName.c_str())	
		_texture = _resourceService->getTexture(textureName);

	if(_model) 
		_isModelAvailable = true;

	if(_texture)
		_isTextureAvailable = true;
}

void GameObject::render()
{
	setTransform();
	drawTexture();
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
	if(!_isModelAvailable || !_model->mesh)
		return;

	HRESULT result;
	for (UINT i = 0; i < _model->materialNum; ++i)
	{ 
		result = _renderer->getDevice()->SetMaterial(&_model->materials[i]);
		result = _model->mesh->DrawSubset(i);
	}
}

void GameObject::drawTexture(){
	if (_texture)
		_renderer->getDevice()->SetTexture(0, _texture->texture);
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