#include"DxLib.h"
#include "BulletsStraight.h"
                                     /*※1：位置*/    /*※2：スピード*/                /*※1*/ /*※2*/
BulletsStraight::BulletsStraight(T_Location location, T_Location speed) : BulletsBase(location, speed, 5.0f, 3)
{

}

/*率直な弾丸：描画以外の更新を実行する*/
void BulletsStraight::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y -= speed.y;
	//NewLocation.y += speed.y;
	//

	SetLocation(NewLocation);
}

/*率直な弾丸：描画に関することを実行する*/
void BulletsStraight::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

/*率直な弾丸：画面外処理*/
bool BulletsStraight::ScreenOut()
{
	bool ret = (GetLocation().y + GetRadius() <= 0 || GetLocation().y + GetRadius() >= 720); /*0より小さいとき or 720より大きいとき・円が全部画面外の時*/

		return ret;
}
