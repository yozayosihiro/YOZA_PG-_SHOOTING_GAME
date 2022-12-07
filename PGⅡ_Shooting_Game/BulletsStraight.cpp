#include"DxLib.h"
#include "BulletsStraight.h"
                                     /*��1�F�ʒu*/    /*��2�F�X�s�[�h*/                /*��1*/ /*��2*/
BulletsStraight::BulletsStraight(T_Location location, T_Location speed) : BulletsBase(location, speed, 5.0f, 3)
{

}

/*�����Ȓe�ہF�`��ȊO�̍X�V�����s����*/
void BulletsStraight::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y -= speed.y;
	//NewLocation.y += speed.y;
	//

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
	bool ret = (GetLocation().y + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 720); /*0��菬�����Ƃ� or 720���傫���Ƃ��E�~���S����ʊO�̎�*/

		return ret;
}
