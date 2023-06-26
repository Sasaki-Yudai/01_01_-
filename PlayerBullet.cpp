#include "PlayerBullet.h"
#include <cassert>;


void PlayerBullet::Initialize(Model* model, const Vector3& position) {

	assert(model);

	model_ = model;

	//テクスチャ読込
	textureHandle2_ = TextureManager::Load("black.png");

	worldTransform_.Initialize();

	//引数で受け取った初期座標をセット
	worldTransform_.translation_ = position;

}



void PlayerBullet::Update()
{
	worldTransform_.UpdateMatrix(); 
	
};

void PlayerBullet::Draw(const ViewProjection& viewProjection){

model_->Draw(worldTransform_, viewProjection, textureHandle2_);



};
