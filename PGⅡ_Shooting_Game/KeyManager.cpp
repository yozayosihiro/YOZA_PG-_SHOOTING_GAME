#include "KeyManager.h"
#include"DxLib.h"

/*�L�[������*/
 char KeyManager::OldKey[256];
 char KeyManager::NowKey[256];

 /*�}�E�X������*/
 int KeyManager::OldMouse;
 int KeyManager::NowMouse;

/*�`��ȊO�̍X�V�����s����*/
void KeyManager::Update()
{
	for (int i = 0; i < 256; i++)
	{
		OldKey[i] = NowKey[i];
	}

	if (GetHitKeyStateAll(NowKey) == -1)
	{
		throw - 1;
	}

	OldMouse = NowMouse;

	NowMouse = GetMouseInput();
}

/*******************************�L�[���͏���*******************************************/
/*�L�[�{�^���������Ă邩�����ĂȂ���*/
bool KeyManager::OnKeyClicked(int Key)
{
	/*NowKey���������OldKey��������ĂȂ��Ƃ�*/
	bool ret = (NowKey[Key] == 1) && (OldKey[Key] != 1); /*���t���[��������ĂȂ���*/
	return ret;
}

/*�L�[�{�^���𗣂����u�ԁE���͉�����ĂȂ����ǑO�͉�����Ă�*/
bool KeyManager::OnKeyReleased(int Key)
{
	bool ret = (NowKey[Key] != 1) && (OldKey[Key] == 1);/*�{�^���𗣂����u��*/
	return ret;
}

/*�L�[�{�^���������Ă���ԁE�L�[�{�^���������ꑱ���Ă���*/
bool KeyManager::OnKeyPressed(int Key)
{
	bool ret = (NowKey[Key] == 1);/*�{�^���������ꑱ���Ă���*/
	return ret;
}
/*******************************�L�[���͏���*******************************************/

/******************************�}�E�X���͏���******************************************/
/*�}�E�X�N���b�N���Ă邩�����ĂȂ���*/
bool KeyManager::OnMouseClicked(int Key)
{
	bool ret = ((NowMouse & Key) && (OldMouse & Key));
	return ret;
}

/*�}�E�X�N���b�N�{�^���𗣂����u�ԁE���͉�����ĂȂ����ǑO�͉�����Ă�*/
 bool KeyManager::OnMouseReleased(int Key)
{
	 bool ret = ((NowMouse & Key != 1) && (OldMouse & Key == 1));
	 return ret;
}

 /*�}�E�X�N���b�N���Ă���ԁE�}�E�X�N���b�N�{�^���������ꑱ���Ă���*/
 bool KeyManager::OnMousePressed(int Key)
 {
	 bool ret = ((NowMouse & Key == 1));
	 return ret;
 }
 /******************************�}�E�X���͏���******************************************/