#include "Utility\Math.h"

CHAOS_ENGINE_BEGIN

	void Math::normalize(vector3* target, vector3* source){
		D3DXVec3Normalize(target, source);
	}

	void Math::cross(vector3* target, vector3* source1, vector3* source2){
		D3DXVec3Cross(target, source1, source2);
	}

	float Math::dot(vector3* source1, vector3* source2){
		return(D3DXVec3Dot(source1, source2));
	}

	//Vector of floating changes effect on the matrix
	void Math::rotation(matrix* target, vector3* source1, float angle){
		D3DXMatrixRotationAxis(target, source1, angle);
	}

	void Math::rotationX(matrix* target, float angle){
		D3DXMatrixRotationX(target, angle);
	}

	void Math::rotationY(matrix* target, float angle){
		D3DXMatrixRotationY(target, angle);
	}

	void Math::rotationZ(matrix* target, float angle){
		D3DXMatrixRotationZ(target, angle);
	}

	//Matrix effect on the vector
	void Math::transformCoord(vector3* target, vector3* source1, matrix* source2){
		D3DXVec3TransformCoord(target, source1, source2);
	}

	void Math::transformNormal(vector3* target, vector3* source1, matrix* source2){
		D3DXVec3TransformNormal(target, source1, source2);
	}

	//Matrix implementations
	float Math::determinant(matrix* source){
		return D3DXMatrixDeterminant(source);
	}

	void Math::identity(matrix* target){
		D3DXMatrixIdentity(target);
	}

	void Math::inverse(matrix* target, float determinant, matrix* source){
		D3DXMatrixInverse(target, &determinant, source);
	}

	bool Math::isIdentity(matrix* source){
		return D3DXMatrixIsIdentity(source);
	}

	void Math::multiply(matrix* target, matrix* source1, matrix* source2){
		D3DXMatrixMultiply(target, source1, source2);
	}

	void Math::scale(matrix* target, float sx, float sy, float sz){
		D3DXMatrixScaling(target, sx, sy, sz);
	}

	void Math::translation(matrix* target, float x, float y, float z){
		D3DXMatrixTranslation(target, x, y, z);
	}

	void Math::transpoze(matrix* target, matrix* source){
		D3DXMatrixTranspose(target, source);
	}

	double Math::sin(double angle){
		return std::sin(angle);
	}

	float Math::sin(float angle){
		return std::sin(angle);
	}
	double Math::cos(double angle){
		return std::cos(angle);
	}

	float Math::cos(float angle){
		return std::cos(angle);
	}

CHAOS_ENGINE_END

	//add Random math

