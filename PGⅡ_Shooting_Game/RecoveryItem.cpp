#include "RecoveryItem.h"
#include"DxLib.h"

/*回復アイテム：コンストラクタ*/                                                                        /*speed値*/
RecoveryItem::RecoveryItem(T_Location location) : ItemBase(location, 5.f, enum_ItemType::HEAL, T_Location{ 0,1 }), volume_item(2)
{

}

/*回復アイテム：描画以外の更新を実行する*/
void RecoveryItem::Update()
{
	/*LocationをLocationに移動させる処理*/
	T_Location NewLocation = GetLocation();

	NewLocation.y += speed.y; /*アイテムはスピードの値をみて移動*/
	SetLocation(NewLocation);
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