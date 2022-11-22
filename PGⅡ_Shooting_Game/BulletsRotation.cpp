#include "BulletsRotation.h"
#include"DxLib.h"

                                     /*※1：位置*/    /*※2：スピード*/                /*※1*/ /*※2*/
BulletsRotation::BulletsRotation(T_Location location, T_Location speed) : BulletsBase(location, speed, 5.0f, 3)
{

}

/*率直な弾丸：描画以外の更新を実行する*/
void BulletsRotation::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y -= speed.y;
	/*NewLocation.y += speed.y;*/

	SetLocation(NewLocation);
}

/*率直な弾丸：描画に関することを実行する*/
void BulletsRotation::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

/*率直な弾丸：画面外処理*/
bool BulletsRotation::ScreenOut()
{
	bool ret = (GetLocation().y + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 720 || GetLocation().x + GetRadius() <= 0 || GetLocation().x + GetRadius() >= 1200); /*Y軸で0より小さいとき or Y軸で720より大きいとき or X軸で0より小さいとき or X軸で1200より大きいとき ・円が全部画面外の時*/

	return ret;
}