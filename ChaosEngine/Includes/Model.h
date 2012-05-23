#pragma once
#ifndef MODEL_H
#define MODEL_H

#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <string>
#include "Utility\Math.h"

class __declspec(dllexport) BoundingSphere{
public:
	//FUNDAMENTAL MEMBERS
	//vector that shows the center
	Math::vector3 m_Center;
	float m_Radius;

	//METHODS
	BoundingSphere():m_Radius(0.0f){}
	bool computeBoundingSphere(LPD3DXMESH mesh);
};

class MeshInfo{
public:
	//FUNDAMENTAL MEMBERS
	DWORD m_FVF;
	UINT m_NumBytesForVertex;
	UINT m_NumFaces;
	UINT m_NumVertices;
};

class __declspec(dllexport) Model{
public:
	//FUNDAMENTAL MEMBERS
	//The mesh buffer
	LPD3DXMESH     m_Mesh;

	//The object that hold the mesh material data
	D3DMATERIAL9*  m_Materials;

	////Number of the mesh material
	DWORD          m_MaterialNumber;

	//Bounding sphere object
	BoundingSphere m_BoundingSphere;

	//Mesh info
	MeshInfo       m_MeshInfo;

	//Name of the model
	std::string    m_ModelName;

	//OBJECTS ARE IMPORTED FROM OUTSIDE Or DEPENDENCY OBJECTS
	//Direct3D Device
	LPDIRECT3DDEVICE9 m_d3d;

	//METHODS
	Model(std::string modelName, LPDIRECT3DDEVICE9 d3d);
	void draw();
	void release();
};

#endif