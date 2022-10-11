#include"DxLib.h"
#include<stdio.h>
#include"Common.h"
#include"AbstractScene.h"
#include"SceneManager.h"
#include"GameMain.h"

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

	/* タイトルを test に変更 */
	SetMainWindowText("SHOOTING GAME");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	/*タイトル画像データの読み込み*/
	//if ((g_TitleImage = LoadGraph("images/Title.png")) == -1) return -1;
	/*ランキング画像データの読み込み*/
	//if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;
	/*エンド画像データの読み込み*/
	//if ((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;
	/*ブロック画像データの読み込み*/
	//if (LoadDivGraph("images/Block.bmp", 8, 8, 1, 40, 8, g_BlockImage) == -1) return -1;

	/*ランキングデータの読み込み*/
	//if (ranking.ReadRanking() == -1)  return  -1;    

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	/*シーンマネージャーオブジェクトの作成*/
	SceneManager SceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));

	// ゲームループ
	while (ProcessMessage() == 0) {
	//while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT) {
	//

			/* 入力キー取得 */
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		// 画面の初期化

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