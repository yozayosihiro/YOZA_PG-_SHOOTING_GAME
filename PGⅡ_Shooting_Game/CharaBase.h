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

protected:/*�L�����F�R���X�g���N�^*/

	BulletsBase** bullets; /*(�|�C���^�z��)*/

	/*�G(�|�C���^�z��)*/
	//Enemy** enemy; /*(�|�C���^�z��)*/
	//

	CharaBase(T_Location location, T_Location speed, float radius);

public:

	/*�L�����F�`��ȊO�̍X�V�����s����*/
	virtual void Update() = 0;

	/*�L�����F�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() = 0;

	/*�L�����F�����蔻�菈��*/
	virtual void Hit(int damage) = 0;

	BulletsBase** GetBullets();

	/*�L�����F�e�̍폜����*/
	void DeleteBullet(int BulletNum);

	/*�L�����F�G�l�~�[�̍폜����*/
	//void DeleteEnemy(int EnemyNum);
	//
};


