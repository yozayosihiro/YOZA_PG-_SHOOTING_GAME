#pragma once

class KeyManager
{
private: /*exturn�֎~�̏ꍇ*/

	/*�L�[����*/
	static char OldKey[256];
	static char NowKey[256];

	/*�}�E�X����*/
	static int OldMouse;
	static int NowMouse;

private:
	/*�R���X�g���N�^�ɃA�N�Z�X�֎~*/
	KeyManager() = default; 

public:

	//�`��ȊO�̍X�V�����s����
	static void Update();

	/*�L�[���͏���*/
	static bool OnKeyClicked(int Key);
	static bool OnKeyReleased(int Key);
	static bool OnKeyPressed(int Key);

	/*�}�E�X���͏���*/
	static bool OnMouseClicked(int Key);
	static bool OnMouseReleased(int Key);
	static bool OnMousePressed(int Key);
};

