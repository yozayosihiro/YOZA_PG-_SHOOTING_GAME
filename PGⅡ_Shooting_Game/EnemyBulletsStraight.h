#pragma once
#include "BulletsBase.h"

class EnemyBulletsStraight : public BulletsBase
{

public:/*�����Ȓe�ہF�R���X�g���N�^*/

	EnemyBulletsStraight(T_Location location);

public:

	/*�����Ȓe�ہF�`��ȊO�̍X�V�����s����*/
	virtual void Update() override;

	/*�����Ȓe�ہF�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() override;

	/*�����Ȓe�ہF��ʒ[����*/
	virtual bool ScreenOut() override;

};

