/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   IUpdatedObject.h
Version:     v0.01
Description: Interface for UpdatedObject class

-------------------------------------------------------------------------
History:
- 10-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __IUPDATED_OBJECT_H__
#define __IUPDATED_OBJECT_H__

#include "Utility/Macros.h"
#include "Utility/Config.h"
#include "Object/IObject.h"

CHAOS_ENGINE_BEGIN

/* Interface */
class CHAOS_DLL IUpdatedObject: public IObject{
public:
	virtual void update() = 0;
};

CHAOS_ENGINE_END

#endif