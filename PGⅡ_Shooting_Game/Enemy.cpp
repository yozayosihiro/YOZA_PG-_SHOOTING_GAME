#include "Enemy.h"
#include"DxLib.h"
#include"BulletsStraight.h"
#include"EnemyBulletsStraight.h"
#include "KeyManager.h"
#include"BulletsRotation.h"

/*�G�F�ړ��E�����̏��*/
struct MoveInformation 
{
	T_Location TargetLocation; 

	int pattern;       /*���@�E�p�^�[��*/

	int attackPattern; /*�U�����@*/

	int next;          /*����(�z��)����*/

	int waitTimeFlame; /*(�҂��Ȃ�)����*/

	/*int attackPattern; /*�U�����@*/
};

MoveInformation MoveInfo[10] =
{
	//{640,150,0,1,0,0} ,  /*{X���W,Y���W,�p�^�[��,�U�����@,����(�z��)����,(�҂��Ȃ�)����}*/
	//{1200.4,150,0,2,0,0},
	//{0,0,1,3,180,0},
	//{80.2,150,0,4,0,2},
	//{0,0,1,5,180,1},
	//{1200.4,150,0,2,0,1},

	{640,150,0,0,1,0} ,  /*{X���W,Y���W,�p�^�[��,�U�����@,����(�z��)����,(�҂��Ȃ�)����}*/
	{1200.4,150,0,0,2,0},
	{0,0,1,0,3,180},
	{80.2,150,0,2,4,0},
	{0,0,1,1,5,180},
	{1200.4,150,0,1,2,0},
};

//T_Location loopLocations[4] = /*�J��Ԃ��ړ��p�̍��W*/
//{
//	{640,150},	  /*�ړ�1*/
//	{1200.4,150}, /*�ړ�2*/
//	{80.2,150}    /*�ړ�3*/
//}; 

/*�ʕ��@*/
T_Location loopLocations[3] = /*�J��Ԃ��ړ��p�̍��W*/
{
	{640,150},	  /*�ړ�1*/
	{1200.4,150}, /*�ړ�2*/
	{80.2,150},   /*�ړ�3*/
};

int Next[3] = /*�ړ��ԍ�*/
{
	1, /*�ړ�1*/
	2, /*�ړ�2*/
	3, /*�ړ�3*/
};

int current = 0; /*�����p�ԍ��̕ϐ�*/
                                                          /*speed   X,Y */                  /*   ��   ��   ��   */
