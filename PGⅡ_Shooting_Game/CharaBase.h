#pragma once
#include "SpherCollider.h"

class CharaBase : public SpherCollider
{
private:

	/*bullets(�|�C���^�z��)*/

	T_Location speed; /*�X�s�[�h*/

	int* image; /**/

protected:/*�R���X�g���N�^*/

	CharaBase(T_Location location, T_Location speed, float radius);

public:

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Hit() = 0;

	/*GetBullets();*/
};


