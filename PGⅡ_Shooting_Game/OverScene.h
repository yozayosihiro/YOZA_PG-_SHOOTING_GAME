#pragma once
#include "AbstractScene.h"

class OverScene : public AbstractScene
{
	/*�Q�[�����C���F�`��ȊO�̍X�V�����s����*/
	virtual void Update();

	/*�Q�[�����C���F�Q�[�����C���F�`��Ɋւ��邱�Ƃ���������*/
	virtual void Draw() const;

	/*�Q�[�����C���F�V�[���̕ύX����*/
	virtual AbstractScene* ChangeScene();
};

