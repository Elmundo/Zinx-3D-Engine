#include "Object/Object.h"

CHAOS_ENGINE_BEGIN

// Static object
UINT64 Object::_objectID = 0;

Object::Object()
{
	_objectID++;
}

UINT64 Object::objectID(){
	return _objectID;
}

void Object::onAdd()
{

}

void Object::onRemove()
{

}

Object::~Object()
{
	// Do some stuff
}

CHAOS_ENGINE_END