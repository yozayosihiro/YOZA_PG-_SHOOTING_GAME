//#include "MouseManager.h"
//#include <DxLib.h>
//
///*�}�E�X������*/
//int MouseManager::OldMouse;
//int MouseManager::NowMouse;
//
///*�`��ȊO�̍X�V�����s����*/
//void MouseManager::Update()
//{
//	for (int i = 0; i < 256; i++)
//	{
//		OldMouse[i] = NowMouse[i];
//	}
//
//	if (GetHitKeyStateAll(NowMouse) == -1)
//	{
//		throw - 1;
//	}
//
//	OldMouse = NowMouse;
//
//	NowMouse = GetMouseInput();
//}
//
//
///******************************�}�E�X���͏���******************************************/
///*�}�E�X�N���b�N���Ă邩�����ĂȂ���*/
//bool MouseManager::OnMouseClicked(int Key)
//{
//	bool ret = ((NowMouse & Key) && (OldMouse & Key));
//	return ret;
//}
//
///*�}�E�X�N���b�N�{�^���𗣂����u�ԁE���͉�����ĂȂ����ǑO�͉�����Ă�*/
//bool MouseManager::OnMouseReleased(int Key)
//{
//	bool ret = ((NowMouse & Key != 1) && (OldMouse & Key == 1));
//	return ret;
//}
//
///*�}�E�X�N���b�N���Ă���ԁE�}�E�X�N���b�N�{�^���������ꑱ���Ă���*/
//bool MouseManager::OnMousePressed(int Key)
//{
//	bool ret = ((NowMouse & Key == 1));
//	return ret;
//}
///******************************�}�E�X���͏���******************************************/