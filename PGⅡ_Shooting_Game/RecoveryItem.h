#pragma once
#include "ItemBase.h"

class RecoveryItem : public ItemBase
{
private:

	int volume_item; /*回復アイテム量*/

protected:

public:

public:

	/*回復アイテム：描画以外の更新を実行する*/
	virtual void Update() override;

	/*回復アイテム：描画に関することを実行する*/
	virtual void Draw() override;

	/*アイテム：回復量*/
	int GetVolumeItem();

};

