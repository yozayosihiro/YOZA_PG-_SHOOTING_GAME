#pragma once
#include "BulletsBase.h"

class BulletsStraight : public BulletsBase
{

public:/*�����Ȓe�ہF�R���X�g���N�^*/

	BulletsStraight(T_Location location, T_Location speed /*= T_Location{0.-2}*/);

public:

	/*�����Ȓe�ہF�`��ȊO�̍X�V�����s����*/
	virtual void Update() override;

	/*�����Ȓe�ہF�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() override;

	/*�����Ȓe�ہF��ʒ[����*/
	virtual bool ScreenOut() override;
};

