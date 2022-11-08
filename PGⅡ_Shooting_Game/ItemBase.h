#pragma once
#include"SpherCollider.h"
#include"enum_ItemType.h"

class ItemBase : public SpherCollider
{
private:

	enum_ItemType type;

protected:

	T_Location speed;

public:

public:

	/*�A�C�e���F�`��ȊO�̍X�V�����s����*/
	virtual void Update() = 0;

	/*�A�C�e���F�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() = 0;

	/*�A�C�e���̃^�C�v�����Fenum_ItemType��Ԃ�����*/
	enum_ItemType GetType();
};

