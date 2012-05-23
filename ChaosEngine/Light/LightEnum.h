#pragma once
#ifndef LIGHTENUM_H
#define LIGHTENUM_H

#include <Utility/Macros.h>

enum CHAOS_DLL LightEnum{
	LIGHT_POINT = 0,
	LIGHT_DIRECTIONAL,
	LIGHT_SPECULAR,
	LIGHT_SPOT
};

#endif