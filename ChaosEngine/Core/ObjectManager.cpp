#include "Core/ObjectManager.h"

CHAOS_ENGINE_BEGIN

ObjectManager* ObjectManager::_instance;

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::release()
{
	std::vector<GameObject*>::iterator it;
	for (it = _root.begin(); it != _root.end(); ++it)
		(*it)->release();
	_root.clear();

	Object::release();
}

void ObjectManager::addChild( GameObject* gameObject )
{
	_root.push_back(gameObject);
}

void ObjectManager::removeChild( GameObject* gameObject )
{
	std::vector<GameObject*>::iterator it;
	it = _root.begin();

	for (; it != _root.end(); ++it)
	{
		if ((*it) == gameObject)
		{
			(*it)->release();
			_root.erase(it);
		}
	}
}

void ObjectManager::visit()
{
	std::vector<GameObject*>::iterator it;
	for (it = _root.begin(); it != _root.end(); ++it)
	{
		(*it)->render();
	}
}

ObjectManager* ObjectManager::instance()
{
	if (!_instance)
		_instance = new ObjectManager();

	return _instance;
}

CHAOS_ENGINE_END