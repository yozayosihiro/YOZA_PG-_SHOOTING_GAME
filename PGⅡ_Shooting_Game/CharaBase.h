#pragma once
#include "SpherCollider.h"
#include"BulletsBase.h"

/*キャラクターのベース*/
class CharaBase : public SpherCollider
{
private:

	T_Location speed; /*スピード*/

	int* image; /**/

protected:/*コンストラクタ*/

	BulletsBase** bullets; /*(ポインタ配列)*/

	CharaBase(T_Location location, T_Location speed, float radius);

public:

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Hit() = 0;

	BulletsBase** GetBullets();
};


