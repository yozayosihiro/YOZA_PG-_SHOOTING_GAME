#pragma once
#include "BulletsBase.h"
class BulletsStraight : public BulletsBase
{

public:/*コンストラクタ*/

	BulletsStraight(T_Location location);

public:

	virtual void Update() override;

	virtual void Draw() override;

	/*画面端処理*/
	virtual bool ScreenOut() override;

};

