#include "Enemy.h"
#include"DxLib.h"
#include"BulletsStraight.h"
#include"EnemyBulletsStraight.h"
#include "KeyManager.h"
#include"BulletsRotation.h"

///*�G�F�ړ��E�����̏��*/
//struct MoveInformation 
//{
//	int pattern;               /*���@�E�p�^�[��*/
//
//	T_Location TargetLocation; /*�ړI�n*/
//
//	int next;                  /*����(�z��)����*/
//
//	int waitTimeFlame;         /*(�҂��Ȃ�)����*/
//
//	int attackPattern;         /*�U�����@*/
//};

/*�G�F�ړ�, �ړI�n, NEXT, �҂�����, �U�����@�̔z��*/
//MoveInformation MoveInfo[10] =
//{
////{���@,    �ړI�n,   NEXT,  �҂�����,  �U�����@};
//	{0,     640, 150,    1,         0,         0}, 
//	{0,  1200.4, 150,    2,         0,         2}, 
//	{1,       0,   0,    3,       300,         1}, 
//	{0,    80.2, 150,    4,         0,         2}, 
//	{1,       0,   0,    1,       300,         1}
//
//	//{640,150,0,0,1,0} ,  //{X���W,Y���W,�p�^�[��,�U�����@,����(�z��)����,(�҂��Ȃ�)����}
//	//{1200.4,150,0,0,2,0},
//	//{0,0,1,0,3,180},
//	//{80.2,150,0,2,4,0},
//	//{0,0,1,1,5,180},
//	//{1200.4,150,0,1,2,0},
//};

//struct ENEMY_MOVE
//{
//	int pattern;       /*���@�E�p�^�[��*/
//
//	int waitTimeFlame; /*(�҂��Ȃ�)����*/
//
//	T_Location TargetLocation;
//
//	int next;          /*����(�z��)����*/
//
//	//int attackPattern; /*�U�����@*/
//};
//
//ENEMY_MOVE MovePattern[6] = 
//{
//	{0, 0, 640.f, }
//	{}
//	{}
//	{}
//	{}
//	{}
//}

//T_Location loopLocations[4] = /*�J��Ԃ��ړ��p�̍��W*/
//{
//	{640,150},	  /*�ړ�1*/
//	{1200.4,150}, /*�ړ�2*/
//	{80.2,150}    /*�ړ�3*/
//}; 

/*�ʕ��@*/
//T_Location loopLocations[3] = /*�J��Ԃ��ړ��p�̍��W*/
//{
//	//{640,150},	  /*�ړ�1*/
//	//{1200.4,150}, /*�ړ�2*/
//	//{80.2,150},   /*�ړ�3*/
//};

/*�ړ��ԍ�*/
//int Next[3] = 
//{
//	//1, /*�ړ�1*/
//	//2, /*�ړ�2*/
//	//3, /*�ړ�3*/
//};

//int current = 0; /*�����p�ԍ��̕ϐ�*/
//int waitCount = 0; /*��؎���*/

/*�G�F�ړ������E�U���̕��@�A�p�^�[���̃t�@�C���ǂݍ���*/
void Enemy::InputCSV()
{
	FILE* fp; /*FILE�^�\����*/

	errno_t error; /*fopen_s�̃G���[�m�F*/

	error = fopen_s(&fp, "CSV/csv.csv", "r");

	/*(�u���C�N�|�C���g��t����)�t�@�C���̊J�e�X�g*/
	if (error != 0)
	{
		return; //�G���[����
	}
	else //�t�@�C�����J����
	{
		char line[100]; //�s

		/*fgets(line, ������, fp)*/
		//fgets(line, 100, fp); 
		//

		for (int i = 0; fgets(line, 100, fp) != NULL; i++) {
			//while (fgets(line[100], 100, fp) != NULL) //�w��̕�����������Ă���
			//{
				sscanf_s(
						  line, //�s

					"%d, %f, %f, %d, %d, %d",       //(int, float, float, int, int, int)

					& MoveInfo[i].pattern,          /*���@�E�p�^�[��*/

					& MoveInfo[i].TargetLocation.x, /*�ړI�n.X���W*/

					& MoveInfo[i].TargetLocation.y, /*�ړI�n.Y���W*/

					& MoveInfo[i].next,             /*����(�z��)����*/

					& MoveInfo[i].waitTimeFlame,    /*(�҂��Ȃ�)����*/

					& MoveInfo[i].attackPattern     /*�U�����@*/
				 );
			//}
			//	
		}
		return;
	}
	fclose(fp); /*�t�@�C�������*/
}
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
	InputCSV();
}

