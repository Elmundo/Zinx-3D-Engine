#pragma once
#ifndef MATH_H
#define MATH_H

#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

namespace Math{

	typedef D3DXVECTOR3 vector3;
	typedef D3DXMATRIX  matrix;

	//Vector implementations
	void normalize(vector3* target, vector3* source);
	void cross(vector3* target, vector3* source1, vector3* source2);
	float dot(vector3* source1, vector3* source2);

	//Vector or floating changes effect on the matrix
	void rotation(matrix* target, vector3* source1, float angle);
	void rotationX(matrix* target, float angle);
	void rotationY(matrix* target, float angle);
	void rotationZ(matrix* target, float angle);

	//Matrix effect on the vector
	void transformCoord(vector3* target, vector3* source1, matrix* source2);
	void transformNormal(vector3* target, vector3* source1, matrix* source2);

	//Matrix implementations
	float determinant(matrix* source);
	void identity(matrix* target);
	void inverse(matrix* target, float determinant, matrix* source);
	bool isIdentity(matrix* source);
	void multiply(matrix* target, matrix* source1, matrix* source2);
	void scale(matrix* target, float sx, float sy, float sz);
	void translation(matrix* target, float x, float y, float z);
	void transpoze(matrix* target, matrix* source);
	float sin(float angle);
	float cos(float angle);
	double sin(double angle);
	double cos(double angle);
}

#endif