#include"GameMain.h"
#include"RecoveryItem.h"
#include"OverScene.h"

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
	//enemy[0] = new Enemy(T_Location{200,0}); /*�G����̂������*/
	//

	enemy[0] = new Enemy(T_Location{ 1280 / 2,0 }); /*�^�񒆂ɐ���  �G����̂������*/
	enemy[1] = new Enemy(T_Location{ 1280 / 4,0 }); /*�^�񒆂ɐ���  �G,��̖�*/

	item = new ItemBase * [10];

	for (int i = 0; i < 10; i++)
	{
		item[i] = nullptr; /*������*/
	}
}

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

	   /*�G�̒e�ƃv���C���[�̓����蔻��@����*/
	   /*�G�̒e������Ă���
	   for(�e�����[�v�ŎQ��)
	   {
			if(�G�̒e�ƃv���C���[�̓����蔻��)
			{
				 �v���C���[�Ƀ_���[�W��^����

				 �G�̒e���폜����
			}
	   }*/

		/*�G�̒e������Ă��� ����*/
		//BulletsBase** EnemyBullet = enemy[EnemyCount]->GetBullets();

		/*�e�����[�v�ŎQ�� ����*/
		//for (int BulletCount = 0; BulletCount < 30; BulletCount++) /*�e30��*/
		//{
		//	if (EnemyBullet[BulletCount] == nullptr)
		//	{
		//		break;
		//	}
		//	 /*�G�̒e�ƃv���C���[�̓����蔻��*/
		//	if (player->HitSphere(EnemyBullet[BulletCount])) /*�G�l�~�[�Ƀv���C���[�̒e���q�b�g���Ă���*/
		//	{
		//		/*�v���C���[�Ƀ_���[�W��^����*/
		//		player->Hit(EnemyBullet[BulletCount]->GetDamege());/*�F�X�ƌĂяo���Ă���*/
		//
		//		/*�G�̒e���폜����*/
		//		enemy[EnemyCount]->DeleteBullet(BulletCount);
		//
		//		BulletCount--;
		//
		//		/*�v���C���[�̍폜*/
		//		//delete player; /*�G������(�f���[�g)*/
		//	}
		//}

		for (int i = 0; i < 10; i++)
		{
			if (item[i] == nullptr)
			{
				break;
			}
			item[i]->Update();
		}

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
	   /*�G�̒e�ƃv���C���[�̓����蔻�� ����(���{)*/
	   /*�G�̒e������Ă���
	   for(�e�����[�v�ŎQ��)
	   {
			if(�G�̒e�ƃv���C���[�̓����蔻��)
			{
				 �v���C���[�Ƀ_���[�W��^����

				 �G�̒e���폜����
			}
	   }*/

	    /*�e�����[�v�ŎQ�� ����(���{)*/
		for (EnemyCount = 0; EnemyCount < 30; EnemyCount++) /*�e30��*/
		{
			if (enemy[EnemyCount] == nullptr)
			{
				break;
			}
			bullet = enemy[EnemyCount]->GetBullets();

			for (int i = 0; i < 30; i++)
			{
				if (bullet[i] == nullptr)

					break;

				if (player->HitSphere(bullet[i]))
				{
					player->Hit(bullet[i]->GetDamege());

					enemy[EnemyCount]->DeleteBullet(i);

					i--; //������񌩂�
				}
			}
		}
	
		/*�A�C�e���̍폜����*/
		for (int ItemCount = 0; ItemCount < 10; ItemCount++)
		{
			if (item[ItemCount] == nullptr)
			{
				break;
			}
			/*�A�C�e���̍폜����*/
			if (item[ItemCount]->HitSphere(player)) /*�A�C�e���ƃv���C���[�̓����蔻��*/
			{
				/*�񕜏���*/
				player->Hit(item[ItemCount]);

				/*�A�C�e���̍폜*/
				delete item[ItemCount]; /*�A�C�e��������(�f���[�g)*/
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

				ItemCount--;  /*ItemCount��0�ɂ���*/
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
AbstractScene* GameMainScene::ChangeScene() 
{
	if (player->LifeCheck()) //�v���C���[��HP��0��������
	{
		return dynamic_cast<AbstractScene*>(new OverScene()); /*AbstractScene�^�ɖ߂��āAnew��OverScene()���쐬*/
	}
	return this;
}
