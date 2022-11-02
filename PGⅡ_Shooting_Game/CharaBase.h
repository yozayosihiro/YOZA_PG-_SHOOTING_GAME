#pragma once
#include "SpherCollider.h"
#include"BulletsBase.h"

/*�L�����N�^�[�̃x�[�X*/
class CharaBase : public SpherCollider
{
//private:
//
//	T_Location speed; /*�X�s�[�h*/
//
//	int* image; /**/

protected:

	T_Location speed; /*�X�s�[�h*/

	int* image; /**/

protected:/*�R���X�g���N�^*/

	BulletsBase** bullets; /*(�|�C���^�z��)*/

	CharaBase(T_Location location, T_Location speed, float radius);

public:

	/*�`��ȊO�̍X�V�����s����*/
	virtual void Update() = 0;

	/*�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() = 0;

	/*�����蔻�菈��*/
	virtual void Hit(int damage) = 0;

	BulletsBase** GetBullets();

	/*�e�̍폜����*/
	void DeleteBullet(int BulletNum);
};


