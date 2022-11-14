#pragma once
#include "CharaBase.h"

class Player :  public CharaBase
{
private:

	int score; /*�X�R�A*/

	int life; /*HP*/

public: /*�R���X�g���N�^�E������*/

	Player(T_Location location);

public:

	/*�v���C���[�F�`��ȊO�̍X�V�����s����*/
	void Update() override;

	/*�v���C���[�F�`��Ɋւ��邱�Ƃ����s����*/
	void Draw() override;

	/*�v���C���[�F�U�������蔻�菈��*/
	void Hit(int damage) override;

	/*�v���C���[�F�A�C�e���ւ̓��e����*/
	void Hit(class ItemBase* item);

	/*�v���C���[�FHP����*/
	bool LifeCheck();

	/*�v���C���[�F�X�R�A��Ԃ�*/
	int GetScore();

	/*�v���C���[�F�X�R�A���Z*/
	void AddScore(int score);
};

