#include "ItemBase.h"

/*�A�C�e���F�R���X�g���N�^*/
ItemBase::ItemBase(T_Location location, float radius, enum_ItemType type, T_Location speed) : SpherCollider(location, radius), type(type), speed(speed) /*������n���Ă���*/
{

}

/*�A�C�e���̃^�C�v�����Fenum_ItemType��Ԃ�����*/
enum_ItemType ItemBase::GetType()
{
	return type;
}