#pragma once
#include "BulletsBase.h"
class BulletsRotation : public BulletsBase
{

public:/*��]���e�ہF�R���X�g���N�^*/
	                                                /*�G���e�𔭎˂���*/
	BulletsRotation(T_Location location, float speed, int degAngle);

public:

	/*��]���e�ہF�`��ȊO�̍X�V�����s����*/
	virtual void Update() override;

	/*��]���e�ہF�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() override;

	/*��]���e�ہF��ʒ[����*/
	virtual bool ScreenOut() override;
};

