#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>

#include "Object\BaseObject.h"
#include "Utility\Math.h"

class CHAOS_DLL Object: public BaseObject{
public:
	//FUNDAMENTAL MEMBERS
	std::string m_Name;
	std::string m_TextureName;

	//METHODS
	void addChild(BaseObject* obj);
	void addSibling(BaseObject* obj);
	void removeChild(BaseObject* obj);
	void removeSibling(BaseObject* obj);
	void release();

	void rotate(Math::vector3 &vector, float angle);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	void scale(float sx, float sy, float sz);
	void scale(float s);

	void move(Math::vector3 mov);
	void move(Math::matrix move);//Not sure about this one
	void move(float x, float y, float z);
	void setPosition(Math::vector3 v);

	void walk(float unit);
	void strafe(float unit);

	void setPositionMatrix();
	void setPositionRotateMatrix();

	//Cont. Method
	Object(std::string objectName, std::string textureName){
		
		m_Name = objectName;
		m_TextureName = textureName;
		
		Math::identity(&m_Scale);
		Math::identity(&m_Translate);
		Math::identity(&m_Rotate);
		Math::identity(&m_Coord);

		Math::translation(&m_Coord, 0, 0, 0);

		m_Right = Math::vector3(1,0,0);
		m_Up    = Math::vector3(0,1,0);
		m_Look  = Math::vector3(0,0,1);
		m_Pos   = Math::vector3(0,0,0);
	}
};

#endif