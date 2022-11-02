#pragma once
#include"SpherCollider.h"

/*�e�ۂ̃x�[�X*/
class BulletsBase : public SpherCollider
{
private:

	int damage; //�_���[�W

protected:

	T_Location speed; //�X�s�[�h

public: /*�R���X�g���N�^*/

	BulletsBase(T_Location location, T_Location speed, float radius, int damage);

public:

	/*�`��ȊO�̍X�V�����s����*/
	virtual void Update() = 0;

	/*�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() = 0;

	/*��ʊO����*/
	virtual bool ScreenOut() = 0;

	int GetDamege();
};

