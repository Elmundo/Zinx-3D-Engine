/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   ObjectManager.h
Version:     v0.01
Description: Manager which control a lot of thing

-------------------------------------------------------------------------
History:
- 03-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include <Object/GameObject.h>

CHAOS_ENGINE_BEGIN

class CHAOS_DLL ObjectManager: public Object{
private:
	static ObjectManager* _instance;

	std::vector<GameObject*> _root;

public:
	ObjectManager();
	virtual ~ObjectManager();

	void addChild(GameObject* gameObject);
	void removeChild(GameObject* gameObject);
	void visit();

	virtual void release();
	static ObjectManager* instance();
};

CHAOS_ENGINE_END


#endif