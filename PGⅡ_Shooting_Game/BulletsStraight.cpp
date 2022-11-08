#include"DxLib.h"
#include "BulletsStraight.h"

BulletsStraight::BulletsStraight(T_Location location) : BulletsBase(location, T_Location{ 0,2 }, 5.0f, 3)
{

}

/*�����Ȓe�ہF�`��ȊO�̍X�V�����s����*/
void BulletsStraight::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y -= speed.y;

	SetLocation(NewLocation);
}

/*�����Ȓe�ہF�`��Ɋւ��邱�Ƃ����s����*/
void BulletsStraight::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

/*�����Ȓe�ہF��ʊO����*/
bool BulletsStraight::ScreenOut()
{
	bool ret = (GetLocation().y + GetRadius() <= 0); /*0��菬�����Ƃ��E�~���S����ʊO�̎�*/

		return ret;
}
