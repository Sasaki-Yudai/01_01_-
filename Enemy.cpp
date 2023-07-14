#include "Enemy.h"
#include <cassert>;


void Enemy::Initialize(Model* model, uint32_t textureHandle3) {

	assert(model);

	model_ = model;

	textureHandle3_ = textureHandle3;


	
	worldTransform_.Initialize();


	// velocity_ = velocity;
};

void Enemy::Update() { 
	
		// 移動ベクトル
	Vector3 enemyMove = {0, 0, 0};


		// キャラクターの移動速度
	const float kEnemySpeed = 0.6f;

    worldTransform_.translation_.z -= kEnemySpeed;

	worldTransform_.UpdateMatrix(); 
};

void Enemy::Draw(ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection, textureHandle3_);
};
