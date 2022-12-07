#pragma once
#include"SpherCollider.h"
#include"enum_ItemType.h"

class ItemBase : public SpherCollider
{
private:

	/*�A�C�e���F���*/
	enum_ItemType type;

protected:

	/*�A�C�e���F�X�s�[�h*/
	T_Location speed;

public: /*�A�C�e���F�R���X�g���N�^*/

	/*�A�C�e���F�R���X�g���N�^(T_Location �ʒu, float ���a, enum�A�C�e��, T_Location �X�s�[�h)*/
	ItemBase(T_Location location, float radius, enum_ItemType type, T_Location speed);

public:

	/*�A�C�e���F�`��ȊO�̍X�V�����s����*/
	virtual void Update() = 0;

	/*�A�C�e���F�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() = 0;

	/*�A�C�e���̃^�C�v�����Fenum_ItemType��Ԃ�����*/
	enum_ItemType GetType();
};

