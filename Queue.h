#pragma once

#include "Multiply.h"

// 座標移動(ベクトルの加算)

//	vector3 result;

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate) {

	// スケーリング行列
	Matrix4x4 matScale{0};

	matScale.m[0][0] = scale.x;
	matScale.m[1][1] = scale.y;
	matScale.m[2][2] = scale.z;

	matScale.m[3][3] = 1;

	// X軸回転まわりの回転
	Matrix4x4 matRotX = {0};

	matRotX.m[0][0] = 1;
	matRotX.m[1][1] = cosf(rot.x);
	matRotX.m[2][1] = -sinf(rot.x);
	matRotX.m[1][2] = sinf(rot.x);
	matRotX.m[2][2] = cosf(rot.x);
	matRotX.m[3][3] = 1;

	// Y軸まわりの回転
	Matrix4x4 matRotY = {0};
	matRotY.m[0][0] = cosf(rot.y);
	matRotY.m[1][1] = 1;
	matRotY.m[0][2] = -sinf(rot.y);
	matRotY.m[2][0] = sinf(rot.y);
	matRotY.m[2][2] = cosf(rot.y);
	matRotY.m[3][3] = 1;

	// Z軸まわりの回転
	Matrix4x4 matRotZ = {0};
	matRotZ.m[0][0] = cosf(rot.z);
	matRotZ.m[1][0] = sinf(rot.z);
	matRotZ.m[0][1] = -sinf(rot.z);
	matRotZ.m[1][1] = cosf(rot.z);
	matRotZ.m[2][2] = 1;
	matRotZ.m[3][3] = 1;

	Matrix4x4 matRot = Multiply(Multiply(matRotZ, matRotX), matRotY);

	// 平行移動行列
	// TransferMatrix();

	Matrix4x4 matTrans = {0};

	matTrans.m[0][0] = 1;
	matTrans.m[1][1] = 1;
	matTrans.m[2][2] = 1;
	matTrans.m[3][3] = 1;
	matTrans.m[3][0] = translate.x;
	matTrans.m[3][1] = translate.y;
	matTrans.m[3][2] = translate.z;

	Matrix4x4 matWorld = Multiply(Multiply(matScale, matRot), matTrans);

	return matWorld;
}

Vector3 Add(const Vector3 v1, const Vector3 v2) { 
	
	Vector3 result = {};

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
};