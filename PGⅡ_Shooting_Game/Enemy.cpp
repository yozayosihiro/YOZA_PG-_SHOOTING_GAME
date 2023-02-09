#include "Enemy.h"
#include"DxLib.h"
#include"BulletsStraight.h"
#include"EnemyBulletsStraight.h"
#include "KeyManager.h"
#include"BulletsRotation.h"

///*敵：移動・動きの情報*/
//struct MoveInformation 
//{
//	int pattern;               /*方法・パターン*/
//
//	T_Location TargetLocation; /*目的地*/
//
//	int next;                  /*次の(配列)処理*/
//
//	int waitTimeFlame;         /*(待ちなど)時間*/
//
//	int attackPattern;         /*攻撃方法*/
//};

/*敵：移動, 目的地, NEXT, 待ち時間, 攻撃方法の配列*/
//MoveInformation MoveInfo[10] =
//{
////{方法,    目的地,   NEXT,  待ち時間,  攻撃方法};
//	{0,     640, 150,    1,         0,         0}, 
//	{0,  1200.4, 150,    2,         0,         2}, 
//	{1,       0,   0,    3,       300,         1}, 
//	{0,    80.2, 150,    4,         0,         2}, 
//	{1,       0,   0,    1,       300,         1}
//
//	//{640,150,0,0,1,0} ,  //{X座標,Y座標,パターン,攻撃方法,次の(配列)処理,(待ちなど)時間}
//	//{1200.4,150,0,0,2,0},
//	//{0,0,1,0,3,180},
//	//{80.2,150,0,2,4,0},
//	//{0,0,1,1,5,180},
//	//{1200.4,150,0,1,2,0},
//};

//struct ENEMY_MOVE
//{
//	int pattern;       /*方法・パターン*/
//
//	int waitTimeFlame; /*(待ちなど)時間*/
//
//	T_Location TargetLocation;
//
//	int next;          /*次の(配列)処理*/
//
//	//int attackPattern; /*攻撃方法*/
//};
//
//ENEMY_MOVE MovePattern[6] = 
//{
//	{0, 0, 640.f, }
//	{}
//	{}
//	{}
//	{}
//	{}
//}

//T_Location loopLocations[4] = /*繰り返し移動用の座標*/
//{
//	{640,150},	  /*移動1*/
//	{1200.4,150}, /*移動2*/
//	{80.2,150}    /*移動3*/
//}; 

/*別方法*/
//T_Location loopLocations[3] = /*繰り返し移動用の座標*/
//{
//	//{640,150},	  /*移動1*/
//	//{1200.4,150}, /*移動2*/
//	//{80.2,150},   /*移動3*/
//};

/*移動番号*/
//int Next[3] = 
//{
//	//1, /*移動1*/
//	//2, /*移動2*/
//	//3, /*移動3*/
//};

//int current = 0; /*処理用番号の変数*/
//int waitCount = 0; /*停滞時間*/

/*敵：移動処理・攻撃の方法、パターンのファイル読み込み*/
void Enemy::InputCSV()
{
	FILE* fp; /*FILE型構造体*/

	errno_t error; /*fopen_sのエラー確認*/

	error = fopen_s(&fp, "CSV/csv.csv", "r");

	/*(ブレイクポイントを付けて)ファイルの開閉テスト*/
	if (error != 0)
	{
		return; //エラー発生
	}
	else //ファイルを開いた
	{
		char line[100]; //行

		/*fgets(line, 文字数, fp)*/
		//fgets(line, 100, fp); 
		//

		for (int i = 0; fgets(line, 100, fp) != NULL; i++) {
			//while (fgets(line[100], 100, fp) != NULL) //指定の文字数を取ってくる
			//{
				sscanf_s(
						  line, //行

					"%d, %f, %f, %d, %d, %d",       //(int, float, float, int, int, int)

					& MoveInfo[i].pattern,          /*方法・パターン*/

					& MoveInfo[i].TargetLocation.x, /*目的地.X座標*/

					& MoveInfo[i].TargetLocation.y, /*目的地.Y座標*/

					& MoveInfo[i].next,             /*次の(配列)処理*/

					& MoveInfo[i].waitTimeFlame,    /*(待ちなど)時間*/

					& MoveInfo[i].attackPattern     /*攻撃方法*/
				 );
			//}
			//	
		}
		return;
	}
	fclose(fp); /*ファイルを閉じる*/
}
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
	InputCSV();
}

