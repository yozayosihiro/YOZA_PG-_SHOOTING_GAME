#pragma once
#include "BulletsBase.h"

class BulletsStraight : public BulletsBase
{

public:/*率直な弾丸：コンストラクタ*/

	BulletsStraight(T_Location location, T_Location speed /*= T_Location{0.-2}*/);

public:

	/*率直な弾丸：描画以外の更新を実行する*/
	virtual void Update() override;

	/*率直な弾丸：描画に関することを実行する*/
	virtual void Draw() override;

	/*率直な弾丸：画面端処理*/
	virtual bool ScreenOut() override;
};

