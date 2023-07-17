#include "Enemy.h"
#include <cassert>;

void Enemy::Initialize(Model* model, uint32_t textureHandle3) {

	assert(model);

	model_ = model;

	textureHandle3_ = textureHandle3;

		worldTransform_.translation_ = {0.0f, 1.0f, 20.0f};


	worldTransform_.Initialize();

	// velocity_ = velocity;
};

void Enemy::Update() {

	// キャラクターの移動速度
	const float kEnemySpeed = 0.2f;

	switch (phase_) {
	case Enemy::Phase::Approach:

	default:

		// 移動
		worldTransform_.translation_.z -= kEnemySpeed;

		// 規定の位置に到達したら離脱
		if (worldTransform_.translation_.z < 0.0f) {
			phase_ = Enemy::Phase::Leave;
		}
		break;

	case Enemy::Phase::Leave:

		// 移動
		worldTransform_.translation_.x -= kEnemySpeed;
		worldTransform_.translation_.y += kEnemySpeed;
		worldTransform_.translation_.z += kEnemySpeed;

		break;
	}

	worldTransform_.UpdateMatrix();
};

void Enemy::Draw(ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection, textureHandle3_);
};
