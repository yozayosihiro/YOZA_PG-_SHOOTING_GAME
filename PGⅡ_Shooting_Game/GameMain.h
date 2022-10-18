#pragma once
#include"AbstractScene.h"
#include"Player.h"

/*ゲームメインクラス*/
class GameMainScene : public AbstractScene {

private:

/*確保してる箱が多いので一応*/
	Player* player; 

public:

	/*コンストラクタ*/
	GameMainScene();

	//デストラクタ
	virtual ~GameMainScene() {};

public:

	//描画以外の更新を実行する
	virtual void Update()  override;
	//virtual void Draw() const = 0;
	//virtual AbstractScene* Update() override;
	
	//描画に関することを実装する
	virtual void Draw() const override;

	//シーンの変更処理
	virtual AbstractScene* ChangeScene() override;
	//virtual AbstractScene* ChangeScene() = 0;
	//
};
