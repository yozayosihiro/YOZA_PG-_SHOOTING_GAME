#include "BulletsBase.h"

BulletsBase::BulletsBase(T_Location location, T_Location speed, float radius, int damage) : SpherCollider(location, radius), damage(damage), speed(speed)
{

}


/*弾丸：ダメージ処理*/
int BulletsBase::GetDamege()
{
	return damage;
}

