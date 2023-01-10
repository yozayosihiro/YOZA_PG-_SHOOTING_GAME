#pragma once
#include "CharaBase.h"

class Enemy : public CharaBase
{
private:

	int hp; /*敵：HP*/

	int point; /*敵：ポインタ取得*/

	int shotNum; /*敵：自分が弾を出した値を持たせる*/

	int locationNum; /*繰り返し移動用の座標の番号を示す*/

public: /*コンストラクタ*/

	Enemy(T_Location location);

	/*敵(ポインタ配列)*/
	//Enemy** enemy; /*(ポインタ配列)*/
	//
	

public:

	/*敵：描画以外の更新を実行する*/
	virtual	void Update() override;

	/*敵：描画に関することを実行する*/
	virtual	void Draw() override;

	/*敵：当たり判定処理*/
	virtual	void Hit(int damage) override;

	/*敵：HP判定処理*/
	bool HpCheck();

	/*敵：ポインタ取得処理*/
	int GetPoint();

	/*敵：移動処理*/
	void Move();

	/*エネミーの削除処理*/
	//void DeleteEnemy(int EnemyNum);
	//
};

