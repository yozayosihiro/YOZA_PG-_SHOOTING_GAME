#pragma once
#include"AbstractScene.h"
#include"Player.h"
#include"Enemy.h"

/*�Q�[�����C���N���X*/
class GameMainScene : public AbstractScene {

private:

/*�m�ۂ��Ă锠�������̂ňꉞ*/
	Player* player; /*�v���C���[*/

	Enemy** enemy; /*�G*/
	 
public:

	/*�Q�[�����C���F�R���X�g���N�^*/
	GameMainScene();

	/*�Q�[�����C���F�f�X�g���N�^*/
	virtual ~GameMainScene() {};

public:

	/*�Q�[�����C���F�`��ȊO�̍X�V�����s����*/
	virtual void Update()  override;
	//virtual void Draw() const = 0;
	//virtual AbstractScene* Update() override;
	
	/*�Q�[�����C���F�Q�[�����C���F�`��Ɋւ��邱�Ƃ���������*/
	virtual void Draw() const override;

	/*�Q�[�����C���F�V�[���̕ύX����*/
	virtual AbstractScene* ChangeScene() override;
	//virtual AbstractScene* ChangeScene() = 0;
	//
};
