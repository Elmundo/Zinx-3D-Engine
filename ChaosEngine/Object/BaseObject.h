#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include "Utility\Math.h"
#include <Utility/Macros.h>

//Abstract Class
class CHAOS_DLL BaseObject{
public:
	BaseObject* m_Parent; //There will be only one parent for each object
	std::vector<BaseObject*> m_Childs; //There could be one or mode child object for each object

	std::string m_Name;

	Math::matrix m_Scale;
	Math::matrix m_Translate;
	Math::matrix m_Rotate;

	Math::matrix m_Coord;
	Math::matrix m_Combined;

	Math::vector3 m_Right;
	Math::vector3 m_Up;
	Math::vector3 m_Look;
	Math::vector3 m_Pos;

	Math::vector3 m_Direction;

	//METHODS//
	virtual void addChild(BaseObject* obj){};
	virtual void addSibling(BaseObject* obj){};
	virtual void removeChild(BaseObject* obj){};
	virtual void removeSibling(BaseObject* obj){};
	virtual void release(){};
	
};

#endif