Enemy::Enemy(T_Location location) : CharaBase(location, T_Location{ 2,2 }, 20.f), hp(10), point(10), shotNum(0),locationNum(0)
{
	/*BulletsBase** bullets*//*2�d�z��*/
	bullets = new BulletsBase * [30]; /*�����ɏo����e�̐� 30*/

	/*2�d�z��̏�����*/
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

/*�G�F�ړ�����*/
void Enemy::Move()
{
	T_Location NextLocation = GetLocation(); /*�G�̍��W�E���̍��W�����̍��W�ɓ����*/

	if ((NextLocation.y == loopLocations[current].y) && (NextLocation.x == loopLocations[current].x)) /*�������W�ɂ����玟��*/
	{
		current = Next[current];
	}
	else /*�ړI�n�ɂ��Ȃ������Ƃ���*/
	{
		/*�c�̈ړ�����*/
		if (NextLocation.y != loopLocations[current].y) /*Y���W*/
		{
			if (NextLocation.y < loopLocations[current].y)
			{
				NextLocation.y += speed.y; /*���ړ�*/

				if ((GetLocation().y <= loopLocations[current].y) && (loopLocations[current].y <= NextLocation.y)) /*((����Y���W <= �ړI�n) && �ړI�n <= ����Y���W))*/
				{
					NextLocation.y = loopLocations[current].y; /*�ړI�n���ђ������Ƃ�*/
				}
			}
			else
			{
				NextLocation.y -= speed.y; /*��ړ�*/

				if ((NextLocation.y <= loopLocations[current].y) && (loopLocations[current].y <= GetLocation().y)) /*((����Y���W <= �ړI�n) && (�ړI�n <= ����Y���W))*/
				{
					NextLocation.y = loopLocations[current].y;
				}
			}
		}
	}
	/*���̈ړ�����*/
	if (NextLocation.x != loopLocations[current].x) /*X���W*/
	{
		if (NextLocation.x < loopLocations[current].x)
		{
			NextLocation.x += speed.x; /*�E�ړ�*/

			if ((GetLocation().x <= loopLocations[current].x) && (loopLocations[current].x <= NextLocation.x)) /*((����X���W <= �ړI�n) && �ړI�n <= ����X���W))*/
			{
				NextLocation.x = loopLocations[current].x; /*�ړI�n���ђ������Ƃ�*/
			}
		}
		else
		{
			NextLocation.x -= speed.x; /*���ړ�*/

			if ((NextLocation.x <= loopLocations[current].x) && (loopLocations[current].x <= GetLocation().x)) /*((����X���W <= �ړI�n) && (�ړI�n <= ����X���W))*/
			{
				NextLocation.x = loopLocations[current].x; /*�ړI�n���ђ������Ƃ�*/
			}
		}
	}
	SetLocation(NextLocation); /*�G�̈ړ������̃Z�b�g*/
}

/*�G�F�ړ�����*/
//void Enemy::Move()
//{
//	 /*�G�̈ړ� Location��Location�Ɉړ������鏈��*/
//	T_Location NewLocation = GetLocation();
//
//	/*�G�̈ړ�����*/
//	if (NewLocation.x != loopLocations[locationNum].x) /*�G��X���W�ƖڕW��X���W���Ⴉ������*/
//	{
//		if (NewLocation.x < loopLocations[locationNum].x)  /*�G��X���W���ڕW��X���W���傫�������� X���W�̉E�ړ�*/
//		{
//			speed.x = 1;  /*X���W�̉E�ړ� �X�s�[�hX�ňړ�*/
//		}
//		if (NewLocation.x > loopLocations[locationNum].x) /*�G��X���W���ڕW��X���W�������������� X���W�̍��ړ�*/
//		{
//			speed.x = -1; /*X���W�̍��ړ� �X�s�[�hX�ňړ�*/
//		}
//
//		NewLocation.x += speed.x; /*�G�l�~�[�̓X�s�[�hX�̒l���݂Ĉړ�*/
//	}
//	/*�G��X���W�ƖڕW��X���W����v�����Ƃ�*/
//	else if (NewLocation.y != loopLocations[locationNum].y) /*�G��Y���W�ƖڕW��Y���W���Ⴉ������*/
//	{
//		speed.x = 0; /*X���W�̈ړ������Ȃ��悤��*/
//
//		if (NewLocation.y < loopLocations[locationNum].y) /*�G��Y���W���ڕW��Y���W���傫�������� Y���W�̏�ړ�*/
//		{
//			speed.y = 1;  /*Y���W�̏�ړ� �X�s�[�hY�ňړ�*/
//		}
//		if (NewLocation.y > loopLocations[locationNum].y) /*�G��Y���W���ڕW��Y���W�������������� Y���W�̉��ړ�*/
//		{
//			speed.y = -1; /*Y���W�̉��ړ� �X�s�[�hY�ňړ�*/
//		}
//
//		NewLocation.y += speed.y; /*�G�l�~�[�̓X�s�[�hY�̒l���݂Ĉړ�*/
//	}
//	/*�G��XY���W�ƖڕW��XY���W����v�����Ƃ�*/
//	else
//	{
//		speed.y = 0;   /*Y���W�̈ړ������Ȃ��悤��*/
//
//		locationNum++; /*���̈ړ��p�̍��W��*/
//	}
//
//	/*�ړ��p�̍��W�����[�v����*/
//	if (locationNum > 3)
//	{
//		locationNum = 2;
//	}
//
//	//NewLocation.x += speed.x; /*�G�l�~�[�̓X�s�[�hX�̒l���݂Ĉړ�*/
//	//NewLocation.y += speed.y; /*�G�l�~�[�̓X�s�[�hY�̒l���݂Ĉړ�*/
//
//	SetLocation(NewLocation); /*�G�̈ړ������̃Z�b�g*/
//******************************************************************
//}

/*�G�F�`��ȊO�̍X�V�����s����*/
void Enemy::Update()
{
	int BulleCount;

	/*�G�F�ړ�����*/
	Move();

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
			/*�e���쐬*/                                /*�ʒu*/  /*speed*/ /*���ˊp�x*/
			bullets[BulleCount] = new BulletsRotation(GetLocation(), 2.f, (20 * shotNum));

			shotNum++; /*�����Ă���*/

			                                                   /*BulletsStraight�̈���*/
			/*bullets[BulleCount] = new BulletsStraight(GetLocation(),T_Location {0,-4}); /*BulletsStraight���쐬*/
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