#pragma once
#include"AbstractScene.h"
#include"Player.h"

/*�Q�[�����C���N���X*/
class GameMainScene : public AbstractScene {

private:

/*�m�ۂ��Ă锠�������̂ňꉞ*/
	Player* player; 

public:

	/*�R���X�g���N�^*/
	GameMainScene();

	//�f�X�g���N�^
	virtual ~GameMainScene() {};

public:

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
};
