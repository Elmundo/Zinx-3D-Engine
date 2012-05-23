#ifndef OBJECT2D
#define OBJECT2D

#include <iostream>
#include <string>
#include <vector>
#include "Utility\Math.h"
#include "Object\BaseObject.h"

class CHAOS_DLL Object2D: public BaseObject{
public:
	//FUNDAMENTAL MEMBERS
	std::string m_Name;

	Math::matrix  m_PosMatrix;
	Math::vector3 m_Pos;

	//METHODS
	void addChild(BaseObject* obj);
	void addSibling(BaseObject* obj);
	void removeChild(BaseObject* obj);
	void removeSibling(BaseObject* obj);
	void release();
	
	void move(int x, int y);
	void move(Math::vector3 v);

	//Cont. Method
	Object2D(std::string objectName);
};

#endif