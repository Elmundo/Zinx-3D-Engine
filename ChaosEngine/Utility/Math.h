#pragma once
#ifndef MATH_H
#define MATH_H

#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <Utility/Macros.h>

CHAOS_ENGINE_BEGIN

class CHAOS_DLL Math{
public:
	typedef D3DXVECTOR3 vector3;
	typedef D3DXMATRIX  matrix;

	//Vector implementations
	static void normalize(vector3* target, vector3* source);
	static void cross(vector3* target, vector3* source1, vector3* source2);
	static float dot(vector3* source1, vector3* source2);

	//Vector or floating changes effect on the matrix
	static void rotation(matrix* target, vector3* source1, float angle);
	static void rotationX(matrix* target, float angle);
	static void rotationY(matrix* target, float angle);
	static void rotationZ(matrix* target, float angle);

	//Matrix effect on the vector
	static void transformCoord(vector3* target, vector3* source1, matrix* source2);
	static void transformNormal(vector3* target, vector3* source1, matrix* source2);

	//Matrix implementations
	static float determinant(matrix* source);
	static void identity(matrix* target);
	static void inverse(matrix* target, float determinant, matrix* source);
	static bool isIdentity(matrix* source);
	static void multiply(matrix* target, matrix* source1, matrix* source2);
	static void scale(matrix* target, float sx, float sy, float sz);
	static void translation(matrix* target, float x, float y, float z);
	static void transpoze(matrix* target, matrix* source);
	static float sin(float angle);
	static float cos(float angle);
	static double sin(double angle);
	static double cos(double angle);
};

CHAOS_ENGINE_END

#endif