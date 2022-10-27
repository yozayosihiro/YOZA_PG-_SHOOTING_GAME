#include "Enemy.h"
#include"DxLib.h"

Enemy::Enemy(T_Location location) : CharaBase(location, T_Location{ 0,0.5 }, 20.f), hp(10), point(10)
{

}

/*描画以外の更新を実行する*/
void Enemy::Update()
{
	/*LocationをLocationに移動させる処理*/
	T_Location NewLocation = GetLocation();

	NewLocation.y += 0.5;
	SetLocation(NewLocation);
}

/*描画に関することを実行する*/
void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));
}

void Enemy::Hit()
{

}

bool Enemy::HpCheck()
{
	/*HP = 0 かどうか?*/
	bool ret = (hp <= 0); 

		return ret;
}

int Enemy::GetPoint()
{
	return point; /*メンバ変数のポイントを返す*/
}