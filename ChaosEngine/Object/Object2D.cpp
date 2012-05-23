#include "Object\Object2D.h"

Object2D::Object2D(std::string objectName){
		
	m_Name = objectName;
		
	m_Pos.x = 0;
	m_Pos.y = 0;
	m_Pos.z = 0;

	Math::identity(&m_PosMatrix);
	Math::translation(&m_PosMatrix, m_Pos.x, m_Pos.y, m_Pos.z);
}

void Object2D::addChild(BaseObject* obj){
	obj->m_Parent = this;
	m_Childs.push_back(obj);
}

void Object2D::removeChild(BaseObject* obj){
	
	obj->m_Parent = NULL;
	std::vector<BaseObject*>::iterator i;

	for(i = m_Childs.begin(); i <= m_Childs.end(); ++i){
		if( !((*i)->m_Name.compare(obj->m_Name.c_str())) ){
			(*i)->release();
			m_Childs.erase(i);
			break;
		}
	}
	return;
}

void Object2D::addSibling(BaseObject* obj){

}

void Object2D::removeSibling(BaseObject* obj){

}

void Object2D::move(int x, int y){
	Math::translation(&m_PosMatrix, x, y, 0);
}

void Object2D::move(Math::vector3 v){
	Math::translation(&m_PosMatrix, v.x, v.y, v.z);
}

void Object2D::release(){

}
