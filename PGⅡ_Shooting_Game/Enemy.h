#pragma once
#include "CharaBase.h"

class Enemy : public CharaBase
{
private:

	int hp;

	int point;

public: /*�R���X�g���N�^*/

	Enemy(T_Location location);

public:

	/*�`��ȊO�̍X�V�����s����*/
	virtual	void Update() override;

	/*�`��Ɋւ��邱�Ƃ����s����*/
	virtual	void Draw() override;

	/*�����蔻�菈��*/
	virtual	void Hit(int damage) override;

	bool HpCheck();

	int GetPoint();
};

