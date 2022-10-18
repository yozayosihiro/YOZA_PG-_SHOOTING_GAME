#pragma once
#include "SpherCollider.h"

class CharaBase : public SpherCollider
{
private:

	/*bullets(ポインタ配列)*/

	T_Location speed; /*スピード*/

	int* image; /**/

protected:/*コンストラクタ*/

	CharaBase(T_Location location, T_Location speed, float radius);

public:

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Hit() = 0;

	/*GetBullets();*/
};


