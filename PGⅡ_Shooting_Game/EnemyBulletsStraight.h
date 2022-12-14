#pragma once
#include "BulletsBase.h"

class EnemyBulletsStraight : public BulletsBase
{

public:/*率直な弾丸：コンストラクタ*/

	EnemyBulletsStraight(T_Location location);

public:

	/*率直な弾丸：描画以外の更新を実行する*/
	virtual void Update() override;

	/*率直な弾丸：描画に関することを実行する*/
	virtual void Draw() override;

	/*率直な弾丸：画面端処理*/
	virtual bool ScreenOut() override;

};

