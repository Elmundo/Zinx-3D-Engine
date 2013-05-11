#include "Object/GameObject.h"
#include "Core/ObjectManager.h"
#include <math.h>
#include "d3dx9math.h"
#include "Utility\Math.h"

CHAOS_ENGINE_BEGIN

GameObject::GameObject()
{
	_gameObjectID = countGameObject();

	_renderer        = Renderer::instance();
	_objectManager   = ObjectManager::instance();
	_resourceService = ResourceService::instance(); 

	_isModelAvailable = false;
	_isTextureAvailable  = false;

	_position.x = _position.y = _position.z = _direction.y = 0.0f;
	_direction.x = 1.0f;
	_direction.z = 1.0f;

	_texture = NULL;
	_model = NULL;

	_objectManager->addChild(this);
}

GameObject::GameObject(std::string modelName, std::string textureName="")
{
	_gameObjectID = countGameObject();

	_renderer        = Renderer::instance();
	_objectManager   = ObjectManager::instance();
	_resourceService = ResourceService::instance(); 

	_isModelAvailable = false;
	_isTextureAvailable  = false;

	_position.x = _position.y = _position.z = _direction.y = 0.0f;
	_direction.x = 1.0f;
	_direction.z = 1.0f;

	_objectManager->addChild(this);

	setResource(modelName, textureName);
}

GameObject::~GameObject() 
{
	
}


void GameObject::release()
{
	_objectManager->removeChild(this);
	
	_model->release();
	_texture->release();

	Node::release();
}

inline UINT64 GameObject::countGameObject()
{
	static UINT64 s_gameObjectID = 0;
	return s_gameObjectID++;
}

inline const UINT64 GameObject::gameObjectID()
{
	return _gameObjectID;
}

void GameObject::setResource(std::string modelName, std::string textureName){
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

	//TODO: Baris
	/*******************BUG**********************/
	/* Eðer child'larý da içinde çizdirirse zaten ObjectManager'da kayýtlý olduklarýndan tekrar çizdirilirler..
	if (_children.size() > 0)
	{
		std::vector<Node*>::iterator it;
		for (it = _children.begin(); it != _children.end(); ++it)
		{
			// Node sýnýfýnda tanýmlý olan _parent ve _children nesnelerini template tanýmla
			GameObject* obj = (GameObject*) (*it);
			obj->render();
		}
	}
	*/
}

void GameObject::setTransform()
{
	Math::matrix translation;
	Math::matrix rotation;
	//Math::matrix final;

	Math::translation(&translation, _position.x, _position.y, _position.z);
	Math::rotationY(&rotation, D3DXToRadian(_direction.y));
	Math::multiply(&_final, &rotation, &translation);
	
	/* Bu yapýyý GameObject sýnýfýný ObjectManager'dan ayýrýp root yapýsýna geçince kullan.
	if (_parent)
	{
		Math::matrix mat = ((GameObject*)_parent)->final();
		Math::multiply(&_final, &mat, &_final);
	}
	*/
	_renderer->getDevice()->SetTransform(D3DTS_WORLD, &_final);
	
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

// TODO: Shall be refactored!
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

void GameObject::rotate(float angle)
{
	_direction.y += angle;
}


void GameObject::setPosition(Math::vector3 position)
{
	_position.x = position.x;
	_position.y = position.y;
	_position.z = position.z;
}

void GameObject::setPosition(int x, int y, int z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

const Math::vector3 GameObject::position()
{
	return _position;
}

const Math::vector3 GameObject::direction()
{
	return _direction;
}

const Math::matrix GameObject::final()
{
	return _final;
}


CHAOS_ENGINE_END