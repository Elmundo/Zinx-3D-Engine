#include "Object/GameObject.h"
#include "Core/ObjectManager.h"

CHAOS_ENGINE_BEGIN

GameObject::GameObject()
{
	ObjectManager::instance()->addChild(this);
}

GameObject::GameObject(std::string modelName)
{
	Math::identity(&_position);

	ObjectManager::instance()->addChild(this);
	_model = ResourceService::instance()->getModel(modelName);
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
	if(!_model || !_model->mesh)
		return;

	HRESULT result;

	for (UINT i = 0; i < _model->materialNum; ++i)
	{ 
		result = Renderer::instance()->getDevice()->SetMaterial(&_model->materials[i]);
		result = _model->mesh->DrawSubset(i);
	}
}


void GameObject::release()
{
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