#include "resource/ResourceService.h"

CHAOS_ENGINE_BEGIN

ResourceService* ResourceService::_instance;

ResourceService::ResourceService()
{

}

bool ResourceService::loadResource(std::string resourceName)
{
	_modelList.push_back(loadModel(resourceName));

	return true;
}

bool ResourceService::removeResource( std::string resourceName )
{
	std::vector<Model*>::iterator it;

	it = _modelList.begin();
	for (; it != _modelList.end(); ++it)
	{
		Model* model = (*it);
		if(model->name.compare(resourceName) == 0){
			_modelList.erase(it);
			model->release();
			model = NULL;
		}
	}

	return true;
}

Model* ResourceService::loadModel(std::string name)
{
	Model* model = new Model();
	model->name = name;

	LPD3DXBUFFER adjacencyBuffer;
	LPD3DXBUFFER materialBuffer;

	HRESULT result = D3DXLoadMeshFromX(model->name.c_str(),
		D3DXMESH_SYSTEMMEM,
		Renderer::instance()->getDevice(),
		&adjacencyBuffer,
		&materialBuffer,
		NULL,
		&model->materialNum,
		&model->mesh);

	if (result != S_OK)
		MessageBox(NULL, "Model cannot be loaded!", "ResourceService", 0);

	D3DXMATERIAL* materials = (D3DXMATERIAL*) materialBuffer->GetBufferPointer();
	model->materials = new D3DMATERIAL9[model->materialNum];

	for(UINT i = 0; i < model->materialNum; ++i){
		model->materials[i] = materials->MatD3D;
		model->materials[i].Ambient = model->materials[i].Diffuse;
	}
	
	model->info.FVF               = model->mesh->GetFVF();
	model->info.numBytesForVertex = model->mesh->GetNumBytesPerVertex();
	model->info.numFaces          = model->mesh->GetNumFaces();
	model->info.numVertices       = model->mesh->GetNumVertices();

	BYTE* vertexBuffer = 0;
	model->mesh->LockVertexBuffer(0, (void**)&vertexBuffer);

	result = D3DXComputeBoundingSphere((D3DXVECTOR3*)vertexBuffer,
				model->mesh->GetNumVertices(),
				D3DXGetFVFVertexSize(model->mesh->GetFVF()),
				&model->boundingSphere.center,
				&model->boundingSphere.radius);

	model->mesh->UnlockVertexBuffer();
	
	if (result != S_OK)
		MessageBox(NULL, "Model Bounding Sphere cannot be created!", "ResourceService", 0);

	return model;
}

bool ResourceService::loadTexture(std::string name)
{
	return true;
}

ResourceService* ResourceService::instance()
{
	if (!_instance)
		_instance = new ResourceService();

	return _instance;
}

void ResourceService::release()
{

}

ResourceService::~ResourceService()
{

}

Model* ResourceService::getModel( std::string name )
{
	std::vector<Model*>::iterator it;
	it = _modelList.begin();
	
	for (; it != _modelList.end(); ++it)
	{
		Model* model = (*it);
		if(model->name.compare(name) == 0){
			return model;
		}
	}

	return NULL;
}

/*
Model* ResourceService::getModel( std::string name )
{
	//return (Model*)_modelDic[name];
	return new Model();
}*/

CHAOS_ENGINE_END