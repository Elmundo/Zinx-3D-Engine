#include "Object/Object.h"

CHAOS_ENGINE_BEGIN

// Static object
UINT64 Object::_objectCount= 0;

Object::Object()
{
	_objectID = ++_objectCount;
}

UINT64 Object::objectCount(){
	return _objectCount;
}

UINT Object::objectID()
{
	return _objectID;
}

void Object::release()
{
	delete this;
}

Object::~Object()
{
	--_objectCount;
}



CHAOS_ENGINE_END