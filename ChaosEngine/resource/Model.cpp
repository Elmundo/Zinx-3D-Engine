#include "resource/Model.h"

CHAOS_ENGINE_BEGIN

Model::Model()
{

}

Model::~Model(){}

void Model::release()
{
	mesh->Release();
	delete materials;
}

CHAOS_ENGINE_END