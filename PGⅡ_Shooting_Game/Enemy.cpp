#include "Enemy.h"
#include"DxLib.h"
#include"BulletsStraight.h"
#include"EnemyBulletsStraight.h"
#include "KeyManager.h"
#include"BulletsRotation.h"

/*敵：移動・動きの情報*/
struct MoveInformation 
{
	T_Location TargetLocation; 

	int pattern;       /*方法・パターン*/

	int attackPattern; /*攻撃方法*/

	int next;          /*次の(配列)処理*/

	int waitTimeFlame; /*(待ちなど)時間*/

	/*int attackPattern; /*攻撃方法*/
};

MoveInformation MoveInfo[10] =
{
	//{640,150,0,1,0,0} ,  /*{X座標,Y座標,パターン,攻撃方法,次の(配列)処理,(待ちなど)時間}*/
	//{1200.4,150,0,2,0,0},
	//{0,0,1,3,180,0},
	//{80.2,150,0,4,0,2},
	//{0,0,1,5,180,1},
	//{1200.4,150,0,2,0,1},

	{640,150,0,0,1,0} ,  /*{X座標,Y座標,パターン,攻撃方法,次の(配列)処理,(待ちなど)時間}*/
	{1200.4,150,0,0,2,0},
	{0,0,1,0,3,180},
	{80.2,150,0,2,4,0},
	{0,0,1,1,5,180},
	{1200.4,150,0,1,2,0},
};

//T_Location loopLocations[4] = /*繰り返し移動用の座標*/
//{
//	{640,150},	  /*移動1*/
//	{1200.4,150}, /*移動2*/
//	{80.2,150}    /*移動3*/
//}; 

/*別方法*/
T_Location loopLocations[3] = /*繰り返し移動用の座標*/
{
	{640,150},	  /*移動1*/
	{1200.4,150}, /*移動2*/
	{80.2,150},   /*移動3*/
};

int Next[3] = /*移動番号*/
{
	1, /*移動1*/
	2, /*移動2*/
	3, /*移動3*/
};

int current = 0; /*処理用番号の変数*/
                                                          /*speed   X,Y */                  /*   初   期   化   */
