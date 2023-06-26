#include "PlayerBullet.h"
#include <Input.h>
#include <Model.h>
#include <WorldTransform.h>
#include <list>

#pragma once
class Player {

	// PlayerBullet* bullet_ = nullptr;

	std::list<PlayerBullet*> bullets_;

	///< summary>
	/// 攻撃
	///</summary>
	void Attack(Vector3& position);

public:
	//<summry>
	// 初期化
	//</summry>
	void Initialize(Model* model_, uint32_t textureHndle);

	//<summry>
	// 更新
	//</summry>
	void Update();

	//<summry>
	// 描画
	//</summry>
	void Draw(ViewProjection& viewProjection);

	//<summry>
	// デストラクタ
	//<summry>
	~Player();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;

	Input* input_ = nullptr;

	struct vector3 {
		float X;
		float Y;
		float Z;
	};
};