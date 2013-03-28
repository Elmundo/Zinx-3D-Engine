/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Scheduler.h
Version:     v0.01
Description: Responsible for creating, managing window and windows message architecture

-------------------------------------------------------------------------
History:
- 10-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "Object/Node.h"
#include "Object/UpdatedObject.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Scheduler: public Object{
private:
	static Scheduler* _instance;

	std::vector<UpdatedObject*> _updatedList;

public:
	Scheduler();
	virtual ~Scheduler();
	virtual void release();

	void tick();
	void addChild(UpdatedObject* object);
	void removeChild(UpdatedObject* object);

	static Scheduler* instance();
};

CHAOS_ENGINE_END

#endif
