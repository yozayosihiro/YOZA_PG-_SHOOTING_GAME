#pragma once
#include "CharaBase.h"

class Enemy : public CharaBase
{
private:

	int hp; /*�G�FHP*/

	int point; /*�G�F�|�C���^�擾*/

	int shotNum; /*�G�F�������e���o�����l����������*/

	int locationNum; /*�J��Ԃ��ړ��p�̍��W�̔ԍ�������*/

public: /*�R���X�g���N�^*/

	Enemy(T_Location location);

	/*�G(�|�C���^�z��)*/
	//Enemy** enemy; /*(�|�C���^�z��)*/
	//
	

public:

	/*�G�F�`��ȊO�̍X�V�����s����*/
	virtual	void Update() override;

	/*�G�F�`��Ɋւ��邱�Ƃ����s����*/
	virtual	void Draw() override;

	/*�G�F�����蔻�菈��*/
	virtual	void Hit(int damage) override;

	/*�G�FHP���菈��*/
	bool HpCheck();

	/*�G�F�|�C���^�擾����*/
	int GetPoint();

	/*�G�F�ړ�����*/
	void Move();

	/*�G�l�~�[�̍폜����*/
	//void DeleteEnemy(int EnemyNum);
	//
};

