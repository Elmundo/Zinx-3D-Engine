#ifndef CLASS_HELPER_H
#define CLASS_HELPER_H

#include <iostream>

class __declspec(dllexport) ClassHelper{

public:
	template<class T> 
	static std::string getClassName(T unknown){
		std::string className;
		className = typeid(unknown).name();
		className.erase(0,6); //erase Class prefix from our expression
		return className;
	}

	virtual ~ClassHelper(){}
};
//ClassHelper* ClassHelper::_instance = NULL;
#endif