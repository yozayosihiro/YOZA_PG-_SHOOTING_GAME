#include "TitleScene.h"
#include"GameMain.h"
#include"DxLib.h"
#include"KeyManager.h"

/*�Q�[�����C���F�`��ȊO�̍X�V�����s����*/
void TitleScene::Update()
{
	
 }

/*�Q�[�����C���F�Q�[�����C���F�`��Ɋւ��邱�Ƃ���������*/
void TitleScene::Draw() const
{
	
 }

/*�Q�[�����C���F�V�[���̕ύX����*/
AbstractScene * TitleScene::ChangeScene() 
{
	if (KeyManager::OnKeyClicked(KEY_INPUT_A)) /*�{�^����������*/
	{
		return dynamic_cast<AbstractScene*>(new GameMainScene()); /*AbstractScene�^�ɖ߂��āAnew��GameMainScene()���쐬*/
	}
	return this; /*�X�V�Ȃ�*/
}