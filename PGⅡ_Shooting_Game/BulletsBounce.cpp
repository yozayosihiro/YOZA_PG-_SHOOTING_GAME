#include "BulletsBounce.h"
#include"DxLib.h"

#define _USE_MATH_DEFINES

#include<math.h>
							  
BulletsBounce::BulletsBounce(T_Location location, float speed, float bounceAngle) : BulletsBase(location, T_Location{ 0.0 }, 5.f, 1)
{
	float rad = bounceAngle * (float)M_PI * 2;
	bounceX = (int)(speed * cosf(rad));
	bounceY = (int)(speed * sinf(rad));
}

/*���˕Ԃ莮�e�ہF�`��ȊO�̍X�V�����s����*/
void BulletsBounce::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y += bounceY;
	NewLocation.x += bounceX;

	SetLocation(NewLocation);
}

/*���˕Ԃ莮�e�ہF�`��Ɋւ��邱�Ƃ����s����*/
void BulletsBounce::Draw()
{

}

/*���˕Ԃ莮�e�ہF��ʒ��˕Ԃ�*/
void BulletsBounce::ScreenBounce()
{
	
}