#pragma once
#include"SpherCollider.h"
#include"enum_ItemType.h"

class ItemBase : public SpherCollider
{
private:

	enum_ItemType type;

protected:

	T_Location speed;

public:

public:

	/*アイテム：描画以外の更新を実行する*/
	virtual void Update() = 0;

	/*アイテム：描画に関することを実行する*/
	virtual void Draw() = 0;

	/*アイテムのタイプ処理：enum_ItemTypeを返す処理*/
	enum_ItemType GetType();
};

