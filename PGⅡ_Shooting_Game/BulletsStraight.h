#pragma once
#include "BulletsBase.h"
class BulletsStraight : public BulletsBase
{

public:/*�R���X�g���N�^*/

	BulletsStraight(T_Location location);

public:

	virtual void Update() override;

	virtual void Draw() override;

	/*��ʒ[����*/
	virtual bool ScreenOut() override;

};