Enemy::Enemy(T_Location location) : CharaBase(location, T_Location{ 2,2 }, 20.f), hp(10), point(10), shotNum(0),locationNum(0)
{
	/*BulletsBase** bullets*//*2重配列*/
	bullets = new BulletsBase * [30]; /*同時に出せる弾の数 30*/

	/*2重配列の初期化*/
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

/*敵：移動処理*/
void Enemy::Move()
{
	T_Location NextLocation = GetLocation(); /*敵の座標・今の座標を次の座標に入れる*/

	if ((NextLocation.y == loopLocations[current].y) && (NextLocation.x == loopLocations[current].x)) /*同じ座標にいたら次へ*/
	{
		current = Next[current];
	}
	else /*目的地にいなかったときは*/
	{
		/*縦の移動処理*/
		if (NextLocation.y != loopLocations[current].y) /*Y座標*/
		{
			if (NextLocation.y < loopLocations[current].y)
			{
				NextLocation.y += speed.y; /*下移動*/

				if ((GetLocation().y <= loopLocations[current].y) && (loopLocations[current].y <= NextLocation.y)) /*((今のY座標 <= 目的地) && 目的地 <= 次のY座標))*/
				{
					NextLocation.y = loopLocations[current].y; /*目的地を飛び超えたとき*/
				}
			}
			else
			{
				NextLocation.y -= speed.y; /*上移動*/

				if ((NextLocation.y <= loopLocations[current].y) && (loopLocations[current].y <= GetLocation().y)) /*((次のY座標 <= 目的地) && (目的地 <= 今のY座標))*/
				{
					NextLocation.y = loopLocations[current].y;
				}
			}
		}
	}
	/*横の移動処理*/
	if (NextLocation.x != loopLocations[current].x) /*X座標*/
	{
		if (NextLocation.x < loopLocations[current].x)
		{
			NextLocation.x += speed.x; /*右移動*/

			if ((GetLocation().x <= loopLocations[current].x) && (loopLocations[current].x <= NextLocation.x)) /*((今のX座標 <= 目的地) && 目的地 <= 次のX座標))*/
			{
				NextLocation.x = loopLocations[current].x; /*目的地を飛び超えたとき*/
			}
		}
		else
		{
			NextLocation.x -= speed.x; /*左移動*/

			if ((NextLocation.x <= loopLocations[current].x) && (loopLocations[current].x <= GetLocation().x)) /*((次のX座標 <= 目的地) && (目的地 <= 今のX座標))*/
			{
				NextLocation.x = loopLocations[current].x; /*目的地を飛び超えたとき*/
			}
		}
	}
	SetLocation(NextLocation); /*敵の移動処理のセット*/
}

/*敵：移動処理*/
//void Enemy::Move()
//{
//	 /*敵の移動 LocationをLocationに移動させる処理*/
//	T_Location NewLocation = GetLocation();
//
//	/*敵の移動処理*/
//	if (NewLocation.x != loopLocations[locationNum].x) /*敵のX座標と目標のX座標が違かったら*/
//	{
//		if (NewLocation.x < loopLocations[locationNum].x)  /*敵のX座標より目標のX座標が大きかったら X座標の右移動*/
//		{
//			speed.x = 1;  /*X座標の右移動 スピードXで移動*/
//		}
//		if (NewLocation.x > loopLocations[locationNum].x) /*敵のX座標より目標のX座標が小さかったら X座標の左移動*/
//		{
//			speed.x = -1; /*X座標の左移動 スピードXで移動*/
//		}
//
//		NewLocation.x += speed.x; /*エネミーはスピードXの値をみて移動*/
//	}
//	/*敵のX座標と目標のX座標が一致したとき*/
//	else if (NewLocation.y != loopLocations[locationNum].y) /*敵のY座標と目標のY座標が違かったら*/
//	{
//		speed.x = 0; /*X座標の移動をしないように*/
//
//		if (NewLocation.y < loopLocations[locationNum].y) /*敵のY座標より目標のY座標が大きかったら Y座標の上移動*/
//		{
//			speed.y = 1;  /*Y座標の上移動 スピードYで移動*/
//		}
//		if (NewLocation.y > loopLocations[locationNum].y) /*敵のY座標より目標のY座標が小さかったら Y座標の下移動*/
//		{
//			speed.y = -1; /*Y座標の下移動 スピードYで移動*/
//		}
//
//		NewLocation.y += speed.y; /*エネミーはスピードYの値をみて移動*/
//	}
//	/*敵のXY座標と目標のXY座標が一致したとき*/
//	else
//	{
//		speed.y = 0;   /*Y座標の移動をしないように*/
//
//		locationNum++; /*次の移動用の座標に*/
//	}
//
//	/*移動用の座標をループする*/
//	if (locationNum > 3)
//	{
//		locationNum = 2;
//	}
//
//	//NewLocation.x += speed.x; /*エネミーはスピードXの値をみて移動*/
//	//NewLocation.y += speed.y; /*エネミーはスピードYの値をみて移動*/
//
//	SetLocation(NewLocation); /*敵の移動処理のセット*/
//******************************************************************
//}

/*敵：描画以外の更新を実行する*/
void Enemy::Update()
{
	int BulleCount;

	/*敵：移動処理*/
	Move();

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
			/*弾幕作成*/                                /*位置*/  /*speed*/ /*発射角度*/
			bullets[BulleCount] = new BulletsRotation(GetLocation(), 2.f, (20 * shotNum));

			shotNum++; /*足していく*/

			                                                   /*BulletsStraightの引数*/
			/*bullets[BulleCount] = new BulletsStraight(GetLocation(),T_Location {0,-4}); /*BulletsStraightを作成*/
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