#include "Core/Scheduler.h"

CHAOS_ENGINE_BEGIN

Scheduler* Scheduler::_instance;

Scheduler::Scheduler(){
	// do stuff
}

void Scheduler::tick()
{
	std::vector<UpdatedObject*>::iterator it; 
	it = _updatedList.begin();
	for (; it != _updatedList.end(); ++it)
		(*it)->update();
}

void Scheduler::addChild( UpdatedObject* object )
{
	_updatedList.push_back(object);
}

void Scheduler::removeChild( UpdatedObject* object )
{
	std::vector<UpdatedObject*>::iterator it;
	it = _updatedList.begin();

	for (; it != _updatedList.end(); ++it)
		if ((*it) == object) {
			_updatedList.erase(it);
			break;
		}
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

