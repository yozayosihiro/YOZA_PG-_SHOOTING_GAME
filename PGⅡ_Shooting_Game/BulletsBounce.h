#pragma once
#include "BulletsBase.h"

class BulletsBounce : public BulletsBase
{
private:

	int bounceX;
	int bounceY;

public:/*���˕Ԃ莮�e�ہF�R���X�g���N�^*/
											
	BulletsBounce(T_Location location, float speed, float bounceAngle);

public:

	/*���˕Ԃ莮�e�ہF�`��ȊO�̍X�V�����s����*/
	virtual void Update() override;

	/*���˕Ԃ莮�e�ہF�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() override;

	/*���˕Ԃ莮�e�ہF��ʒ��˕Ԃ�*/
	 void ScreenBounce();
};

