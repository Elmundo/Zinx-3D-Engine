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
	std::vector<IRenderable*>::iterator it;
	for (it = _root.begin(); it != _root.end(); ++it)
	{
		IObject *object = (IObject*)(*it);
		object->release();
	}

	_root.clear();

	Object::release();
}

void ObjectManager::addChild(IRenderable* gameObject )
{
	_root.push_back(gameObject);
}

void ObjectManager::removeChild(IRenderable* gameObject )
{
	std::vector<IRenderable*>::iterator it;
	it = _root.begin();

	for (; it != _root.end(); ++it)
	{
		if ((*it) == gameObject)
		{
			IObject *object = (IObject*)(*it);
			object->release();
			_root.erase(it);
			break;
		}
	}
}

void ObjectManager::visit()
{
	std::vector<IRenderable*>::iterator it;
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