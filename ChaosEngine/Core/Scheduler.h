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

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Scheduler: public Node{
private:
	static Scheduler* _instance;

public:
	Scheduler();
	virtual ~Scheduler();

	void tick();
	virtual void release();
	static Scheduler* instance();
};

CHAOS_ENGINE_END

#endif
