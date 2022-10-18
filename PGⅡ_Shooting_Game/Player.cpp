#include "DxLib.h"
#include "Player.h"

Player::Player(T_Location location) : CharaBase(location, T_Location{ 2,2 }, 10.f), score(0), life(10)
{

}

void Player::Update()
{
	/*Location‚ğLocation‚ÉˆÚ“®‚³‚¹‚éˆ—*/
	T_Location NewLocation = GetLocaation();

	NewLocation.x += 1;
	SetLocation(NewLocation);
}

void Player::Draw()
{
	DrawCircle(GetLocaation().x, GetLocaation().y, GetRadius(), GetColor(255, 0, 0));
}

void Player::Hit()
{

}

bool Player::LifeCheck()
{
	/*HP = 0 ‚©‚Ç‚¤‚©?*/
	bool ret = (life <= 0);

	return ret;
}

int Player::GetScore()
{
	return score;
}
