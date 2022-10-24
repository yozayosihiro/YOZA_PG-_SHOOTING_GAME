#include "DxLib.h"
#include "Player.h"
#include"BulletsStraight.h"
#include"KeyManager.h"

Player::Player(T_Location location) : CharaBase(location, T_Location{ 2,2 }, 10.f), score(0), life(10)
{
	/*BulletsBase** bullets*//*2�d�z��*/
	bullets = new BulletsBase * [30]; /*�����ɏo����e�̐� 30*/

	/*2�d�z��̏�����*/
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

/*�`��ȊO�̍X�V�����s����*/
void Player::Update()
{
	/*Location��Location�Ɉړ������鏈��*/
	T_Location NewLocation = GetLocation();

	NewLocation.x += 1;
	SetLocation(NewLocation);

	int BulleCount;

	for (BulleCount = 0; BulleCount < 30; BulleCount++) /*���˃J�E���g*/
	{
		if (bullets[BulleCount] == nullptr)
		{
			break;
		}

		bullets[BulleCount]->Update();
	}

	if (KeyManager::OnMouseClicked(MOUSE_INPUT_LEFT)) /*�}�E�X���N���b�N*/
	{
		if (BulleCount < 30 && bullets[BulleCount] == nullptr) /*���˃J�E���g*/
		{
			bullets[BulleCount] = new BulletsStraight(GetLocation()); /*BulletsStraight���쐬*/
		}
	}
}

/*�`��Ɋւ��邱�Ƃ����s����*/
void Player::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));

	/*�e�ۂ̕`��*/
	for (int BulleCount = 0; BulleCount < 30; BulleCount++)
	{
		if (bullets[BulleCount] == nullptr)
		{
			break;
		}

		bullets[BulleCount]->Draw();
	}
}

void Player::Hit()
{

}

bool Player::LifeCheck()
{
	/*HP = 0 ���ǂ���?*/
	bool ret = (life <= 0);

	return ret;
}

int Player::GetScore()
{
	return score;
}
