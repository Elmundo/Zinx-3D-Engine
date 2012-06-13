#include "Log/Log.h"

CHAOS_ENGINE_BEGIN

void Log::debug(std::string className, std::string method, std::string message){
	if(_logFile.good()){
		std::string logExpression;
		logExpression = "DEBUG:[Class:"+className+"] - " + "[Method: "+method+"] - " + "[Message:"+message+"]\n";
		_logFile << logExpression;
	}
	else
		throw false; //use LogException instead of boolean value
}

void Log::error(std::string className, std::string method, std::string message){
	if(_logFile.good()){
		std::string logExpression;
		logExpression = "ERROR:[Class:"+className+"] - " + "[Method: "+method+"] - " + "[Message:"+message+"]\n";
		_logFile << logExpression;
	}
	else
		throw false; //use LogException instead of boolean value
}

void Log::info(std::string className, std::string method, std::string message){
	if(_logFile.good()){
		std::string logExpression;
		logExpression = "INFO:[Class:"+className+"] - " + "[Method: "+method+"] - " + "[Message:"+message+"]\n";
		_logFile << logExpression;
	}
	else
		throw false; //use LogException instead of boolean value
}

void Log::warn(std::string className, std::string method, std::string message){
	if(_logFile.good()){
		std::string logExpression;
		logExpression = "WARN:[Class:"+className+"] - " + "[Method: "+method+"] - " + "[Message:"+message+"]\n";
		_logFile << logExpression;
	}
	else
		throw false; //use LogException instead of boolean value
}

Log* Log::_instance = NULL;

CHAOS_ENGINE_END