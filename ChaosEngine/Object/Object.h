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
#include <Windows.h>
#include <iostream>
#include <map>
#include <vector>

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Object{

private:
	static UINT64 _objectCount; 
	UINT _objectID;

public:
	Object();
	virtual ~Object();

	static UINT64 objectCount();
	UINT objectID();
	virtual void release();
};

CHAOS_ENGINE_END

#endif