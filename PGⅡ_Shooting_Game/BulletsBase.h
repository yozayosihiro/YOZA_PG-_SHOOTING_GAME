#pragma once
#include"SpherCollider.h"

/*弾丸のベース*/
class BulletsBase : public SpherCollider
{
private:

	int damage; //ダメージ

protected:

	T_Location speed; //スピード

public: /*コンストラクタ*/

	BulletsBase(T_Location location, T_Location speed, float radius, int damage);

public:

	/*描画以外の更新を実行する*/
	virtual void Update() = 0;

	/*描画に関することを実行する*/
	virtual void Draw() = 0;

	/*画面外処理*/
	virtual bool ScreenOut() = 0;

	int GetDamege();
};

