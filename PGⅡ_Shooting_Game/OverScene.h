#pragma once
#include "AbstractScene.h"

class OverScene : public AbstractScene
{
	/*ゲームメイン：描画以外の更新を実行する*/
	virtual void Update();

	/*ゲームメイン：ゲームメイン：描画に関することを実装する*/
	virtual void Draw() const;

	/*ゲームメイン：シーンの変更処理*/
	virtual AbstractScene* ChangeScene();
};

