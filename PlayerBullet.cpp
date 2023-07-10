#include "PlayerBullet.h"
#include <cassert>;
//#include "Queue.h"

void PlayerBullet::Initialize(Model* model, const Vector3& position, const Vector3& velocity) {

	assert(model);

	model_ = model;

	//テクスチャ読込
	textureHandle2_ = TextureManager::Load("black.png");

	worldTransform_.Initialize();

	//引数で受け取った初期座標をセット
	worldTransform_.translation_ = position;

	velocity_ = velocity;


}



void PlayerBullet::Update()
{
	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.y += velocity_.y;
	worldTransform_.translation_.z += velocity_.z;

//	worldTransform_.translation_ = Add(worldTransform_.translation_, velocity_);


	worldTransform_.UpdateMatrix(); 


	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}




};

void PlayerBullet::Draw(const ViewProjection& viewProjection){

model_->Draw(worldTransform_, viewProjection, textureHandle2_);



};
