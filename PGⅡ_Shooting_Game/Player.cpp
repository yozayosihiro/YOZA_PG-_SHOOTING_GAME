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

	if (KeyManager::OnKeyPressed(KEY_INPUT_W)) /*上移動*/
	{
		NewLocation.y -= speed.y;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_A)) /*左移動*/
	{
		NewLocation.x -= speed.x;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_S)) /*下移動*/
	{
		NewLocation.y += speed.y;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_D)) /*右移動*/
	{
		NewLocation.x += speed.x;
	}

	SetLocation(NewLocation);

	int BulleCount;

	for (BulleCount = 0; BulleCount < 30; BulleCount++) /*発射カウント*/
	{
		if (bullets[BulleCount] == nullptr)
		{
			break;
		}

		bullets[BulleCount]->Update(); /*弾のアップデート*/

		/*画面外に行ったら弾を消す*/
		if(bullets[BulleCount] ->ScreenOut())
		{
			delete bullets[BulleCount]; /*弾を消す(デリート)*/
			bullets[BulleCount] = nullptr; /*NULL POINTER(ヌル・ポインター)で上書き*/

			/*配列を前に詰める*/
			for (BulleCount = 0; BulleCount < 30; BulleCount++)
			{
				//if (BulleCount != 29) { /*弾カウントが最後じゃなかったら*/
				//
				//	bullets[BulleCount] = bullets[BulleCount + 1]; /*次の弾*/
				//}
				//else 
				//{
				//	bullets[BulleCount] = nullptr; /*最後だったらnullpointerで上書き*/
				//
				//}

				if (BulleCount != 29) { /*弾カウントが最後じゃなかったら*/

					bullets[BulleCount] = bullets[BulleCount + 1]; /*次の弾*/
				}
				else 
				{
					bullets[BulleCount] = nullptr; /*最後だったらNULL POINTER(ヌル・ポインター)で上書き*/
				}
			}
		}
	}

	if (KeyManager::OnMousePressed(MOUSE_INPUT_LEFT)) /*マウス左クリック*/
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
