#include "Object/Node.h"

CHAOS_ENGINE_BEGIN

Node::Node()
{

}

void Node::addChild(Node* object)
{
	_children.push_back(object);
}

void Node::removeChild(Node* object)
{
	std::vector<Node*>::iterator iter;
	for (iter = _children.begin(); iter != _children.end(); ++iter )
	{
		if ( (*iter)->objectID() == object->objectID() )
		{
			_children.erase(iter);
			object->release();
			break;
		}
	}
}

/*
 *	Override this method in subclass
 */
void Node::release()
{
	Object::release();
}

/*
 *	Override this method in subclass
 */
Node::~Node()
{

}

CHAOS_ENGINE_END
