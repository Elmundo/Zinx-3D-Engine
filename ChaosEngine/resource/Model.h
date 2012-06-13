/********************************************************************
Chaos Engine Source File.
Copyright (C), Chaos Studios, 2012.
-------------------------------------------------------------------------
File name:   Model.h
Version:     v0.01
Description: Responsible for creating, managing window and windows message architecture

-------------------------------------------------------------------------
History:
- 13-06-2012   : Created by Baris YILMAZ

*********************************************************************/

#ifndef __MODEL_H__
#define __MODEL_H__

#include "Core/Renderer.h"

CHAOS_ENGINE_BEGIN

struct CHAOS_DLL MeshInfo{
public:
	DWORD FVF;
	UINT numBytesForVertex;
	UINT numFaces;
	UINT numVertices;
};

struct CHAOS_DLL BoundingSphere{
public:
	Math::vector3 center;
	FLOAT radius;
};

class CHAOS_DLL Model: public Object{
public:
	LPD3DXMESH mesh;
	D3DMATERIAL9* materials;
	DWORD materialNum;
	MeshInfo info;
	std::string name;
	BoundingSphere boundingSphere;

	Model();
	virtual ~Model();

	virtual void release();

};

CHAOS_ENGINE_END

#endif