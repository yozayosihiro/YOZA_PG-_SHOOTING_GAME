#include "RecoveryItem.h"
#include"DxLib.h"

/*�񕜃A�C�e���F�`��ȊO�̍X�V�����s����*/
void RecoveryItem::Update()
{

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