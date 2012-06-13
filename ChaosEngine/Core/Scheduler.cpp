#include "Core/Scheduler.h"

CHAOS_ENGINE_BEGIN

Scheduler* Scheduler::_instance;

Scheduler::Scheduler(){
	// do stuff
}

void Scheduler::tick()
{
	// do some stuff
}

Scheduler* Scheduler::instance()
{
	if (!_instance)
		_instance = new Scheduler();

	return _instance;
}

void Scheduler::release()
{
	delete this;
}

Scheduler::~Scheduler()
{
	// do some stuff
}



CHAOS_ENGINE_END

