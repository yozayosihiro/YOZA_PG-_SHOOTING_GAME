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

	/*�`��ȊO�̍X�V�����s����*/
	void Update() override;

	/*�`��Ɋւ��邱�Ƃ����s����*/
	void Draw() override;

	/*�����蔻�菈��*/
	void Hit(int damage) override;

	bool LifeCheck();

	int GetScore();
};

