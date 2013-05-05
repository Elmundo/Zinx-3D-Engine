/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   IObject.h
Version:     v0.01
Description: Interface for Object class

-------------------------------------------------------------------------
History:
- 10-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __IOBJECT_H__
#define __IOBJECT_H__

#include "Utility/Macros.h"
#include "Utility/Config.h"

CHAOS_ENGINE_BEGIN

/* Interface */
class CHAOS_DLL IObject{
public:
	virtual void release() = 0;
};

CHAOS_ENGINE_END

#endif