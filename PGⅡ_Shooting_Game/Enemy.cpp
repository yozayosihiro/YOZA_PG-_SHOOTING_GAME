#include "Enemy.h"
#include"DxLib.h"
#include"BulletsStraight.h"
#include"EnemyBulletsStraight.h"
#include "KeyManager.h"

Enemy::Enemy(T_Location location) : CharaBase(location, T_Location{ 0,0.5 }, 20.f), hp(10), point(10)
{
	/*BulletsBase** bullets*//*2�d�z��*/
	bullets = new BulletsBase * [30]; /*�����ɏo����e�̐� 30*/

	/*2�d�z��̏�����*/
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

/*�G�F�`��ȊO�̍X�V�����s����*/
void Enemy::Update()
{
	/*Location��Location�Ɉړ������鏈��*/
	T_Location NewLocation = GetLocation();

	NewLocation.y += speed.y; /*�G�l�~�[�̓X�s�[�h�̒l���݂Ĉړ�*/
	SetLocation(NewLocation);

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

	/*�G�F�e�ۂ̔���*/
	if (1) /*������*/
	{
		if (BulleCount < 30 && bullets[BulleCount] == nullptr) /*���˃J�E���g*/
		{
			                                                   /*BulletsStraight�̈���*/
			bullets[BulleCount] = new BulletsStraight(GetLocation(),T_Location {0,-4}); /*BulletsStraight���쐬*/
			//bullets[BulleCount] = new EnemyBulletsStraight(GetLocation()); /*����BulletsStraight���쐬*/
			//
		}
	}
}

/*�G�F�`��Ɋւ��邱�Ƃ����s����*/
void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

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

/*�G�F�����蔻�菈��*/
void Enemy::Hit(int damage)
{
	if (0 < damage) /*�N���X�ň����n����Ă邩�ǂ���*/
	{
		hp -= damage; /*�G�l�~�[��HP�����炷*/

		if (hp < 0) /*HP��0�̎�*/
		{
			hp = 0;
		}
	}
}

/*�G�FHP���菈��*/
bool Enemy::HpCheck()
{
	/*HP = 0 ���ǂ���?*/
	bool ret = (hp <= 0); 

		return ret;
}

/*�G�F�|�C���^�擾����*/
int Enemy::GetPoint()
{
	return point; /*�����o�ϐ��̃|�C���g��Ԃ�*/
}

/*�G�l�~�[�̍폜����*/
//void DeleteEnemy(int EnemyNum)
//{
//	
//}