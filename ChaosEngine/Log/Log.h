#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>
#include <typeinfo>
#include "Utility\ClassHelper.h"
#include <Utility/Macros.h>

//Singleton pattern class
class CHAOS_DLL Log{
private:
	static Log* _instance;
	std::fstream _logFile;
	
	Log(){
		_logFile.open("EngineLog.txt", std::fstream::out);
		
		if(!_logFile.is_open()){
			throw false; //Throw an exception here, use LogException instead of boolean value
		}

		//info(ClassHelper::getClassName(this), "Log()", "Log system is initialized!");
	}

	virtual ~Log(){
		_logFile.close();
	}
public:
	void debug(std::string className, std::string methodName, std::string message);
	void error(std::string className, std::string methodName, std::string message);
	void info(std::string className, std::string methodName, std::string message);
	void warn(std::string className, std::string methodName, std::string message);

	static Log* instance(){
		if(!_instance)
			return _instance = new Log();
		return _instance;
	}
};

#endif