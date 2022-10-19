#include<stdio.h>
#include"AbstractScene.h"
#include"SceneManager.h"

/*�`��ȊO�̍X�V�����s����*/
//AbstractScene* SceneManager::Update() {

/*�����o�ϐ��̒l������������̂������o*/
void SceneManager :: Update() {

	  mScene->Update();

}

/*�`��Ɋւ��邱�Ƃ����s����*/
void SceneManager::Draw() const {

	mScene->Draw();
}

/*�V�[���̕ύX����*/
AbstractScene* SceneManager::ChangeScene() {

	//�V�[���̕ύX�����Ăяo��
	AbstractScene* NextScene = mScene->ChangeScene();

	//���̃V�[�������݃V�[���ƕʂȂ猻�s
	if (NextScene != mScene)
	{
		delete mScene;

		mScene = NextScene;
	}

	return NextScene;
}