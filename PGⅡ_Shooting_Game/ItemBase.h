#pragma once
#include"SpherCollider.h"
#include"enum_ItemType.h"

class ItemBase : public SpherCollider
{
private:

	/*アイテム：種類*/
	enum_ItemType type;

protected:

	/*アイテム：スピード*/
	T_Location speed;

public: /*アイテム：コンストラクタ*/

	/*アイテム：コンストラクタ(T_Location 位置, float 半径, enumアイテム, T_Location スピード)*/
	ItemBase(T_Location location, float radius, enum_ItemType type, T_Location speed);

public:

	/*アイテム：描画以外の更新を実行する*/
	virtual void Update() = 0;

	/*アイテム：描画に関することを実行する*/
	virtual void Draw() = 0;

	/*アイテムのタイプ処理：enum_ItemTypeを返す処理*/
	enum_ItemType GetType();
};

