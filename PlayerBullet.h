#include<Input.h>
#include <Model.h>
#include <WorldTransform.h>





///<summary>
///初期化
/// </summary>
///<param name="model">モデル</param>
/// <param name="position">初期座標</param>
/// <param name="velocity">速度</param>


///<summary>
///自キャラの弾
/// </summary>

class PlayerBullet {
private:
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t textureHandle2_ = 0u;

	// 速度
	Vector3 velocity_;

	//寿命<frm>
	static const int32_t kLifeTime = 60 * 5;

	//デスタイマー
	int32_t deathTimer_ = kLifeTime;

	//デスフラグ
	bool isDead_ = false;


public:
	
	bool IsDead() const { return isDead_; }


	///<summary>
	///初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="position">初期座標</param>
	
	void Initialize(Model* model, const Vector3& posiion, const Vector3& velocity);


	///<summary>
	///更新
	/// </summary>

	void Update();


	///<summary>
	///<描画>
	/// </summary>
	///<param name="ViewProjection"> ビュープロジェクション</param>

	void Draw(const ViewProjection& viewProjection);

};