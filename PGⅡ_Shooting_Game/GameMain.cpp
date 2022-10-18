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

	player->Update();
}

/*描画に関することを実行する*/
void GameMainScene::Draw() const {

	player->Draw();
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
}
