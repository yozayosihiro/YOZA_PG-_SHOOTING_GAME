//#include "MouseManager.h"
//#include <DxLib.h>
//
///*マウス初期化*/
//int MouseManager::OldMouse;
//int MouseManager::NowMouse;
//
///*描画以外の更新を実行する*/
//void MouseManager::Update()
//{
//	for (int i = 0; i < 256; i++)
//	{
//		OldMouse[i] = NowMouse[i];
//	}
//
//	if (GetHitKeyStateAll(NowMouse) == -1)
//	{
//		throw - 1;
//	}
//
//	OldMouse = NowMouse;
//
//	NowMouse = GetMouseInput();
//}
//
//
///******************************マウス入力処理******************************************/
///*マウスクリックしてるか押してないか*/
//bool MouseManager::OnMouseClicked(int Key)
//{
//	bool ret = ((NowMouse & Key) && (OldMouse & Key));
//	return ret;
//}
//
///*マウスクリックボタンを離した瞬間・今は押されてないけど前は押されてた*/
//bool MouseManager::OnMouseReleased(int Key)
//{
//	bool ret = ((NowMouse & Key != 1) && (OldMouse & Key == 1));
//	return ret;
//}
//
///*マウスクリックしている間・マウスクリックボタンを押され続けている*/
//bool MouseManager::OnMousePressed(int Key)
//{
//	bool ret = ((NowMouse & Key == 1));
//	return ret;
//}
///******************************マウス入力処理******************************************/