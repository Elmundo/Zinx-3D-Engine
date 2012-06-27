#include "Object/GameObject.h"
#include "Core/ObjectManager.h"

CHAOS_ENGINE_BEGIN

GameObject::GameObject()
{
	_isResourceAvailable = false;
	Math::identity(&_position);
	ObjectManager::instance()->addChild(this);
}

void GameObject::setResource(std::string modelName){
	_model = ResourceService::instance()->getModel(modelName);
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
	Renderer::instance()->getDevice()->SetTransform(D3DTS_WORLD, &_position);
}

void GameObject::drawModel()
{
	if(!_isResourceAvailable || !_model->mesh)
		return;

	HRESULT result;

	for (UINT i = 0; i < _model->materialNum; ++i)
	{ 
		result = Renderer::instance()->getDevice()->SetMaterial(&_model->materials[i]);
		result = _model->mesh->DrawSubset(i);
	}
}

void GameObject::move(float x = 0.0, float y = 0.0, float z = 0.0){
	Math::matrix translate;
	
	Math::identity(&translate);
	Math::translation(&translate, x, y, z);
	Math::multiply(&_position, &_position, &translate);
}


void GameObject::release()
{
	ObjectManager::instance()->removeChild(this);

	Node::release();
}

GameObject::~GameObject()
{

}

/*
 *	Getter & Setter
 */
Math::matrix GameObject::position(){ return _position;}
Math::matrix GameObject::combined(){ return _combined;}
Math::matrix GameObject::scale(){ return _scale;}
Math::matrix GameObject::translate(){ return _translate;}
Math::matrix GameObject::rotate(){ return _rotate;}
Math::vector3 GameObject::direction(){ return _direction;}

CHAOS_ENGINE_END