#ifndef __MACROS_H__
#define __MACROS_H__

#ifdef _USRDLL
	#define CHAOS_DLL _declspec(dllexport)
#else
	#define CHAOS_DLL _declspec(dllimport)
#endif


#endif