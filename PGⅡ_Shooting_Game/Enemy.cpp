#include "Enemy.h"
#include"DxLib.h"
#include"BulletsStraight.h"
#include"EnemyBulletsStraight.h"
#include "KeyManager.h"

Enemy::Enemy(T_Location location) : CharaBase(location, T_Location{ 0,0.5 }, 20.f), hp(10), point(10)
{
	/*BulletsBase** bullets*//*2重配列*/
	bullets = new BulletsBase * [30]; /*同時に出せる弾の数 30*/

	/*2重配列の初期化*/
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

/*敵：描画以外の更新を実行する*/
void Enemy::Update()
{
	/*LocationをLocationに移動させる処理*/
	T_Location NewLocation = GetLocation();

	NewLocation.y += speed.y; /*エネミーはスピードの値をみて移動*/
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
			/*弾丸の消去*/
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

	/*敵：弾丸の発射*/
	if (1) /*自動で*/
	{
		if (BulleCount < 30 && bullets[BulleCount] == nullptr) /*発射カウント*/
		{
			                                                   /*BulletsStraightの引数*/
			bullets[BulleCount] = new BulletsStraight(GetLocation(),T_Location {0,-4}); /*BulletsStraightを作成*/
			//bullets[BulleCount] = new EnemyBulletsStraight(GetLocation()); /*強引BulletsStraightを作成*/
			//
		}
	}
}

/*敵：描画に関することを実行する*/
void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

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

/*敵：当たり判定処理*/
void Enemy::Hit(int damage)
{
	if (0 < damage) /*クラスで引き渡されてるかどうか*/
	{
		hp -= damage; /*エネミーのHPを減らす*/

		if (hp < 0) /*HPが0の時*/
		{
			hp = 0;
		}
	}
}

/*敵：HP判定処理*/
bool Enemy::HpCheck()
{
	/*HP = 0 かどうか?*/
	bool ret = (hp <= 0); 

		return ret;
}

/*敵：ポインタ取得処理*/
int Enemy::GetPoint()
{
	return point; /*メンバ変数のポイントを返す*/
}

/*エネミーの削除処理*/
//void DeleteEnemy(int EnemyNum)
//{
//	
//}