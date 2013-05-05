/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Object.h
Version:     v0.01
Description: Abstract root class which all Chaos Engine classes inherit from

-------------------------------------------------------------------------
History:
- 03-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Utility/Macros.h"
#include "Utility/Config.h"
#include "Object/IObject.h"
#include <Windows.h>
#include <iostream>
#include <map>
#include <vector>

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Object: public IObject{

private: 
	UINT64 _objectID;

public:
	Object();
	virtual ~Object();
	virtual void release(); // Override this method

	inline UINT64 countObject();
	inline const UINT64 objectID();
	BOOL isEqual(Object *object);
};

CHAOS_ENGINE_END

#endif