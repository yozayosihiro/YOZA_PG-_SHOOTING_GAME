#include "RecoveryItem.h"
#include"DxLib.h"

/*�񕜃A�C�e���F�R���X�g���N�^*/                                                                        /*speed�l*/
RecoveryItem::RecoveryItem(T_Location location) : ItemBase(location, 5.f, enum_ItemType::HEAL, T_Location{ 0,1 }), volume_item(2)
{

}

/*�񕜃A�C�e���F�`��ȊO�̍X�V�����s����*/
void RecoveryItem::Update()
{
	/*Location��Location�Ɉړ������鏈��*/
	T_Location NewLocation = GetLocation();

	NewLocation.y += speed.y; /*�A�C�e���̓X�s�[�h�̒l���݂Ĉړ�*/
	SetLocation(NewLocation);
 }

/*�񕜃A�C�e���F�`��Ɋւ��邱�Ƃ����s����*/
void RecoveryItem::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 255));
 }

/*�A�C�e���F�񕜗�*/
int RecoveryItem::GetVolumeItem()
{
	return volume_item;
}