#include "DxLib.h"
#include "Player.h"
#include"BulletsStraight.h"
#include"KeyManager.h"

Player::Player(T_Location location) : CharaBase(location, T_Location{ 2,2 }, 10.f), score(0), life(10)
{
	/*BulletsBase** bullets*//*2重配列*/
	bullets = new BulletsBase * [30]; /*同時に出せる弾の数 30*/

	/*2重配列の初期化*/
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

/*描画以外の更新を実行する*/
void Player::Update()
{
	/*LocationをLocationに移動させる処理*/
	T_Location NewLocation = GetLocation();

	NewLocation.x += 1;
	SetLocation(NewLocation);

	int BulleCount;

	for (BulleCount = 0; BulleCount < 30; BulleCount++) /*発射カウント*/
	{
		if (bullets[BulleCount] == nullptr)
		{
			break;
		}

		bullets[BulleCount]->Update();
	}

	if (KeyManager::OnMouseClicked(MOUSE_INPUT_LEFT)) /*マウス左クリック*/
	{
		if (BulleCount < 30 && bullets[BulleCount] == nullptr) /*発射カウント*/
		{
			bullets[BulleCount] = new BulletsStraight(GetLocation()); /*BulletsStraightを作成*/
		}
	}
}

/*描画に関することを実行する*/
void Player::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));

	/*弾丸の描画*/
	for (int BulleCount = 0; BulleCount < 30; BulleCount++)
	{
		if (bullets[BulleCount] == nullptr)
		{
			break;
		}

		bullets[BulleCount]->Draw();
	}
}

void Player::Hit()
{

}

bool Player::LifeCheck()
{
	/*HP = 0 かどうか?*/
	bool ret = (life <= 0);

	return ret;
}

int Player::GetScore()
{
	return score;
}
