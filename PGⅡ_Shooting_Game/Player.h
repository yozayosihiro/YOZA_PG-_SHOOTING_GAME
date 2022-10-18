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

	void Update() override;

	void Draw() override;

	void Hit() override;

	bool LifeCheck();

	int GetScore();
};

