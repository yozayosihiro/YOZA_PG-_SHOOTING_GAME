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

	/*描画以外の更新を実行する*/
	void Update() override;

	/*描画に関することを実行する*/
	void Draw() override;

	/*当たり判定処理*/
	void Hit(int damage) override;

	bool LifeCheck();

	int GetScore();
};

