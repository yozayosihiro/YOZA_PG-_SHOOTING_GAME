#include"DxLib.h"
#include "BulletsStraight.h"

BulletsStraight::BulletsStraight(T_Location location) : BulletsBase(location, T_Location{ 0,2 }, 5.0f, 3)
{

}

/*率直な弾丸：描画以外の更新を実行する*/
void BulletsStraight::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y -= speed.y;

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
	bool ret = (GetLocation().y + GetRadius() <= 0); /*0より小さいとき・円が全部画面外の時*/

		return ret;
}
