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

	virtual void Update() = 0;

	virtual void Draw() = 0;

	int GetDamege();
};

