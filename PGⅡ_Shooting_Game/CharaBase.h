#pragma once
#include "SpherCollider.h"
#include"BulletsBase.h"

/*�L�����N�^�[�̃x�[�X*/
class CharaBase : public SpherCollider
{
private:

	T_Location speed; /*�X�s�[�h*/

	int* image; /**/

protected:/*�R���X�g���N�^*/

	BulletsBase** bullets; /*(�|�C���^�z��)*/

	CharaBase(T_Location location, T_Location speed, float radius);

public:

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Hit() = 0;

	BulletsBase** GetBullets();
};


