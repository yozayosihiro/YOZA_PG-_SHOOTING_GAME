#pragma once
#include"AbstractScene.h"

/*�Q�[�����C���N���X*/
class GameMainScene : public AbstractScene {

public:

	//�f�X�g���N�^
	virtual ~GameMainScene() {};

	//�`��ȊO�̍X�V�����s����
	virtual void Update()  override;
	//virtual void Draw() const = 0;
	//virtual AbstractScene* Update() override;
	

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;
	//virtual AbstractScene* ChangeScene() = 0;
	//

	GameMainScene();
};
