#pragma once

class KeyManager
{
private: /*exturn禁止の場合*/

	/*キー入力*/
	static char OldKey[256];
	static char NowKey[256];

	/*マウス入力*/
	static int OldMouse;
	static int NowMouse;

private:
	/*コンストラクタにアクセス禁止*/
	KeyManager() = default; 

public:

	//描画以外の更新を実行する
	static void Update();

	/*キー入力処理*/
	static bool OnKeyClicked(int Key);
	static bool OnKeyReleased(int Key);
	static bool OnKeyPressed(int Key);

	/*マウス入力処理*/
	static bool OnMouseClicked(int Key);
	static bool OnMouseReleased(int Key);
	static bool OnMousePressed(int Key);
};

