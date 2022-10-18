#pragma once
#include "CharaBase.h"

class Player :  public CharaBase
{
private:

	int score; /*�X�R�A*/

	int life; /*HP*/

public: /*�R���X�g���N�^�E������*/

	Player(T_Location location);

public:

	void Update() override;

	void Draw() override;

	void Hit() override;

	bool LifeCheck();

	int GetScore();
};

