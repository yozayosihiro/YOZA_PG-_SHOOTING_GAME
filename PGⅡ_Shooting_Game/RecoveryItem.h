#pragma once
#include "ItemBase.h"

class RecoveryItem : public ItemBase
{
private:

	int volume_item; /*�񕜃A�C�e����*/

protected:

public:

public:

	/*�񕜃A�C�e���F�`��ȊO�̍X�V�����s����*/
	virtual void Update() override;

	/*�񕜃A�C�e���F�`��Ɋւ��邱�Ƃ����s����*/
	virtual void Draw() override;

	/*�A�C�e���F�񕜗�*/
	int GetVolumeItem();

};

