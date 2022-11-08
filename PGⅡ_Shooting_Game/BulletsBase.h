#pragma once
#include"SpherCollider.h"

/*�e�ۂ̃x�[�X*/
class BulletsBase : public SpherCollider
{
private:

	int damage; /*�e�ہF�_���[�W*/

protected:

	T_Location speed; /*�e�ہF�X�s�[�h*/

public: /*�e�ہF�R���X�g���N�^*/

	BulletsBase(T_Location location, T_Location speed, float radius, int damage);

public:

	/*�e�ہF�`��ȊO�̍X�V�����s����*/
	virtual void Update() = 0;

	/*�e�ہF�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() = 0;

	/*�e�ہF��ʊO����*/
	virtual bool ScreenOut() = 0;

	/*�e�ہF�_���[�W����*/
	int GetDamege();
};

