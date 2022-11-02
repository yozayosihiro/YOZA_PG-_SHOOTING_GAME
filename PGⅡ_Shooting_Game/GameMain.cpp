#include"GameMain.h"

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

/*描画以外の更新を実行する*/
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

	BulletsBase** bullet = player->GetBullets();

	for (EnemyCount = 0; EnemyCount < 10; EnemyCount++) /*敵が10体に増えるまで*/
	{
		if (enemy[EnemyCount] == nullptr)
		{
			break;
		}

		/*エネミーの更新*/
		enemy[EnemyCount]->Update();

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
					/*エネミーの削除*/

				}
			}
		}
	}
}

/*描画に関することを実行する*/
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
}

/*シーンの変更処理*/
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

	enemy[0] = new Enemy(T_Location{200,0}); /*敵を一体だけ作る*/
}
