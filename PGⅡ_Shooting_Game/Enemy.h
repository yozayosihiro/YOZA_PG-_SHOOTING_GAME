#pragma once
#include "CharaBase.h"

class Enemy : public CharaBase
{
private:

	int hp;

	int point;

public: /*コンストラクタ*/

	Enemy(T_Location location);

	/*敵(ポインタ配列)*/
	//Enemy** enemy; /*(ポインタ配列)*/
	//
	

public:

	/*描画以外の更新を実行する*/
	virtual	void Update() override;

	/*描画に関することを実行する*/
	virtual	void Draw() override;

	/*当たり判定処理*/
	virtual	void Hit(int damage) override;

	bool HpCheck();

	int GetPoint();

	/*エネミーの削除処理*/
	//void DeleteEnemy(int EnemyNum);
	//
};

