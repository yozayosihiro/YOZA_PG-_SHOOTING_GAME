#include"DxLib.h"
#include<stdio.h>
#include"Common.h"
#include"AbstractScene.h"
#include"SceneManager.h"
#include"GameMain.h"
#include"KeyManager.h"
#include"TitleScene.h"

/***********************************************
 * �ϐ��̐錾
 ***********************************************/
int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���

GAME_STATE	g_GameState = GAME_STATE::GAME_TITLE; // �Q�[���X�e�[�^�X

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	/* �^�C�g��*/
	SetMainWindowText("SHOOTING GAME");

	ChangeWindowMode(TRUE);		       // �E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);       // ��ʂ�傫������
	if (DxLib_Init() == -1) return -1; // DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	/*AbstractScene�^�ɖ߂��āA�V�[���}�l�[�W���[�I�u�W�F�N�g�̍쐬*/
	SceneManager SceneMng(dynamic_cast<AbstractScene*>(new TitleScene()));

	// �Q�[�����[�v
	while (ProcessMessage() == 0) {
	//while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT) {
	//

			/* ���̓L�[�擾 */
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		// ��ʂ̏�����

		/*�L�[���͏����m�F�e�X�g*/
		//KeyManager::Update();
		//if(KeyManager::OnPressed(KEY_INPUT_A)) /*�����ꂽ�Ƃ�*/
			//if (KeyManager::OnClicked(KEY_INPUT_A)) /*�����ꂽ�u��*/
				//if (KeyManager::OnReleased(KEY_INPUT_A)) /*�������u��*/
		//{
		//	DrawFormatString(200, 200, 0xffffff, "AAA");
		//}

		/*�}�E�X���͏����m�F�e�X�g*/
		//KeyManager::Update();
		//if(KeyManager::OnMousePressed(MOUSE_INPUT_LEFT)) /*�����ꂽ�Ƃ�*/
			//if (KeyManager::OnMouseClicked(MOUSE_INPUT_LEFT)) /*�����ꂽ�u��*/
				//if (KeyManager::OnMouseReleased(MOUSE_INPUT_LEFT)) /*�������u��*/
		//{
		//	DrawFormatString(200, 200, 0xffffff, "AAA");
		//}

		/*switch����*/
		//switch (g_GameState) {
		//	case GAME_STATE::GAME_TITLE:
		//		DrawGameTitle();	   //�Q�[���^�C�g������
		//		break;
		//	case GAME_STATE::GAME_INIT:
		//	 	GameInit();		       //�Q�[����������
		//		break;
		//	case GAME_STATE::DRAW_RANKING:
		//		DrawRanking();	       //�����L���O�`�揈��
		//		break;
		//	case GAME_STATE::DRAW_END:
		//		DrawEnd();		      //�G���h��ʕ`�揈��
		//		break;
		//	case GAME_STATE::GAME_MAIN:
		//		GameMain();		      //�Q�[�����C������
		//		break;
		//	case GAME_STATE::DRAW_GAME_OVER:
		//		DrawGameOver();       //�Q�[���I�[�o�[�`�揈��
		//		break;
		//	case GAME_STATE::DRAW_GAME_CLEAR:
		//		DrawGameClear();      //�Q�[���N���A�`�揈��
		//		break;
		//	case GAME_STATE::INPUT_RANKING:
		//		InputRanking();       //�����L���O���͏���
		//		break;
		//}

		/*�V�[���}�l�[�W���[����*/
	    //	if (SceneMng.Update() != nullptr)
	//	{
    //
	//		SceneMng.Update();
	//		SceneMng.Draw();
    //
	//		if (SceneMng.ChangeScene() == nullptr)
	//		{
    //
	//			DxLib::DxLib_End();	// DX���C�u�����g�p�̏I������
    //
	//			return 0;	// �\�t�g�̏I��
	//		}
	//	}
	//	else
	//	{
	//		break;
	//	}
    //
	//	ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
    //
	//}
    //
	//DxLib::DxLib_End();	// DX���C�u�����g�p�̏I������
    //
	//return 0;	// �\�t�g�̏I��

		SceneMng.Update(); //�V�[���̍X�V����
		SceneMng.Draw();   //�V�[���̕`�揈��
		KeyManager::Update(); //�}�E�X�E�L�[���͍X�V����

		/*�V�[���}�l�[�W���[�E�V�[���̕ύX����*/
		if (SceneMng.ChangeScene() == nullptr)
		{

			DxLib::DxLib_End();	// DX���C�u�����g�p�̏I������

			return 0;	// �\�t�g�̏I��
		}

		ScreenFlip();  // ����ʂ̓��e��\��ʂɔ��f

	}
		
	DxLib::DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��

}