/*�G�F�ړ�����*/
void Enemy::Move()
{
	T_Location NextLocation = GetLocation(); /*�G�̍��W�E���̍��W�����̍��W�ɓ����*/

	if ((NextLocation.y == MoveInfo[current].TargetLocation.y) && (NextLocation.x == MoveInfo[current].TargetLocation.x)) /*�������W�ɂ����玟��*/
	{
		current = MoveInfo[current].next;
	}
	else /*�ړI�n�ɂ��Ȃ������Ƃ���*/
	{
		/*�c�̈ړ�����*/
		if (NextLocation.y != MoveInfo[current].TargetLocation.y) /*Y���W*/
		{
			if (NextLocation.y < MoveInfo[current].TargetLocation.y)
			{
				NextLocation.y += speed.y; /*���ړ�*/

				if ((GetLocation().y <= MoveInfo[current].TargetLocation.y) && (MoveInfo[current].TargetLocation.y <= NextLocation.y)) /*((����Y���W <= �ړI�n) && �ړI�n <= ����Y���W))*/
				{
					NextLocation.y = MoveInfo[current].TargetLocation.y; /*�ړI�n���ђ������Ƃ�*/
				}
			}
			else
			{
				NextLocation.y -= speed.y; /*��ړ�*/

				if ((NextLocation.y <= MoveInfo[current].TargetLocation.y) && (MoveInfo[current].TargetLocation.y <= GetLocation().y)) /*((����Y���W <= �ړI�n) && (�ړI�n <= ����Y���W))*/
				{
					NextLocation.y = MoveInfo[current].TargetLocation.y;
				}
			}
		}
	}
	/*���̈ړ�����*/
	if (NextLocation.x != MoveInfo[current].TargetLocation.x) /*X���W*/
	{
		if (NextLocation.x < MoveInfo[current].TargetLocation.x)
		{
			NextLocation.x += speed.x; /*�E�ړ�*/

			if ((GetLocation().x <= MoveInfo[current].TargetLocation.x) && (MoveInfo[current].TargetLocation.x <= NextLocation.x)) /*((����X���W <= �ړI�n) && �ړI�n <= ����X���W))*/
			{
				NextLocation.x = MoveInfo[current].TargetLocation.x; /*�ړI�n���ђ������Ƃ�*/
			}
		}
		else
		{
			NextLocation.x -= speed.x; /*���ړ�*/

			if ((NextLocation.x <= MoveInfo[current].TargetLocation.x) && (MoveInfo[current].TargetLocation.x <= GetLocation().x)) /*((����X���W <= �ړI�n) && (�ړI�n <= ����X���W))*/
			{
				NextLocation.x = MoveInfo[current].TargetLocation.x; /*�ړI�n���ђ������Ƃ�*/
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
	/*�G�F�ړ��E�U���̏����p�^�[��*/
	switch (MoveInfo[current].pattern)
	{
	case 0:
		Move(); /*�G�F�ړ�����*/
		break;

	case 1:
		waitCount++; /*��؎���++*/

  /*(�G�̏������[�����p�ԍ�].(�҂��Ȃ�)���� <= ��؎���)*/
		if (MoveInfo[current].waitTimeFlame <= waitCount) 
		{
			waitCount = 0; /*��؎��� = 0*/

			current = MoveInfo[current].next; /*�����p�ԍ� = �G�������[�����p�ԍ�].NEXT(����)*/
		}
		break;

	default:
		break;
	}

	int bulletCount; /*���˃J�E���g*/

	for (bulletCount = 0; bulletCount < 30; bulletCount++) /*���˃J�E���g*/
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}

		bullets[bulletCount]->Update(); /*�e�̃A�b�v�f�[�g*/

		/*��ʊO�ɍs������e������*/
		if (bullets[bulletCount]->ScreenOut())
		{
			/*�e�ۂ̏���*/
			//delete bullets[BulleCount]; /*�e������(�f���[�g)*/
			//bullets[BulleCount] = nullptr; /*NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/

			DeleteBullet(bulletCount);
			bulletCount--;

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
	//if (1) /*������*/
	//{
	//	if (bulletCount < 30 && bullets[bulletCount] == nullptr) /*���˃J�E���g*/
	//	{
	//		/*�e���쐬*/                                /*�ʒu*/  /*speed*/ /*���ˊp�x*/
	//		bullets[bulletCount] = new BulletsRotation(GetLocation(), 2.f, (20 * shotNum));
	//
	//		shotNum++; /*�����Ă���*/
	//
	//		                                                   /*BulletsStraight�̈���*/
	//		/*bullets[BulleCount] = new BulletsStraight(GetLocation(),T_Location {0,-4}); /*BulletsStraight���쐬*/
	//		//bullets[BulleCount] = new EnemyBulletsStraight(GetLocation()); /*����BulletsStraight���쐬*/
	//		//
	//	}
	//}

   /*(�G�̏������[�����p�ԍ�].�U�����@ != 0)*/
	if (MoveInfo[current].attackPattern != 0) { 
		if (bulletCount < 30 && bullets[bulletCount] == nullptr) /*���˃J�E���g*/
		{
	       /*(�G�̏������[�����p�ԍ�].�U�����@ == 1)*/
			if (MoveInfo[current].attackPattern == 1) 
			{
				bullets[bulletCount] = new BulletsStraight(GetLocation(), T_Location{ 0, -2 }); /*��������*/
			}
		   /*(�G�̏������[�����p�ԍ�].�U�����@ == 2)*/
			if (MoveInfo[current].attackPattern == 2) 
			{
				shotNum++;

				bullets[bulletCount] = new BulletsRotation(GetLocation(), 4.f, (20 * shotNum)); /*��]���e�۔���*/
			}
		}
	}
}

/*�G�F�`��Ɋւ��邱�Ƃ����s����*/
void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

	/*�e�ۂ̕`��*/
	for (int BulletCount = 0; BulletCount < 30; BulletCount++)
	{
		if (bullets[BulletCount] == nullptr)
		{
			break;
		}
		bullets[BulletCount]->Draw();
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