#pragma once
#include "ItemBase.h"

class RecoveryItem : public ItemBase
{
private:

	int volume_item; /*回復アイテム量*/

protected:

public:

	/*回復アイテム：コンストラクタ*/
	RecoveryItem(T_Location location);
	//RecoveryItem(T_Location location, float radius, enum_ItemType type, T_Location speed); /*細かくしたいなら*/
	//

public:

	/*回復アイテム：描画以外の更新を実行する*/
	virtual void Update() override;

	/*回復アイテム：描画に関することを実行する*/
	virtual void Draw() override;

	/*アイテム：回復量*/
	int GetVolumeItem();

};

