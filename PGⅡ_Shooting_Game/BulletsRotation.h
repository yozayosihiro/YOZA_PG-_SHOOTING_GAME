#pragma once
#include "BulletsBase.h"
class BulletsRotation : public BulletsBase
{

public:/*回転式弾丸：コンストラクタ*/

	BulletsRotation(T_Location location, T_Location speed /*= T_Location{0.-2}*/);

public:

	/*回転式弾丸：描画以外の更新を実行する*/
	virtual void Update() override;

	/*回転式弾丸：描画に関することを実行する*/
	virtual void Draw() override;

	/*回転式弾丸：画面端処理*/
	virtual bool ScreenOut() override;
};

