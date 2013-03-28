#include "Object/Object.h"

CHAOS_ENGINE_BEGIN

Object::Object()
{
	_objectID = countObject();
}

Object::~Object()
{
	_objectID = -1;
}


void Object::release()
{
	delete this;
}

inline UINT64 Object::countObject()
{
	static UINT64 s_objectID = 0;
	return s_objectID++;
}


inline const UINT64 Object::objectID()
{
	return _objectID;
}

BOOL Object::isEqual(Object *object)
{
	return (this == object) ? true : false;
}

CHAOS_ENGINE_END