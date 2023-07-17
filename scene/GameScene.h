#pragma once

#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Enemy.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "player.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {
	Player* player_ = nullptr;
	Enemy* enemy_ = nullptr;
	// スプライト
	Sprite* playerSprite_ = nullptr;
	Sprite* enemySprite_ = nullptr;

	////ビュープロジェクション
	// ViewProjection viewProjection_;

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t textureHandle3_ = 0u;

	// モデル
	Model* model_;

	// カメラ
	ViewProjection viewProjection_;

	// デバッグカメラ
	bool isDebugCameraActive_ = false;
	DebugCamera* debugCamera_ = nullptr;

	WorldTransform worldTransform_;


	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
