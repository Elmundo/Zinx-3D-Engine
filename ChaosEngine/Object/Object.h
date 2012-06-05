/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Object.h
Version:     v0.01
Description: Abstract root class which all Chaos Engine classes inherit from

-------------------------------------------------------------------------
History:
- 2012-03-06   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Utility/Macros.h"
#include <Windows.h>

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Object{

private:
	static UINT64 _objectID; 

public:

	Object();
	virtual ~Object();

	virtual void onAdd();
	virtual void onRemove();

	static UINT64 objectID();

};

CHAOS_ENGINE_END

#endif