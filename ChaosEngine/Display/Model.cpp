#include "Display\Model.h"

Model::Model(std::string modelName, LPDIRECT3DDEVICE9 d3d){

	//Assign model's name and d3d
	m_ModelName = modelName;
	m_d3d       = d3d;

	//Adjacenct Buffer
	LPD3DXBUFFER adjacencyBuffer;
	LPD3DXBUFFER materialBuffer;

	//Function that load the mesh data from the 3D model
	HRESULT hr = D3DXLoadMeshFromX(m_ModelName.c_str(), //name of model
					  D3DXMESH_SYSTEMMEM,  //Type of mesh system
					  m_d3d,               //Parameter from Direct3D class - Output object
					  &adjacencyBuffer,
					  &materialBuffer,
					  NULL,
					  &m_MaterialNumber,   //Material number
					  &m_Mesh);            //Object that hold the mesh data
	if(hr != S_OK){
		MessageBox(NULL, "Something has gone wrong!", "Error", 0);
	}

	//Every material attributes is assigining to m_Materials
	D3DXMATERIAL* materials = (D3DXMATERIAL*) materialBuffer->GetBufferPointer();

	//Allocate the memory size of material object
	m_Materials = new D3DMATERIAL9[m_MaterialNumber];

	//The mesh material data is getting from materials to the m_Materials
	for(DWORD i = 0; i < m_MaterialNumber; ++i){
		
		m_Materials[i] = materials->MatD3D;

		//DirectX do not do this automaticly
		m_Materials[i].Ambient = m_Materials[i].Diffuse;

	}

	//Fill the mesh info object
	m_MeshInfo.m_FVF               = m_Mesh->GetFVF();
	m_MeshInfo.m_NumBytesForVertex = m_Mesh->GetNumBytesPerVertex();
	m_MeshInfo.m_NumFaces          = m_Mesh->GetNumFaces();
	m_MeshInfo.m_NumVertices       = m_Mesh->GetNumVertices();

	//Compute the bounding sphere of the model
	m_BoundingSphere.computeBoundingSphere(m_Mesh);
}

//Compute the bounding sphere
bool BoundingSphere::computeBoundingSphere(LPD3DXMESH mesh){
	HRESULT hr         = 0;
	BYTE* vertexBuffer = 0;

	mesh->LockVertexBuffer(0, (void**)&vertexBuffer);

	hr = D3DXComputeBoundingSphere((D3DXVECTOR3*)vertexBuffer,
		                           mesh->GetNumVertices(),
								   D3DXGetFVFVertexSize(mesh->GetFVF()),
								   &m_Center,
								   &m_Radius);
	mesh->UnlockVertexBuffer();

	if(FAILED(hr))
		return false;
	
	return true;
}

void Model::release(){
	
	m_Mesh->Release();
	delete m_Materials;

	m_Mesh      = NULL;
	m_Materials = NULL;
}

void Model::draw(){
	for(DWORD i = 0; i < m_MaterialNumber; ++i){
		m_d3d->SetMaterial(&m_Materials[i]);
		m_Mesh->DrawSubset(i);
	}
}
