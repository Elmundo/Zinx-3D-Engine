/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Macros.h
Version:     v0.01
Description: Define generic macros for framework

-------------------------------------------------------------------------
History:
- 2012-03-06   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __MACROS_H__
#define __MACROS_H__

/*
 *	Generic Macros
 */

#ifdef _USRDLL
	#define CHAOS_DLL _declspec(dllexport)
#else
	#define CHAOS_DLL _declspec(dllimport)
#endif

/*
 *	namespace chaos
 */

#define CHAOS_ENGINE_BEGIN    namespace chaos_engine{
#define CHAOS_ENGINE_END      }
#define USING_CHAOS_ENGINE    using namespace chaos_engine

#ifndef NULL
	#define NULL 0
#endif

/*
 *	Generic Typdefs
 */

//typedef Function *void;
//typedef implemets public; maybe later usage


#endif