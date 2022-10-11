#include"DxLib.h"
#include<stdio.h>
#include"Common.h"
#include"AbstractScene.h"
#include"SceneManager.h"
#include"GameMain.h"

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

	/* �^�C�g���� test �ɕύX */
	SetMainWindowText("SHOOTING GAME");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	/*�^�C�g���摜�f�[�^�̓ǂݍ���*/
	//if ((g_TitleImage = LoadGraph("images/Title.png")) == -1) return -1;
	/*�����L���O�摜�f�[�^�̓ǂݍ���*/
	//if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;
	/*�G���h�摜�f�[�^�̓ǂݍ���*/
	//if ((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;
	/*�u���b�N�摜�f�[�^�̓ǂݍ���*/
	//if (LoadDivGraph("images/Block.bmp", 8, 8, 1, 40, 8, g_BlockImage) == -1) return -1;

	/*�����L���O�f�[�^�̓ǂݍ���*/
	//if (ranking.ReadRanking() == -1)  return  -1;    

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	/*�V�[���}�l�[�W���[�I�u�W�F�N�g�̍쐬*/
	SceneManager SceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));

	// �Q�[�����[�v
	while (ProcessMessage() == 0) {
	//while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT) {
	//

			/* ���̓L�[�擾 */
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		// ��ʂ̏�����

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