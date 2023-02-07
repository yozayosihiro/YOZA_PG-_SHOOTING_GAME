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

	//���̃V�[�������݃V�[���ƕʂȂ�ڍs
	if (NextScene != mScene)
	{
		delete mScene;      //�O�̃V�[�����폜

		mScene = NextScene; //���̃V�[���ɕύX
	}

	return NextScene;       //�V�����V�[��
}