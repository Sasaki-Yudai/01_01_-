#include<Input.h>
#include <Model.h>
#include <WorldTransform.h>



///<summary>
///自キャラの弾
/// </summary>

class PlayerBullet {
private:
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t textureHandle2_ = 0u;


public:
	///<summary>
	///初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="position">初期座標</param>
	
	void Initialize(Model* model, const Vector3& posiion);


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