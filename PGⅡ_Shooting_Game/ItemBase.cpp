#include "ItemBase.h"

/*アイテム：コンストラクタ*/
ItemBase::ItemBase(T_Location location, float radius, enum_ItemType type, T_Location speed) : SpherCollider(location, radius), type(type), speed(speed) /*引数を渡している*/
{

}

/*アイテムのタイプ処理：enum_ItemTypeを返す処理*/
enum_ItemType ItemBase::GetType()
{
	return type;
}