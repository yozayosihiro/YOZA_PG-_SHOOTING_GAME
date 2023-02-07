#pragma once
#include "CharaBase.h"

/*�G�F�ړ��E�����̏��*/
struct MoveInformation 
{
	int pattern;               /*���@�E�p�^�[��*/

	T_Location TargetLocation; /*�ړI�n*/

	int next;                  /*����(�z��)����*/

	int waitTimeFlame;         /*(�҂��Ȃ�)����*/

	int attackPattern;         /*�U�����@*/
};

class Enemy : public CharaBase
{
private:

	int hp; /*�G�FHP*/

	int point; /*�G�F�|�C���^�擾*/

	int shotNum; /*�G�F�������e���o�����l����������*/

	int locationNum; /*�J��Ԃ��ړ��p�̍��W�̔ԍ�������*/

	int current = 0; /*�����p�ԍ��̕ϐ�*/
	int waitCount = 0; /*��؎���*/

	/*�G�F�ړ�, �ړI�n, NEXT, �҂�����, �U�����@�̔z��*/
	MoveInformation MoveInfo[10] = {};

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

	/*�G�F�ړ������E�U���̕��@�A�p�^�[���̃t�@�C���ǂݍ���*/
	void InputCSV();
};

