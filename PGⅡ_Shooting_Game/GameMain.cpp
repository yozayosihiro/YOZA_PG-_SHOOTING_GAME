#include"GameMain.h"

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

/*�`��ȊO�̍X�V�����s����*/
void GameMainScene::Update() {

	player->Update();
}

/*�`��Ɋւ��邱�Ƃ����s����*/
void GameMainScene::Draw() const {

	player->Draw();
}

/*�V�[���̕ύX����*/
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
}
