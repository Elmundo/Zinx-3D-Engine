#include "Core/ObjectManager.h"

CHAOS_ENGINE_BEGIN

ObjectManager* ObjectManager::_instance;

ObjectManager::ObjectManager()
{

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
			_root.erase(it);
			//gameObject->release(); //Not sure of it
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

void ObjectManager::release()
{
	_root.clear();

	Object::release();
}

ObjectManager::~ObjectManager()
{

}

CHAOS_ENGINE_END