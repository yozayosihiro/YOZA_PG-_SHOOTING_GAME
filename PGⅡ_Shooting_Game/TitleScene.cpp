#include "TitleScene.h"
#include"GameMain.h"
#include"DxLib.h"
#include"KeyManager.h"

/*ゲームメイン：描画以外の更新を実行する*/
void TitleScene::Update()
{
	
 }

/*ゲームメイン：ゲームメイン：描画に関することを実装する*/
void TitleScene::Draw() const
{
	
 }

/*ゲームメイン：シーンの変更処理*/
AbstractScene * TitleScene::ChangeScene() 
{
	if (KeyManager::OnKeyClicked(KEY_INPUT_A)) /*ボタンを押して*/
	{
		return dynamic_cast<AbstractScene*>(new GameMainScene()); /*AbstractScene型に戻して、newでGameMainScene()を作成*/
	}
	return this; /*更新なし*/
}