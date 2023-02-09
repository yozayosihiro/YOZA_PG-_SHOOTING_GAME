#pragma once
#include "BulletsBase.h"

class BulletsBounce : public BulletsBase
{
private:

	int bounceX;
	int bounceY;

public:/*跳ね返り式弾丸：コンストラクタ*/
											
	BulletsBounce(T_Location location, float speed, float bounceAngle);

public:

	/*跳ね返り式弾丸：描画以外の更新を実行する*/
	virtual void Update() override;

	/*跳ね返り式弾丸：描画に関することを実行する*/
	virtual void Draw() override;

	/*跳ね返り式弾丸：画面跳ね返り*/
	 void ScreenBounce();
};

