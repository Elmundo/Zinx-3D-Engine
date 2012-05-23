#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <vector>
#include <iostream>
#include "Object\BaseObject.h"

class __declspec(dllexport) ObjectManager{
private:
	std::vector<BaseObject*> _ojectList;

public:
	ObjectManager(){
		
	}

}

#endif