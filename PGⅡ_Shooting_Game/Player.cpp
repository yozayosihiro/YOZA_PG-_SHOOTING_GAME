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

/*プレイヤー：描画以外の更新を実行する*/
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
		if (bullets[BulleCount]->ScreenOut())
		{
			//delete bullets[BulleCount]; /*弾を消す(デリート)*/
			//bullets[BulleCount] = nullptr; /*NULL POINTER(ヌル・ポインター)で上書き*/

			DeleteBullet(BulleCount);
			BulleCount--;

			/*配列を前に詰める・++ */
			//for (int i = BulleCount; i < 30 - 1; i++) /*28までループ*/
			//{
			//	if (bullets[i + 1] == nullptr)
			//	{
			//		break;
			//	}
			//	bullets[i] = bullets[i + 1]; /*後ろを前に*//*ループ*/
			//	bullets[i + 1] = nullptr; /*後ろをNULL POINTER(ヌル・ポインター)で上書き*/
			//}
			//
			//BulleCount--;

			/*配列を前に詰める・-- */
			//for (int i = BulleCount + 1; i < 30; i++) /*2から始まって29で終わる*/
			//{
			//	if (bullets[i] == nullptr)
			//	{
			//		break;
			//	}
			//	bullets[i - 1] = bullets[i]; /*後ろを前に*//*ループ*/
			//	bullets[i] = nullptr; /*後ろをNULL POINTER(ヌル・ポインター)で上書き*/
			//}

		    /*配列を前に詰める・未完成品*/
		    /*配列を前に詰める*/
		    //for (BulleCount = 0; BulleCount < 30; BulleCount++)
      //{
		//if (BulleCount != 29) { /*弾カウントが最後じゃなかったら*/
		//
		//	bullets[BulleCount] = bullets[BulleCount + 1]; /*次の弾*/
		//}
		//else 
		//{
		//	bullets[BulleCount] = nullptr; /*最後だったらnullpointerで上書き*/
		//
		//}
	  //}
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

/*プレイヤー：描画に関することを実行する*/
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

/*プレイヤー：当たり判定処理*/
void Player::Hit(int damage)
{

}

/*プレイヤー：HP処理*/
bool Player::LifeCheck()
{
	/*HP = 0 かどうか?*/
	bool ret = (life <= 0);

	return ret;
}

/*プレイヤー：スコアを返す*/
int Player::GetScore()
{
	return score;
}

/*プレイヤー：スコア加算*/
void Player::AddScore(int score)
{
	if (0 <= score) /*スコアが0より下にならないように*/
	{
		this->score += score;
	}
}
