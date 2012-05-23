#include "Object\Object.h"

void Object::addChild(BaseObject* obj){
	obj->m_Parent = this;
	m_Childs.push_back(obj);
}

void Object::removeChild(BaseObject* obj){
	
	obj->m_Parent = NULL;
	std::vector<BaseObject*>::iterator i;
	//TODO: i[0]-> kullanýmýnda bi sýkýntý var sonra bak,Object2D de bu sorun olmuyor
	for(i = m_Childs.begin(); i <= m_Childs.end(); ++i){
		if( !(i[0]->m_Name.compare(obj->m_Name.c_str())) ){
			i[0]->release();
			m_Childs.erase(i);
			break;
		}
	}
	return;
}


void Object::move(float x, float y, float z){
	Math::identity(&m_Translate);
	Math::translation(&m_Translate, x, y, z);
	Math::multiply(&m_Coord, &m_Coord, &m_Translate);

	m_Pos.x = m_Coord(3,0);
	m_Pos.y = m_Coord(3,1);
	m_Pos.z = m_Coord(3,2);
}

void Object::setPosition(Math::vector3 v){
	Math::identity(&m_Coord);
	Math::translation(&m_Coord, v.x, v.y, v.z);
}
/*
void Object::rotateX(float angle){
	Math::identity(&m_Rotate);
	Math::rotationX(&m_Rotate, angle);
	Math::multiply(&m_Coord, &m_Coord, &m_Rotate);
}

void Object::rotateY(float angle){
	Math::matrix T;
	Math::identity(&T);

	Math::identity(&m_Rotate);
	Math::rotationY(&m_Rotate, angle);
	Math::multiply(&m_Coord, &T, &m_Rotate);
}

void Object::rotateZ(float angle){
	Math::identity(&m_Rotate);
	Math::rotationZ(&m_Rotate, angle);
	Math::multiply(&m_Coord, &m_Coord, &m_Rotate);
}
*/
void Object::scale(float sx, float sy, float sz){
	Math::identity(&m_Scale);
	Math::scale(&m_Scale, sx, sy, sz);
	Math::multiply(&m_Coord, &m_Coord, &m_Scale);
}
void Object::scale(float s){
	Math::identity(&m_Scale);
	Math::scale(&m_Scale, s, s, s);
	Math::multiply(&m_Coord, &m_Coord, &m_Scale);
}

void Object::release(){
	m_Parent = NULL;
}

void Object::setPositionMatrix(){
	Math::normalize(&m_Look, &m_Look);
  
  	Math::cross(&m_Up, &m_Look, &m_Right);
  	Math::normalize(&m_Up, &m_Up);
  	
  	Math::cross(&m_Right, &m_Up, &m_Look);
  	Math::normalize(&m_Right, &m_Right);
	
	float x = -Math::dot(&m_Right, &m_Pos);
	float y = -Math::dot(&m_Up,    &m_Pos);
	float z = -Math::dot(&m_Look,  &m_Pos);


	m_Coord(3,0) = x;
	m_Coord(3,1) = y;
	m_Coord(3,2) = z;
	m_Coord(3,3) = 1.0f;
}

void Object::setPositionRotateMatrix(){
	Math::normalize(&m_Look, &m_Look);
  
  	Math::cross(&m_Up, &m_Look, &m_Right);
  	Math::normalize(&m_Up, &m_Up);
  	
  	Math::cross(&m_Right, &m_Up, &m_Look);
  	Math::normalize(&m_Right, &m_Right);

	m_Coord(0,0) = m_Right.x;
	m_Coord(0,1) = m_Up.x;
	m_Coord(0,2) = m_Look.x;
	m_Coord(0,3) = 0.0f;

	m_Coord(1,0) = m_Right.y;
	m_Coord(1,1) = m_Up.y;
	m_Coord(1,2) = m_Look.y;
	m_Coord(1,3) = 0.0f;

	m_Coord(2,0) = m_Right.z;
	m_Coord(2,1) = m_Up.z;
	m_Coord(2,2) = m_Look.z;
	m_Coord(2,3) = 0.0f;

}

void Object::rotateY(float angle){
	
	Math::matrix T;
	Math::identity(&T);
	Math::rotation(&T, &m_Up, angle);

 	Math::transformCoord(&m_Right, &m_Right, &T);
	Math::transformCoord(&m_Look, &m_Look, &T);

	setPositionRotateMatrix();
}

void Object::walk(float unit){
	m_Pos += m_Look * unit;

	setPositionMatrix();
}

void Object::strafe(float unit){
	m_Pos += m_Right * unit;

	setPositionMatrix();
}

void Object::addSibling(BaseObject* obj){

}

void Object::removeSibling(BaseObject* obj){

}