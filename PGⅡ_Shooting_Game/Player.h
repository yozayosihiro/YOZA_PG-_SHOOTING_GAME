#pragma once
#include "CharaBase.h"

class Player :  public CharaBase
{
private:

	int score; /*スコア*/

	int life; /*HP*/

public: /*コンストラクタ・初期化*/

	Player(T_Location location);

public:

	/*プレイヤー：描画以外の更新を実行する*/
	void Update() override;

	/*プレイヤー：描画に関することを実行する*/
	void Draw() override;

	/*プレイヤー：攻撃当たり判定処理*/
	void Hit(int damage) override;

	/*プレイヤー：アイテムへの内容処理*/
	void Hit(class ItemBase* item);

	/*プレイヤー：HP処理*/
	bool LifeCheck();

	/*プレイヤー：スコアを返す*/
	int GetScore();

	/*プレイヤー：スコア加算*/
	void AddScore(int score);
};

