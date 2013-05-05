/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   UpdatedObject.h
Version:     v0.01
Description: Responsible for creating, managing window and windows message architecture

-------------------------------------------------------------------------
History:
- 17-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __UPDATED_OBJECT_H__
#define __UPDATED_OBJECT_H__

#include "Object/GameObject.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL UpdatedObject: public GameObject{
private:

public:
	UpdatedObject();
	virtual ~UpdatedObject();

	virtual void update();
	virtual void release();
};

CHAOS_ENGINE_END

#endif