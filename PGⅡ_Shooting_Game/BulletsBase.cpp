#include "BulletsBase.h"

BulletsBase::BulletsBase(T_Location location, T_Location speed, float radius, int damage) : SpherCollider(location, radius), damage(damage), speed(speed)
{

}


/*�e�ہF�_���[�W����*/
int BulletsBase::GetDamege()
{
	return damage;
}

