#pragma once
#include "CharaBase.h"

class Enemy : public CharaBase
{
private:

	int hp;

	int point;

public: /*コンストラクタ*/

	Enemy(T_Location location);

public:

	/*描画以外の更新を実行する*/
	virtual	void Update() override;

	/*描画に関することを実行する*/
	virtual	void Draw() override;

	/*当たり判定処理*/
	virtual	void Hit(int damage) override;

	bool HpCheck();

	int GetPoint();
};

