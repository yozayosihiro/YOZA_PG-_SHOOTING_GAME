#include "EnemyBulletsStraight.h"
#include"DxLib.h"

EnemyBulletsStraight::EnemyBulletsStraight(T_Location location) : BulletsBase(location, T_Location{ 0, - 2 }, 5.0f, 3)
{

}



/*率直な弾丸：描画以外の更新を実行する*/
void EnemyBulletsStraight::Update()
{
	T_Location NewLocation = GetLocation();

	NewLocation.y -= speed.y;

	SetLocation(NewLocation);
}

/*率直な弾丸：描画に関することを実行する*/
void EnemyBulletsStraight::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

/*率直な弾丸：画面外処理*/
bool EnemyBulletsStraight::ScreenOut()
{
	bool ret = (GetLocation().y + GetRadius() <= 0); /*0より小さいとき・円が全部画面外の時*/

	return ret;
}