#pragma once
#include "BulletsBase.h"
class BulletsRotation : public BulletsBase
{

public:/*回転式弾丸：コンストラクタ*/
	                                                /*敵が弾を発射する*/
	BulletsRotation(T_Location location, float speed, int degAngle);

public:

	/*回転式弾丸：描画以外の更新を実行する*/
	virtual void Update() override;

	/*回転式弾丸：描画に関することを実行する*/
	virtual void Draw() override;

	/*回転式弾丸：画面端処理*/
	virtual bool ScreenOut() override;
};

