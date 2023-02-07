#pragma once
#include "AbstractScene.h"

//�V�[���}�l�[�W���[�N���X
//�e�V�[���̐؂�ւ����Ǘ�����
class SceneManager : public AbstractScene {

private:

	AbstractScene* mScene; //���݂̃V�[��

public:

	//�R���X�g���N�^
	SceneManager(AbstractScene* scene) : mScene(scene) {}

	//�f�X�g���N�^
	~SceneManager() {

		delete mScene; //�V�[���̍폜
	}

	//�`��ȊO�̍X�V����������
	 void Update() override;
	//AbstractScene* Update() override;
	//

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const override;

	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;
};