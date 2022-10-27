#pragma once
#include "CharaBase.h"

class Enemy : public CharaBase
{
private:

	int hp;

	int point;

public: /*�R���X�g���N�^*/

	Enemy(T_Location location);

public:

	virtual	void Update() override;

	virtual	void Draw() override;

	virtual	void Hit() override;

	bool HpCheck();

	int GetPoint();
};

