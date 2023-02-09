#include "OverScene.h"

#include"TitleScene.h"
#include"DxLib.h"
#include"KeyManager.h"

/*ゲームメイン：描画以外の更新を実行する*/
void OverScene::Update()
{

}

/*ゲームメイン：ゲームメイン：描画に関することを実装する*/
void OverScene::Draw() const
{
	DrawString(0, 100, "Aキーでタイトル", 0xfffffff);

	SetFontSize(30);
	DrawString(300, 300, "ゲームオーバー", 0xfffffff);
}

/*ゲームメイン：シーンの変更処理*/
AbstractScene* OverScene::ChangeScene()
{
	if (KeyManager::OnKeyClicked(KEY_INPUT_A)) /*ボタンを押して*/
	{
		return dynamic_cast<AbstractScene*>(new TitleScene()); /*AbstractScene型に戻して、newでGameMainScene()を作成*/
	}
	return this; /*更新なし*/
}