#pragma once
#include "BulletsBase.h"
class BulletsRotation : public BulletsBase
{

public:/*��]���e�ہF�R���X�g���N�^*/

	BulletsRotation(T_Location location, T_Location speed /*= T_Location{0.-2}*/);

public:

	/*��]���e�ہF�`��ȊO�̍X�V�����s����*/
	virtual void Update() override;

	/*��]���e�ہF�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() override;

	/*��]���e�ہF��ʒ[����*/
	virtual bool ScreenOut() override;
};

