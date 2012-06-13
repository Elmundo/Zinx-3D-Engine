/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Macros.h
Version:     v0.01
Description: Define generic macros for framework

-------------------------------------------------------------------------
History:
- 03-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __MACROS_H__
#define __MACROS_H__

#include <iostream>
#include <vector>

/*
 *	Generic Macros
 */
#ifdef _USRDLL
	#define CHAOS_DLL _declspec(dllexport)
#else
	#define CHAOS_DLL _declspec(dllimport)
#endif

/*
 *	Namespace Chaos
 */
#define CHAOS_ENGINE_BEGIN    namespace chaos_engine{
#define CHAOS_ENGINE_END      }
#define USING_CHAOS_ENGINE    using namespace chaos_engine

#ifndef NULL
	#define NULL 0
#endif

#define CE_CLEAR(p) ZeroMemory(p, sizeof(*p))

/*
 *	Generic Typedefs
 */
//#define std::vector Vector;

//typedef Function *void;
//typedef implemets public; maybe later usage


#endif