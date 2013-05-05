/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   IRenderable.h
Version:     v0.01
Description: Renderable object must be implement this Interface. Therefore this interface,
we do not need to inherit an object from GameObject class that to be renderable.

-------------------------------------------------------------------------
History:
- 04-05-2013   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __IRENDERABLE_H__
#define __IRENDERABLE_H__

#include "Utility/Macros.h"

CHAOS_ENGINE_BEGIN

/* Interface */
class CHAOS_DLL IRenderable
{
public:
	virtual void render() = 0;
};

CHAOS_ENGINE_END
#endif