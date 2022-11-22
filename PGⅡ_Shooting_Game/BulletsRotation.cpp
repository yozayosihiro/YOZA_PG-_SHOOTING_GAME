#include "BulletsRotation.h"
#include"DxLib.h"

                                     /*��1�F�ʒu*/    /*��2�F�X�s�[�h*/                /*��1*/ /*��2*/
BulletsRotation::BulletsRotation(T_Location location, T_Location speed) : BulletsBase(location, speed, 5.0f, 3)
{

}

/*�����Ȓe�ہF�`��ȊO�̍X�V�����s����*/
void BulletsRotation::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y -= speed.y;
	/*NewLocation.y += speed.y;*/

	SetLocation(NewLocation);
}

/*�����Ȓe�ہF�`��Ɋւ��邱�Ƃ����s����*/
void BulletsRotation::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

/*�����Ȓe�ہF��ʊO����*/
bool BulletsRotation::ScreenOut()
{
	bool ret = (GetLocation().y + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 720 || GetLocation().x + GetRadius() <= 0 || GetLocation().x + GetRadius() >= 1200); /*Y����0��菬�����Ƃ� or Y����720���傫���Ƃ� or X����0��菬�����Ƃ� or X����1200���傫���Ƃ� �E�~���S����ʊO�̎�*/

	return ret;
}