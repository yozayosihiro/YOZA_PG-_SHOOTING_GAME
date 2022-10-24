#include "KeyManager.h"
#include"DxLib.h"

/*キー初期化*/
 char KeyManager::OldKey[256];
 char KeyManager::NowKey[256];

 /*マウス初期化*/
 int KeyManager::OldMouse;
 int KeyManager::NowMouse;

/*描画以外の更新を実行する*/
void KeyManager::Update()
{
	for (int i = 0; i < 256; i++)
	{
		OldKey[i] = NowKey[i];
	}

	if (GetHitKeyStateAll(NowKey) == -1)
	{
		throw - 1;
	}

	OldMouse = NowMouse;

	NowMouse = GetMouseInput();
}

/*******************************キー入力処理*******************************************/
/*キーボタンを押してるか押してないか*/
bool KeyManager::OnKeyClicked(int Key)
{
	/*NowKeyが押されてOldKeyが押されてないとき*/
	bool ret = (NowKey[Key] == 1) && (OldKey[Key] != 1); /*毎フレーム押されてないか*/
	return ret;
}

/*キーボタンを離した瞬間・今は押されてないけど前は押されてた*/
bool KeyManager::OnKeyReleased(int Key)
{
	bool ret = (NowKey[Key] != 1) && (OldKey[Key] == 1);/*ボタンを離した瞬間*/
	return ret;
}

/*キーボタンを押している間・キーボタンを押され続けている*/
bool KeyManager::OnKeyPressed(int Key)
{
	bool ret = (NowKey[Key] == 1);/*ボタンを押され続けている*/
	return ret;
}
/*******************************キー入力処理*******************************************/

/******************************マウス入力処理******************************************/
/*マウスクリックしてるか押してないか*/
bool KeyManager::OnMouseClicked(int Key)
{
	bool ret = ((NowMouse & Key) && (OldMouse & Key));
	return ret;
}

/*マウスクリックボタンを離した瞬間・今は押されてないけど前は押されてた*/
 bool KeyManager::OnMouseReleased(int Key)
{
	 bool ret = ((NowMouse & Key != 1) && (OldMouse & Key == 1));
	 return ret;
}

 /*マウスクリックしている間・マウスクリックボタンを押され続けている*/
 bool KeyManager::OnMousePressed(int Key)
 {
	 bool ret = ((NowMouse & Key == 1));
	 return ret;
 }
 /******************************マウス入力処理******************************************/