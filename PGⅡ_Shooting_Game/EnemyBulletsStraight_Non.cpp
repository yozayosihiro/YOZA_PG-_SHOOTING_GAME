#include "EnemyBulletsStraight.h"
#include"DxLib.h"

EnemyBulletsStraight::EnemyBulletsStraight(T_Location location) : BulletsBase(location, T_Location{ 0, - 2 }, 5.0f, 3)
{

}



/*�����Ȓe�ہF�`��ȊO�̍X�V�����s����*/
void EnemyBulletsStraight::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y -= speed.y;

	SetLocation(NewLocation);
}

/*�����Ȓe�ہF�`��Ɋւ��邱�Ƃ����s����*/
void EnemyBulletsStraight::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

/*�����Ȓe�ہF��ʊO����*/
bool EnemyBulletsStraight::ScreenOut()
{
	bool ret = (GetLocation().y + GetRadius() <= 0); /*0��菬�����Ƃ��E�~���S����ʊO�̎�*/

	return ret;
}