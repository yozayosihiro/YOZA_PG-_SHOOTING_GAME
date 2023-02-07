#include"DxLib.h"
#include<stdio.h>
#include"Common.h"
#include"AbstractScene.h"
#include"SceneManager.h"
#include"GameMain.h"
#include"KeyManager.h"
#include"TitleScene.h"

/***********************************************
 * 変数の宣言
 ***********************************************/
int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報

GAME_STATE	g_GameState = GAME_STATE::GAME_TITLE; // ゲームステータス

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	/* タイトル*/
	SetMainWindowText("SHOOTING GAME");

	ChangeWindowMode(TRUE);		       // ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);       // 画面を大きくする
	if (DxLib_Init() == -1) return -1; // DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	/*AbstractScene型に戻して、シーンマネージャーオブジェクトの作成*/
	SceneManager SceneMng(dynamic_cast<AbstractScene*>(new TitleScene()));

	// ゲームループ
	while (ProcessMessage() == 0) {
	//while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT) {
	//

			/* 入力キー取得 */
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		// 画面の初期化

		/*キー入力処理確認テスト*/
		//KeyManager::Update();
		//if(KeyManager::OnPressed(KEY_INPUT_A)) /*押されたとき*/
			//if (KeyManager::OnClicked(KEY_INPUT_A)) /*押された瞬間*/
				//if (KeyManager::OnReleased(KEY_INPUT_A)) /*離した瞬間*/
		//{
		//	DrawFormatString(200, 200, 0xffffff, "AAA");
		//}

		/*マウス入力処理確認テスト*/
		//KeyManager::Update();
		//if(KeyManager::OnMousePressed(MOUSE_INPUT_LEFT)) /*押されたとき*/
			//if (KeyManager::OnMouseClicked(MOUSE_INPUT_LEFT)) /*押された瞬間*/
				//if (KeyManager::OnMouseReleased(MOUSE_INPUT_LEFT)) /*離した瞬間*/
		//{
		//	DrawFormatString(200, 200, 0xffffff, "AAA");
		//}

		/*switch処理*/
		//switch (g_GameState) {
		//	case GAME_STATE::GAME_TITLE:
		//		DrawGameTitle();	   //ゲームタイトル処理
		//		break;
		//	case GAME_STATE::GAME_INIT:
		//	 	GameInit();		       //ゲーム初期処理
		//		break;
		//	case GAME_STATE::DRAW_RANKING:
		//		DrawRanking();	       //ランキング描画処理
		//		break;
		//	case GAME_STATE::DRAW_END:
		//		DrawEnd();		      //エンド画面描画処理
		//		break;
		//	case GAME_STATE::GAME_MAIN:
		//		GameMain();		      //ゲームメイン処理
		//		break;
		//	case GAME_STATE::DRAW_GAME_OVER:
		//		DrawGameOver();       //ゲームオーバー描画処理
		//		break;
		//	case GAME_STATE::DRAW_GAME_CLEAR:
		//		DrawGameClear();      //ゲームクリア描画処理
		//		break;
		//	case GAME_STATE::INPUT_RANKING:
		//		InputRanking();       //ランキング入力処理
		//		break;
		//}

		/*シーンマネージャー処理*/
	    //	if (SceneMng.Update() != nullptr)
	//	{
    //
	//		SceneMng.Update();
	//		SceneMng.Draw();
    //
	//		if (SceneMng.ChangeScene() == nullptr)
	//		{
    //
	//			DxLib::DxLib_End();	// DXライブラリ使用の終了処理
    //
	//			return 0;	// ソフトの終了
	//		}
	//	}
	//	else
	//	{
	//		break;
	//	}
    //
	//	ScreenFlip();			// 裏画面の内容を表画面に反映
    //
	//}
    //
	//DxLib::DxLib_End();	// DXライブラリ使用の終了処理
    //
	//return 0;	// ソフトの終了

		SceneMng.Update(); //シーンの更新処理
		SceneMng.Draw();   //シーンの描画処理
		KeyManager::Update(); //マウス・キー入力更新処理

		/*シーンマネージャー・シーンの変更処理*/
		if (SceneMng.ChangeScene() == nullptr)
		{

			DxLib::DxLib_End();	// DXライブラリ使用の終了処理

			return 0;	// ソフトの終了
		}

		ScreenFlip();  // 裏画面の内容を表画面に反映

	}
		
	DxLib::DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了

}