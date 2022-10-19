#include<stdio.h>
#include"AbstractScene.h"
#include"SceneManager.h"

/*描画以外の更新を実行する*/
//AbstractScene* SceneManager::Update() {

/*メンバ変数の値を書き換えるのがメンバ*/
void SceneManager :: Update() {

	  mScene->Update();

}

/*描画に関することを実行する*/
void SceneManager::Draw() const {

	mScene->Draw();
}

/*シーンの変更処理*/
AbstractScene* SceneManager::ChangeScene() {

	//シーンの変更処理呼び出し
	AbstractScene* NextScene = mScene->ChangeScene();

	//次のシーンが現在シーンと別なら現行
	if (NextScene != mScene)
	{
		delete mScene;

		mScene = NextScene;
	}

	return NextScene;
}