#pragma once
#include"SpherCollider.h"

/*弾丸のベース*/
class BulletsBase : public SpherCollider
{
private:

	int damage; /*弾丸：ダメージ*/

protected:

	T_Location speed; /*弾丸：スピード*/

public: /*弾丸：コンストラクタ*/

	BulletsBase(T_Location location, T_Location speed, float radius, int damage);

public:

	/*弾丸：描画以外の更新を実行する*/
	virtual void Update() = 0;

	/*弾丸：描画に関することを実行する*/
	virtual void Draw() = 0;

	/*弾丸：画面外処理*/
	virtual bool ScreenOut() = 0;

	/*弾丸：ダメージ処理*/
	int GetDamege();
};

