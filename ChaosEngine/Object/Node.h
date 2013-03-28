/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Node.h
Version:     v0.01
Description: Responsible for creating, managing window and windows message architecture

-------------------------------------------------------------------------
History:
- 10-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __NODE_H__
#define __NODE_H__

#include "Object/Object.h"

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Node: public Object{
protected:
	Node* _parent;
	std::vector<Node*> _children;

public:
	Node();
	virtual ~Node();
	virtual void release();

	void addChild(Node* object);
	void removeChild(Node* object);
	inline const std::vector<Node*> children();
	inline const Node* parent();
};

CHAOS_ENGINE_END

#endif 
