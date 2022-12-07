#include "BulletsRotation.h"
#include"DxLib.h"

#define _USE_MATH_DEFINES

#include<math.h>


                                    /*※1：位置*/   /*※2：スピード*/                            /*※1*/     /*※2*/
BulletsRotation::BulletsRotation(T_Location location, float speed, int degAngle) : BulletsBase(location, T_Location{ 0.0 }, 5.f, 1)
{
	int deg = degAngle % 360; /*角度の単位・360度より下の値*/

	double rad = (M_PI / 180) * deg; /*1度の角度 * 30度の実数値 */
	 
   /*参考演算子         90度 (条件式) 270度 ? TRUE：FALSE*/
	float x = (abs(deg) == 90 || deg == 270 ? 0 : cos(rad)); /*横の進行方向・距離   0除算を回避するため*/

	float y = sin(rad); /*縦の進行方向・距離   sin + cos = 1*/

	              /* 位置   (speed * cos),(speed * sin)*/
	this->speed = T_Location{ (speed * x),(speed * y) }; /*比率　同じスピードを掛ける 0.7を掛ける*/
}

/*回転式弾丸：描画以外の更新を実行する*/
void BulletsRotation::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y += speed.y;
	NewLocation.x += speed.x;

	SetLocation(NewLocation);
}

/*回転式弾丸：描画に関することを実行する*/
void BulletsRotation::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

/*回転式弾丸：画面外処理*/
bool BulletsRotation::ScreenOut()
{
	//bool ret = (GetLocation().y + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 720 || GetLocation().x + GetRadius() <= 0 || GetLocation().x + GetRadius() >= 1200); /*Y軸で0より小さいとき or Y軸で720より大きいとき or X軸で0より小さいとき or X軸で1200より大きいとき ・円が全部画面外の時*/

	/*左右の画面外処理*/
	//bool ret = (GetLocation().y + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 720);  /*0より小さいとき or 720より大きいとき・円が全部画面外の時*/
	//return ret;

	/*上下の画面外処理*/
	//bool ret = (GetLocation().x + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 1200); /*0より小さいとき or 1200より大きいとき・円が全部画面外の時*/
	//return ret;

	/*左右の画面外処理*/
	bool ret = ((GetLocation().x + GetRadius()) <= 0); /*X軸で0より小さいとき*/
	if (ret)
	{
		return ret;
	}
	ret = (1280 <= (GetLocation().x - GetRadius()));   /*X軸で1200より大きいとき*/
	if (ret)
	{
		return ret;
	}


	/*上下の画面外処理*/ 
	ret = ((GetLocation().y + GetRadius()) <= 0);   /*Y軸で0より小さいとき*/
	if (ret)
	{
		return ret;
	}
	ret = (720 <= (GetLocation().y - GetRadius())); /*Y軸で720より大きいとき*/
	if (ret)
	{
		return ret;
	}

	//return ret;
}