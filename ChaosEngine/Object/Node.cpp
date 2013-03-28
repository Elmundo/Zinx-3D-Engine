#include "Object/Node.h"

CHAOS_ENGINE_BEGIN

Node::Node()
{
	_parent = NULL;
	_children.clear();
}

Node::~Node()
{

}

void Node::release()
{
	_parent = NULL;

	// Change with FOR_EACH_CLEAN
	std::vector<Node*>::iterator iter;
	for (iter = _children.begin(); iter != _children.end(); ++iter )
		(*iter)->release();
	_children.clear();

	Object::release();
}

void Node::addChild(Node* object)
{
	object->_parent = this;
	_children.push_back(object);
}

void Node::removeChild(Node* object)
{
	//Needed a FOR_EACH(_children, release)
	std::vector<Node*>::iterator iter;
	for (iter = _children.begin(); iter != _children.end(); ++iter )
	{
		if ( (*iter)->isEqual(object) )
		{
			_children.erase(iter);
			object->release();
			break;
		}
	}
}

CHAOS_ENGINE_END