/*敵：移動処理*/
void Enemy::Move()
{
	T_Location NextLocation = GetLocation(); /*敵の座標・今の座標を次の座標に入れる*/

	if ((NextLocation.y == MoveInfo[current].TargetLocation.y) && (NextLocation.x == MoveInfo[current].TargetLocation.x)) /*同じ座標にいたら次へ*/
	{
		current = MoveInfo[current].next;
	}
	else /*目的地にいなかったときは*/
	{
		/*縦の移動処理*/
		if (NextLocation.y != MoveInfo[current].TargetLocation.y) /*Y座標*/
		{
			if (NextLocation.y < MoveInfo[current].TargetLocation.y)
			{
				NextLocation.y += speed.y; /*下移動*/

				if ((GetLocation().y <= MoveInfo[current].TargetLocation.y) && (MoveInfo[current].TargetLocation.y <= NextLocation.y)) /*((今のY座標 <= 目的地) && 目的地 <= 次のY座標))*/
				{
					NextLocation.y = MoveInfo[current].TargetLocation.y; /*目的地を飛び超えたとき*/
				}
			}
			else
			{
				NextLocation.y -= speed.y; /*上移動*/

				if ((NextLocation.y <= MoveInfo[current].TargetLocation.y) && (MoveInfo[current].TargetLocation.y <= GetLocation().y)) /*((次のY座標 <= 目的地) && (目的地 <= 今のY座標))*/
				{
					NextLocation.y = MoveInfo[current].TargetLocation.y;
				}
			}
		}
	}
	/*横の移動処理*/
	if (NextLocation.x != MoveInfo[current].TargetLocation.x) /*X座標*/
	{
		if (NextLocation.x < MoveInfo[current].TargetLocation.x)
		{
			NextLocation.x += speed.x; /*右移動*/

			if ((GetLocation().x <= MoveInfo[current].TargetLocation.x) && (MoveInfo[current].TargetLocation.x <= NextLocation.x)) /*((今のX座標 <= 目的地) && 目的地 <= 次のX座標))*/
			{
				NextLocation.x = MoveInfo[current].TargetLocation.x; /*目的地を飛び超えたとき*/
			}
		}
		else
		{
			NextLocation.x -= speed.x; /*左移動*/

			if ((NextLocation.x <= MoveInfo[current].TargetLocation.x) && (MoveInfo[current].TargetLocation.x <= GetLocation().x)) /*((次のX座標 <= 目的地) && (目的地 <= 今のX座標))*/
			{
				NextLocation.x = MoveInfo[current].TargetLocation.x; /*目的地を飛び超えたとき*/
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
	/*敵：移動・攻撃の処理パターン*/
	switch (MoveInfo[current].pattern)
	{
	case 0:
		Move(); /*敵：移動処理*/
		break;

	case 1:
		waitCount++; /*停滞時間++*/

  /*(敵の処理情報[処理用番号].(待ちなど)時間 <= 停滞時間)*/
		if (MoveInfo[current].waitTimeFlame <= waitCount) 
		{
			waitCount = 0; /*停滞時間 = 0*/

			current = MoveInfo[current].next; /*処理用番号 = 敵処理情報[処理用番号].NEXT(次へ)*/
		}
		break;

	default:
		break;
	}

	int bulletCount; /*発射カウント*/

	for (bulletCount = 0; bulletCount < 30; bulletCount++) /*発射カウント*/
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}

		bullets[bulletCount]->Update(); /*弾のアップデート*/

		/*画面外に行ったら弾を消す*/
		if (bullets[bulletCount]->ScreenOut())
		{
			/*弾丸の消去*/
			//delete bullets[BulleCount]; /*弾を消す(デリート)*/
			//bullets[BulleCount] = nullptr; /*NULL POINTER(ヌル・ポインター)で上書き*/

			DeleteBullet(bulletCount);
			bulletCount--;

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
	//if (1) /*自動で*/
	//{
	//	if (bulletCount < 30 && bullets[bulletCount] == nullptr) /*発射カウント*/
	//	{
	//		/*弾幕作成*/                                /*位置*/  /*speed*/ /*発射角度*/
	//		bullets[bulletCount] = new BulletsRotation(GetLocation(), 2.f, (20 * shotNum));
	//
	//		shotNum++; /*足していく*/
	//
	//		                                                   /*BulletsStraightの引数*/
	//		/*bullets[BulleCount] = new BulletsStraight(GetLocation(),T_Location {0,-4}); /*BulletsStraightを作成*/
	//		//bullets[BulleCount] = new EnemyBulletsStraight(GetLocation()); /*強引BulletsStraightを作成*/
	//		//
	//	}
	//}

   /*(敵の処理情報[処理用番号].攻撃方法 != 0)*/
	if (MoveInfo[current].attackPattern != 0) { 
		if (bulletCount < 30 && bullets[bulletCount] == nullptr) /*発射カウント*/
		{
	       /*(敵の処理情報[処理用番号].攻撃方法 == 1)*/
			if (MoveInfo[current].attackPattern == 1) 
			{
				bullets[bulletCount] = new BulletsStraight(GetLocation(), T_Location{ 0, -2 }); /*垂直発射*/
			}
		   /*(敵の処理情報[処理用番号].攻撃方法 == 2)*/
			if (MoveInfo[current].attackPattern == 2) 
			{
				shotNum++;

				bullets[bulletCount] = new BulletsRotation(GetLocation(), 4.f, (20 * shotNum)); /*回転式弾丸発射*/
			}
		}
	}
}

/*敵：描画に関することを実行する*/
void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

	/*弾丸の描画*/
	for (int BulletCount = 0; BulletCount < 30; BulletCount++)
	{
		if (bullets[BulletCount] == nullptr)
		{
			break;
		}
		bullets[BulletCount]->Draw();
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