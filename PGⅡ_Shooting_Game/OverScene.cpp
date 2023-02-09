#include "OverScene.h"

#include"TitleScene.h"
#include"DxLib.h"
#include"KeyManager.h"

/*�Q�[�����C���F�`��ȊO�̍X�V�����s����*/
void OverScene::Update()
{

}

/*�Q�[�����C���F�Q�[�����C���F�`��Ɋւ��邱�Ƃ���������*/
void OverScene::Draw() const
{
	DrawString(0, 100, "A�L�[�Ń^�C�g��", 0xfffffff);

	SetFontSize(30);
	DrawString(300, 300, "�Q�[���I�[�o�[", 0xfffffff);
}

/*�Q�[�����C���F�V�[���̕ύX����*/
AbstractScene* OverScene::ChangeScene()
{
	if (KeyManager::OnKeyClicked(KEY_INPUT_A)) /*�{�^����������*/
	{
		return dynamic_cast<AbstractScene*>(new TitleScene()); /*AbstractScene�^�ɖ߂��āAnew��GameMainScene()���쐬*/
	}
	return this; /*�X�V�Ȃ�*/
}