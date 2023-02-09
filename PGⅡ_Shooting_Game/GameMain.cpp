#include"GameMain.h"
#include"RecoveryItem.h"
#include"OverScene.h"

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
	//enemy[0] = new Enemy(T_Location{200,0}); /*敵を一体だけ作る*/
	//

	enemy[0] = new Enemy(T_Location{ 1280 / 2,0 }); /*真ん中に生成  敵を一体だけ作る*/
	enemy[1] = new Enemy(T_Location{ 1280 / 4,0 }); /*真ん中に生成  敵,二体目*/

	item = new ItemBase * [10];

	for (int i = 0; i < 10; i++)
	{
		item[i] = nullptr; /*初期化*/
	}
}

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

	   /*敵の弾とプレイヤーの当たり判定　完成*/
	   /*敵の弾を取ってくる
	   for(弾をループで参照)
	   {
			if(敵の弾とプレイヤーの当たり判定)
			{
				 プレイヤーにダメージを与える

				 敵の弾を削除する
			}
	   }*/

		/*敵の弾を取ってくる 完成*/
		//BulletsBase** EnemyBullet = enemy[EnemyCount]->GetBullets();

		/*弾をループで参照 完成*/
		//for (int BulletCount = 0; BulletCount < 30; BulletCount++) /*弾30発*/
		//{
		//	if (EnemyBullet[BulletCount] == nullptr)
		//	{
		//		break;
		//	}
		//	 /*敵の弾とプレイヤーの当たり判定*/
		//	if (player->HitSphere(EnemyBullet[BulletCount])) /*エネミーにプレイヤーの弾がヒットしている*/
		//	{
		//		/*プレイヤーにダメージを与える*/
		//		player->Hit(EnemyBullet[BulletCount]->GetDamege());/*色々と呼び出している*/
		//
		//		/*敵の弾を削除する*/
		//		enemy[EnemyCount]->DeleteBullet(BulletCount);
		//
		//		BulletCount--;
		//
		//		/*プレイヤーの削除*/
		//		//delete player; /*敵を消す(デリート)*/
		//	}
		//}

		for (int i = 0; i < 10; i++)
		{
			if (item[i] == nullptr)
			{
				break;
			}
			item[i]->Update();
		}

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
	   /*敵の弾とプレイヤーの当たり判定 完成(見本)*/
	   /*敵の弾を取ってくる
	   for(弾をループで参照)
	   {
			if(敵の弾とプレイヤーの当たり判定)
			{
				 プレイヤーにダメージを与える

				 敵の弾を削除する
			}
	   }*/

	    /*弾をループで参照 完成(見本)*/
		for (EnemyCount = 0; EnemyCount < 30; EnemyCount++) /*弾30発*/
		{
			if (enemy[EnemyCount] == nullptr)
			{
				break;
			}
			bullet = enemy[EnemyCount]->GetBullets();

			for (int i = 0; i < 30; i++)
			{
				if (bullet[i] == nullptr)

					break;

				if (player->HitSphere(bullet[i]))
				{
					player->Hit(bullet[i]->GetDamege());

					enemy[EnemyCount]->DeleteBullet(i);

					i--; //もう一回見る
				}
			}
		}
	
		/*アイテムの削除処理*/
		for (int ItemCount = 0; ItemCount < 10; ItemCount++)
		{
			if (item[ItemCount] == nullptr)
			{
				break;
			}
			/*アイテムの削除処理*/
			if (item[ItemCount]->HitSphere(player)) /*アイテムとプレイヤーの当たり判定*/
			{
				/*回復処理*/
				player->Hit(item[ItemCount]);

				/*アイテムの削除*/
				delete item[ItemCount]; /*アイテムを消す(デリート)*/
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

				ItemCount--;  /*ItemCountを0にする*/
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
AbstractScene* GameMainScene::ChangeScene() 
{
	if (player->LifeCheck()) //プレイヤーのHPが0だったら
	{
		return dynamic_cast<AbstractScene*>(new OverScene()); /*AbstractScene型に戻して、newでOverScene()を作成*/
	}
	return this;
}
