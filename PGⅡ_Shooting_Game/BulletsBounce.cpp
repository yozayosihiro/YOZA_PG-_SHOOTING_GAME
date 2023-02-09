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

/*跳ね返り式弾丸：描画以外の更新を実行する*/
void BulletsBounce::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y += bounceY;
	NewLocation.x += bounceX;

	SetLocation(NewLocation);
}

/*跳ね返り式弾丸：描画に関することを実行する*/
void BulletsBounce::Draw()
{

}

/*跳ね返り式弾丸：画面跳ね返り*/
void BulletsBounce::ScreenBounce()
{
	
}