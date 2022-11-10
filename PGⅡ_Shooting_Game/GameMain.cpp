#include"GameMain.h"
#include"RecoveryItem.h"

/*�`��ȊO�̍X�V�����s����*/
//AbstractScene* GameMainScene::Update() {
//
//
//	return this;
//}

/*�`��Ɋւ��邱�Ƃ����s����*/
//void GameMainScene::Draw() const {
//
//	
//}

/*�`��Ɋւ��邱�Ƃ����s����*/
//void GameMainScene::Draw() const {
//
//	mScene->Draw();
//}
//

/*�V�[���̕ύX����*/
//AbstractScene* GameMainScene::ChangeScene() {
//
//	//�V�[���̕ύX�����Ăяo��
//	AbstractScene* NextScene = mScene->ChangeScene();
//
//	//���̃V�[�������݃V�[���ƕʂȂ猻�s
//	if (NextScene != mScene)
//	{
//		delete mScene;
//
//		mScene = NextScene;
//	}
//
//	return NextScene;
//}

/*�Q�[�����C���F�`��ȊO�̍X�V�����s����*/
void GameMainScene::Update() {

	/************** �����蔻��E�e�X�g **************/
	/*T_Location location = T_Location{ 100,100 };

	Player test = Player(location);

	test.Draw();

	if (test.HitSphere(player))
	{
		return;
	}*/
	/************************************************/

	player->Update();

	int EnemyCount;

	/*���[�v�̂��߂̕ϐ�*/
	int BulletCount;

	/*�A�C�e��Update����*/
	for (int i = 0; i < 10; i++)
	{
		if (item[i] == nullptr)
		{
			break;
		}
		item[i]->Update();
	}

	BulletsBase** bullet = player->GetBullets();
	for (EnemyCount = 0; EnemyCount < 10; EnemyCount++) /*�G��10�̂ɑ�����܂�*/
	{
		if (enemy[EnemyCount] == nullptr)
		{
			break;
		}

		/*�G�l�~�[�̍X�V*/
		enemy[EnemyCount]->Update();

		/*for (int i = 0; i < 10; i++)
		{
			if (item[i] == nullptr)
			{
				break;
			}

			item[i]->Update();
		}*/

		for (BulletCount = 0; BulletCount < 30; BulletCount++) /*�e30��*/
		{
			if (bullet[BulletCount] == nullptr)
			{
				break;
			}

			/*�����蔻��*/
			if (enemy[EnemyCount]->HitSphere(bullet[BulletCount])) /*�G�l�~�[�Ƀv���C���[�̒e���q�b�g���Ă���*/
			{

				/*�G�l�~�[�Ƀ_���[�W��^����*/
				enemy[EnemyCount]->Hit(bullet[BulletCount]->GetDamege());/*�F�X�ƌĂяo���Ă���*/

				/*�e���폜*/
				player->DeleteBullet(BulletCount);
				BulletCount--;

				/*�G�l�~�[��HP��0�ȉ���������A�G�l�~�[���폜*/
				if (enemy[EnemyCount]->HpCheck())
				{
					for (int i = 0; i < 10; i++)
					{
						if (item[i] == nullptr) /*�G����A�C�e��*/
						{
							item[i] = new RecoveryItem(enemy[EnemyCount]->GetLocation());
							break;
						}
					}

					/*�X�R�A���Z*/
					player->AddScore(enemy[EnemyCount]->GetPoint());
					
					/*�G�l�~�[�̍폜*/
					//player->DeleteBullet(EnemyCount);
					//EnemyCount--;

					/*�G�l�~�[�̍폜*/
					delete enemy[EnemyCount]; /*�G������(�f���[�g)*/
					enemy[EnemyCount] = nullptr; /*NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/

					/*�z���O�ɋl�߂�E++ */
					//for (int i = EnemyCount; i < 30 - 1; i++) /*28�܂Ń��[�v*/
					//{
					//	if (enemy[i + 1] == nullptr)
					//	{
					//		break;
					//	}
					//	enemy[i] = enemy[i + 1]; /*����O��*//*���[�v*/
					//	enemy[i + 1] = nullptr; /*����NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/
					//}
					//
					//EnemyCount--;

					/*�z���O�ɋl�߂�E-- */
					for (int i = EnemyCount + 1; i < 10; i++) /*2����n�܂���29�ŏI���*/
					{
						if (enemy[i] == nullptr)
						{
							break;
						}
						enemy[i - 1] = enemy[i]; /*����O��*//*���[�v*/
						enemy[i] = nullptr; /*����NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/
					}

					EnemyCount--;  /*EnemyCount��0�ɂ���*/
					break;        /*for���𔲂���*/
				}
			}
		}
	}
		for (int ItemCount = 0; ItemCount < 10; ItemCount++)
		{
			if (item[ItemCount] == nullptr)
			{
				break;
			}
			if (item[ItemCount]->HitSphere(player))
			{
				/*�G�l�~�[�̍폜*/
				delete item[ItemCount]; /*�G������(�f���[�g)*/
				item[ItemCount] = nullptr; /*NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/

				/*�z���O�ɋl�߂�E-- */
				for (int i = ItemCount + 1; i < 10; i++) /*2����n�܂���29�ŏI���*/
				{
					if (item[i] == nullptr)
					{
						break;
					}
					item[i - 1] = item[i]; /*����O��*//*���[�v*/
					item[i] = nullptr; /*����NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/
				}

				ItemCount--;  /*EnemyCount��0�ɂ���*/
			}
		}
}

/*�Q�[�����C���F�`��Ɋւ��邱�Ƃ����s����*/
void GameMainScene::Draw() const {

	player->Draw();

	for (int EnemyCount = 0; EnemyCount < 10; EnemyCount++) /*�G��10�̂ɑ�����܂�*/
	{
		if (enemy[EnemyCount] == nullptr)
		{
			break;
		}

		enemy[EnemyCount]->Draw();
	}

	/*�A�C�e��Draw����*/
	for (int i = 0; i < 10; i++)
	{
		if (item[i] == nullptr)
		{
			break;
		}
		item[i]->Draw();
	}
}

/*�Q�[�����C���F�V�[���̕ύX����*/
AbstractScene* GameMainScene::ChangeScene() {

	return this;
}

/***********************************************
 * �Q�[�����C��
 ***********************************************/
GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,100 };/*�v���C���[�̏o���ʒu*/

	player = new Player(location);

	enemy = new Enemy * [10];

	for (int i = 0; i < 10; i++) /*�G�̏�����*/
	{
		enemy[i] = nullptr; /*nullpointer�ŏ�����*/
	}

	/*�A�C�e��������*/
	/*new�ŗ̈�m��*/
	enemy[0] = new Enemy(T_Location{200,0}); /*�G����̂������*/

	item = new ItemBase * [10];

	for (int i = 0; i < 10; i++)
	{
		item[i] = nullptr; /*������*/
	}
}
