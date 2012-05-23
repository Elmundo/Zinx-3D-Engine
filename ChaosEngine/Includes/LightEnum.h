#pragma once
#ifndef LIGHTENUM_H
#define LIGHTENUM_H

enum __declspec(dllexport) LightEnum{
	LIGHT_POINT = 0,
	LIGHT_DIRECTIONAL,
	LIGHT_SPECULAR,
	LIGHT_SPOT
};

#endif