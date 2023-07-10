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
	//<summary>
	// 初期化
	//</summary>
	void Initialize(Model* model_, uint32_t textureHndle);

	//<summary>
	// 更新
	//</summary>
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
};