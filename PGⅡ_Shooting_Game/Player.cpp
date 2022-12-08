#include "DxLib.h"
#include "Player.h"
#include"BulletsStraight.h"
#include"KeyManager.h"
#include"RecoveryItem.h"

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

/*�v���C���[�F�`��ȊO�̍X�V�����s����*/
void Player::Update()
{
	/*�v���C���[�̈ړ� Location��Location�Ɉړ������鏈��*/
	T_Location NewLocation = GetLocation();

	/*�v���C���[�̈ړ�����*/
	if (KeyManager::OnKeyPressed(KEY_INPUT_W)) /*��ړ�*/
	{
		NewLocation.y -= speed.y;
	}
	if (KeyManager::OnKeyPressed(KEY_INPUT_A)) /*���ړ�*/
	{
		NewLocation.x -= speed.x;
	}
	if (KeyManager::OnKeyPressed(KEY_INPUT_S)) /*���ړ�*/
	{
		NewLocation.y += speed.y;
	}
	if (KeyManager::OnKeyPressed(KEY_INPUT_D)) /*�E�ړ�*/
	{
		NewLocation.x += speed.x;
	}

	SetLocation(NewLocation); /*�v���C���[�̈ړ������̃Z�b�g*/

	int BulleCount;

	for (BulleCount = 0; BulleCount < 30; BulleCount++) /*���˃J�E���g*/
	{
		if (bullets[BulleCount] == nullptr)
		{
			break;
		}

		bullets[BulleCount]->Update(); /*�e�̃A�b�v�f�[�g*/

		/*��ʊO�ɍs������e������*/
		if (bullets[BulleCount]->ScreenOut())
		{
			/*�e�ۂ̏���*/
			//delete bullets[BulleCount]; /*�e������(�f���[�g)*/
			//bullets[BulleCount] = nullptr; /*NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/

			DeleteBullet(BulleCount);
			BulleCount--;

			/*�z���O�ɋl�߂�E++ */
			//for (int i = BulleCount; i < 30 - 1; i++) /*28�܂Ń��[�v*/
			//{
			//	if (bullets[i + 1] == nullptr)
			//	{
			//		break;
			//	}
			//	bullets[i] = bullets[i + 1]; /*����O��*//*���[�v*/
			//	bullets[i + 1] = nullptr; /*����NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/
			//}
			//
			//BulleCount--;

			/*�z���O�ɋl�߂�E-- */
			//for (int i = BulleCount + 1; i < 30; i++) /*2����n�܂���29�ŏI���*/
			//{
			//	if (bullets[i] == nullptr)
			//	{
			//		break;
			//	}
			//	bullets[i - 1] = bullets[i]; /*����O��*//*���[�v*/
			//	bullets[i] = nullptr; /*����NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/
			//}

		    /*�z���O�ɋl�߂�E�������i*/
		    /*�z���O�ɋl�߂�*/
		    //for (BulleCount = 0; BulleCount < 30; BulleCount++)
      //{
		//if (BulleCount != 29) { /*�e�J�E���g���Ōザ��Ȃ�������*/
		//
		//	bullets[BulleCount] = bullets[BulleCount + 1]; /*���̒e*/
		//}
		//else 
		//{
		//	bullets[BulleCount] = nullptr; /*�Ōゾ������nullpointer�ŏ㏑��*/
		//
		//}
	  //}
		}
	}

	/*�v���C���[�F�e�ۂ̔���*/
	if (KeyManager::OnMousePressed(MOUSE_INPUT_LEFT)) /*�}�E�X���N���b�N*/
	{
		if (BulleCount < 30 && bullets[BulleCount] == nullptr) /*���˃J�E���g*/
		{
			bullets[BulleCount] = new BulletsStraight(GetLocation(), T_Location{0,2}); /*BulletsStraight���쐬*/
		}
	}
}

/*�v���C���[�F�`��Ɋւ��邱�Ƃ����s����*/
void Player::Draw()
{
/************************************************************************************************/
#define _DEBUG_MODE_PLAYE /*�f�o�b�N���[�h*/

#ifdef _DEBUG_MODE_PLAYE /*�f�o�b�N���[�h*/

	DrawFormatString(10, 10, GetColor(255, 255, 255), "life = %d",life); /*�v���C���[��HP�\��*/

#endif // DEBUG /*�f�o�b�N���[�h*/
/************************************************************************************************/

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

/*�v���C���[�F�U�������蔻�菈��*/
void Player::Hit(int damage)
{
	if (0 <= damage) /*�N���X�ň����n����Ă邩�ǂ���*/
	{
		life -= damage; /*�v���C���[��HP�����炷*/

		if (life <= 0) /*HP��0�̎�*/
		{
			life = 0;
		}
	}
}

/*�v���C���[�F�A�C�e���ւ̓��e����*/
void Player::Hit(class ItemBase* item)
{
	switch (item->GetType())
	{
	case enum_ItemType::HEAL:
	{
		RecoveryItem* recoveryitem = dynamic_cast<RecoveryItem*>(item); /*Dynamic�L���X�g����*/

		life += recoveryitem->GetVolumeItem(); /*�v���C���[��HP�Ƀv���X�ɂ���*/
		break;
	}/*�ϐ��̎�����ۂ���{}��t����*/

	default:
		break;
	}
}

/*�v���C���[�FHP����*/
bool Player::LifeCheck()
{
	/*HP = 0 ���ǂ���?*/
	bool ret = (life <= 0);

	return ret;
}

/*�v���C���[�F�X�R�A��Ԃ�*/
int Player::GetScore()
{
	return score;
}

/*�v���C���[�F�X�R�A���Z*/
void Player::AddScore(int score)
{
	if (0 <= score) /*�X�R�A��0��艺�ɂȂ�Ȃ��悤��*/
	{
		this->score += score;
	}
}
