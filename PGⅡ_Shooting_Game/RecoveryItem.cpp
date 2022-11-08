#include "RecoveryItem.h"
#include"DxLib.h"

/*回復アイテム：描画以外の更新を実行する*/
void RecoveryItem::Update()
{

 }

/*回復アイテム：描画に関することを実行する*/
void RecoveryItem::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 255));
 }

/*アイテム：回復量*/
int RecoveryItem::GetVolumeItem()
{
	return volume_item;
}