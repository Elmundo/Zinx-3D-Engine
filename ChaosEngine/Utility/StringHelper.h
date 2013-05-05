/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   StringHelper.h
Version:     v0.01
Description: Provide helper method to handle string operations

-------------------------------------------------------------------------
History:
- 04-03-2013   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __STRING_HELPER__
#define __STRING_HELPER__ 

#include <string>
#include "Utility\Macros.h"

#define SLASH "/"
#define START_POSITION 0

class CHAOS_DLL StringHelper
{
public:
	static std::string cutFilePathname(std::string sourceName)
	{
		size_t targetPosition = sourceName.find_last_of(SLASH);
		sourceName.erase(START_POSITION, targetPosition + 1);
		return sourceName;
	}
};

#endif