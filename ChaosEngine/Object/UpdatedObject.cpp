#include "UpdatedObject.h"
#include "Core/Scheduler.h"

CHAOS_ENGINE_BEGIN

UpdatedObject::UpdatedObject()
{
	Scheduler::instance()->addChild(this);
}

void UpdatedObject::update()
{
	// override this method
}

void UpdatedObject::release(){
	Scheduler::instance()->removeChild(this);	

	GameObject::release();
}

UpdatedObject::~UpdatedObject()
{

}

CHAOS_ENGINE_END