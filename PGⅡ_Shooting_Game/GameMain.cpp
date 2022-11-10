#include"GameMain.h"
#include"RecoveryItem.h"

/*描画以外の更新を実行する*/
//AbstractScene* GameMainScene::Update() {
//
//
//	return this;
//}

/*描画に関することを実行する*/
//void GameMainScene::Draw() const {
//
//	
//}

/*描画に関することを実行する*/
//void GameMainScene::Draw() const {
//
//	mScene->Draw();
//}
//

/*シーンの変更処理*/
//AbstractScene* GameMainScene::ChangeScene() {
//
//	//シーンの変更処理呼び出し
//	AbstractScene* NextScene = mScene->ChangeScene();
//
//	//次のシーンが現在シーンと別なら現行
//	if (NextScene != mScene)
//	{
//		delete mScene;
//
//		mScene = NextScene;
//	}
//
//	return NextScene;
//}

/*ゲームメイン：描画以外の更新を実行する*/
void GameMainScene::Update() {

	/************** 当たり判定・テスト **************/
	/*T_Location location = T_Location{ 100,100 };

	Player test = Player(location);

	test.Draw();

	if (test.HitSphere(player))
	{
		return;
	}*/
	/************************************************/

	player->Update();

	int EnemyCount;

	/*ループのための変数*/
	int BulletCount;

	/*アイテムUpdate処理*/
	for (int i = 0; i < 10; i++)
	{
		if (item[i] == nullptr)
		{
			break;
		}
		item[i]->Update();
	}

	BulletsBase** bullet = player->GetBullets();
	for (EnemyCount = 0; EnemyCount < 10; EnemyCount++) /*敵が10体に増えるまで*/
	{
		if (enemy[EnemyCount] == nullptr)
		{
			break;
		}

		/*エネミーの更新*/
		enemy[EnemyCount]->Update();

		/*for (int i = 0; i < 10; i++)
		{
			if (item[i] == nullptr)
			{
				break;
			}

			item[i]->Update();
		}*/

		for (BulletCount = 0; BulletCount < 30; BulletCount++) /*弾30発*/
		{
			if (bullet[BulletCount] == nullptr)
			{
				break;
			}

			/*当たり判定*/
			if (enemy[EnemyCount]->HitSphere(bullet[BulletCount])) /*エネミーにプレイヤーの弾がヒットしている*/
			{

				/*エネミーにダメージを与える*/
				enemy[EnemyCount]->Hit(bullet[BulletCount]->GetDamege());/*色々と呼び出している*/

				/*弾を削除*/
				player->DeleteBullet(BulletCount);
				BulletCount--;

				/*エネミーのHPが0以下だったら、エネミーを削除*/
				if (enemy[EnemyCount]->HpCheck())
				{
					for (int i = 0; i < 10; i++)
					{
						if (item[i] == nullptr) /*敵からアイテム*/
						{
							item[i] = new RecoveryItem(enemy[EnemyCount]->GetLocation());
							break;
						}
					}

					/*スコア加算*/
					player->AddScore(enemy[EnemyCount]->GetPoint());
					
					/*エネミーの削除*/
					//player->DeleteBullet(EnemyCount);
					//EnemyCount--;

					/*エネミーの削除*/
					delete enemy[EnemyCount]; /*敵を消す(デリート)*/
					enemy[EnemyCount] = nullptr; /*NULL POINTER(ヌル・ポインター)で上書き*/

					/*配列を前に詰める・++ */
					//for (int i = EnemyCount; i < 30 - 1; i++) /*28までループ*/
					//{
					//	if (enemy[i + 1] == nullptr)
					//	{
					//		break;
					//	}
					//	enemy[i] = enemy[i + 1]; /*後ろを前に*//*ループ*/
					//	enemy[i + 1] = nullptr; /*後ろをNULL POINTER(ヌル・ポインター)で上書き*/
					//}
					//
					//EnemyCount--;

					/*配列を前に詰める・-- */
					for (int i = EnemyCount + 1; i < 10; i++) /*2から始まって29で終わる*/
					{
						if (enemy[i] == nullptr)
						{
							break;
						}
						enemy[i - 1] = enemy[i]; /*後ろを前に*//*ループ*/
						enemy[i] = nullptr; /*後ろをNULL POINTER(ヌル・ポインター)で上書き*/
					}

					EnemyCount--;  /*EnemyCountを0にする*/
					break;        /*for文を抜ける*/
				}
			}
		}
	}
		for (int ItemCount = 0; ItemCount < 10; ItemCount++)
		{
			if (item[ItemCount] == nullptr)
			{
				break;
			}
			if (item[ItemCount]->HitSphere(player))
			{
				/*エネミーの削除*/
				delete item[ItemCount]; /*敵を消す(デリート)*/
				item[ItemCount] = nullptr; /*NULL POINTER(ヌル・ポインター)で上書き*/

				/*配列を前に詰める・-- */
				for (int i = ItemCount + 1; i < 10; i++) /*2から始まって29で終わる*/
				{
					if (item[i] == nullptr)
					{
						break;
					}
					item[i - 1] = item[i]; /*後ろを前に*//*ループ*/
					item[i] = nullptr; /*後ろをNULL POINTER(ヌル・ポインター)で上書き*/
				}

				ItemCount--;  /*EnemyCountを0にする*/
			}
		}
}

/*ゲームメイン：描画に関することを実行する*/
void GameMainScene::Draw() const {

	player->Draw();

	for (int EnemyCount = 0; EnemyCount < 10; EnemyCount++) /*敵が10体に増えるまで*/
	{
		if (enemy[EnemyCount] == nullptr)
		{
			break;
		}

		enemy[EnemyCount]->Draw();
	}

	/*アイテムDraw処理*/
	for (int i = 0; i < 10; i++)
	{
		if (item[i] == nullptr)
		{
			break;
		}
		item[i]->Draw();
	}
}

/*ゲームメイン：シーンの変更処理*/
AbstractScene* GameMainScene::ChangeScene() {

	return this;
}

/***********************************************
 * ゲームメイン
 ***********************************************/
GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,100 };/*プレイヤーの出現位置*/

	player = new Player(location);

	enemy = new Enemy * [10];

	for (int i = 0; i < 10; i++) /*敵の初期化*/
	{
		enemy[i] = nullptr; /*nullpointerで初期化*/
	}

	/*アイテム初期化*/
	/*newで領域確保*/
	enemy[0] = new Enemy(T_Location{200,0}); /*敵を一体だけ作る*/

	item = new ItemBase * [10];

	for (int i = 0; i < 10; i++)
	{
		item[i] = nullptr; /*初期化*/
	}
}
