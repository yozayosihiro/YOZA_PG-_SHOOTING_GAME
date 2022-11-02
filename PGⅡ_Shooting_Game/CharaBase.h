#pragma once
#include "SpherCollider.h"
#include"BulletsBase.h"

/*キャラクターのベース*/
class CharaBase : public SpherCollider
{
//private:
//
//	T_Location speed; /*スピード*/
//
//	int* image; /**/

protected:

	T_Location speed; /*スピード*/

	int* image; /**/

protected:/*コンストラクタ*/

	BulletsBase** bullets; /*(ポインタ配列)*/

	CharaBase(T_Location location, T_Location speed, float radius);

public:

	/*描画以外の更新を実行する*/
	virtual void Update() = 0;

	/*描画に関することを実行する*/
	virtual void Draw() = 0;

	/*当たり判定処理*/
	virtual void Hit(int damage) = 0;

	BulletsBase** GetBullets();

	/*弾の削除処理*/
	void DeleteBullet(int BulletNum);
};


