#include "Enemy.h"
#include"DxLib.h"

Enemy::Enemy(T_Location location) : CharaBase(location, T_Location{ 0,0.5 }, 20.f), hp(10), point(10)
{

}

/*�`��ȊO�̍X�V�����s����*/
void Enemy::Update()
{
	/*Location��Location�Ɉړ������鏈��*/
	T_Location NewLocation = GetLocation();

	NewLocation.y += 0.5;
	SetLocation(NewLocation);
}

/*�`��Ɋւ��邱�Ƃ����s����*/
void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));
}

void Enemy::Hit()
{

}

bool Enemy::HpCheck()
{
	/*HP = 0 ���ǂ���?*/
	bool ret = (hp <= 0); 

		return ret;
}

int Enemy::GetPoint()
{
	return point; /*�����o�ϐ��̃|�C���g��Ԃ�*/
}