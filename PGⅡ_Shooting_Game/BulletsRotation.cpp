#include "BulletsRotation.h"
#include"DxLib.h"

#define _USE_MATH_DEFINES

#include<math.h>


                                    /*��1�F�ʒu*/   /*��2�F�X�s�[�h*/                            /*��1*/     /*��2*/
BulletsRotation::BulletsRotation(T_Location location, float speed, int degAngle) : BulletsBase(location, T_Location{ 0.0 }, 5.f, 1)
{
	int deg = degAngle % 360; /*�p�x�̒P�ʁE360�x��艺�̒l*/

	double rad = (M_PI / 180) * deg; /*1�x�̊p�x * 30�x�̎����l */
	 
   /*�Q�l���Z�q         90�x (������) 270�x ? TRUE�FFALSE*/
	float x = (abs(deg) == 90 || deg == 270 ? 0 : cos(rad)); /*���̐i�s�����E����   0���Z��������邽��*/

	float y = sin(rad); /*�c�̐i�s�����E����   sin + cos = 1*/

	              /* �ʒu   (speed * cos),(speed * sin)*/
	this->speed = T_Location{ (speed * x),(speed * y) }; /*�䗦�@�����X�s�[�h���|���� 0.7���|����*/
}

/*��]���e�ہF�`��ȊO�̍X�V�����s����*/
void BulletsRotation::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y += speed.y;
	NewLocation.x += speed.x;

	SetLocation(NewLocation);
}

/*��]���e�ہF�`��Ɋւ��邱�Ƃ����s����*/
void BulletsRotation::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

/*��]���e�ہF��ʊO����*/
bool BulletsRotation::ScreenOut()
{
	//bool ret = (GetLocation().y + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 720 || GetLocation().x + GetRadius() <= 0 || GetLocation().x + GetRadius() >= 1200); /*Y����0��菬�����Ƃ� or Y����720���傫���Ƃ� or X����0��菬�����Ƃ� or X����1200���傫���Ƃ� �E�~���S����ʊO�̎�*/

	/*���E�̉�ʊO����*/
	//bool ret = (GetLocation().y + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 720);  /*0��菬�����Ƃ� or 720���傫���Ƃ��E�~���S����ʊO�̎�*/
	//return ret;

	/*�㉺�̉�ʊO����*/
	//bool ret = (GetLocation().x + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 1200); /*0��菬�����Ƃ� or 1200���傫���Ƃ��E�~���S����ʊO�̎�*/
	//return ret;

	/*���E�̉�ʊO����*/
	bool ret = ((GetLocation().x + GetRadius()) <= 0); /*X����0��菬�����Ƃ�*/
	if (ret)
	{
		return ret;
	}
	ret = (1280 <= (GetLocation().x - GetRadius()));   /*X����1200���傫���Ƃ�*/
	if (ret)
	{
		return ret;
	}


	/*�㉺�̉�ʊO����*/ 
	ret = ((GetLocation().y + GetRadius()) <= 0);   /*Y����0��菬�����Ƃ�*/
	if (ret)
	{
		return ret;
	}
	ret = (720 <= (GetLocation().y - GetRadius())); /*Y����720���傫���Ƃ�*/
	if (ret)
	{
		return ret;
	}

	//return ret;
}