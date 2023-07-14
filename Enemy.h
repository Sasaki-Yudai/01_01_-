#include <Input.h>
#include <Model.h>
#include <WorldTransform.h>

#pragma once
class Enemy {
public:
	///< summary>
	/// 初期化
	///  </summary>
	///  <param name="model">モデル</param>
	///  <param name="position">初期座標</param>

	void Initialize(Model* model_, uint32_t textureHandle3);

	///< summary>
	/// 更新
	///  </summary>

	void Update();

	///< summary>
	///< 描画>
	/// </summary>
	///< param name="ViewProjection"> ビュープロジェクション</param>

	void Draw(ViewProjection& viewProjection);

	

private:
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t textureHandle3_ = 0u;
	ViewProjection viewprojection_;
};