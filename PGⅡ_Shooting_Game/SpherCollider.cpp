#include "SpherCollider.h"
#include"math.h"

/*�R���X�g���N�^*/
SpherCollider::SpherCollider(T_Location location, float radius) {

	this->location = location; /*������₷���悤�ɓ������̓��m*/
	//this->location x = location x;
	//this->location y = location y;

	this->radius = radius;
}

/*SphereCollider�^���m�̓����蔻��*/
bool SpherCollider::HitSphere(const SpherCollider* collider) const { //SphereColl���� ��������}���邽��(4byt)�|�C���^���g�� const�ň�����ύX���Ȃ�

	/*��������A����ւ̃x�N�g�����v�Z����*/
	/*�v�Z�ŏo�����x�N�g���̑傫���ƁA�����Ƒ���̔��a�̍��v���x�N�g���̑傫������������΁A�������Ă���*/

	/*��������A����ւ̃x�N�g�����v�Z����*/
	         /*floot�^�̐�Βl*/       /*�����Ƒ���Ƃ̊Ԃ̃x�N�g�����v�Z*/
	float vectorX = fabsf(this->location.x - collider->GetLocation().x); //�����̃x�N�g�� ���� ����̃x�N�g��
	float vectorY = fabsf(this->location.y - collider->GetLocation().y); //�����̃x�N�g�� ���� ����̃x�N�g��

	/*�x�N�g���̑傫�����v�Z*/ 
	float  VectorLength = (vectorX * vectorX) + (vectorY * vectorY); /*��x2�� + y2��*/

	             /*floot�^*/
	VectorLength = sqrtf(VectorLength); /*����O������*/

	/*�v�Z�ŏo�����x�N�g���̑傫���ƁA�����Ƒ���̔��a�̍��v���x�N�g���̑傫������������΁A�������Ă���*/
	/*�����Ƒ���̔��a�̍��v�l���v�Z*/
	float SumRadius = radius + collider->GetRadius();

	/*�����蔻��̌��ʂ��i�[*/
	bool ret = VectorLength < SumRadius; /*bool ret = VectorLength <= SumRadius;*/

	return ret;
}

/*���S���W�̎擾*/
T_Location SpherCollider::GetLocation() const { //���S���W�̎擾

	return location;
}

/*���S���W�̐ݒ�*/
void SpherCollider::SetLocation(T_Location location) { //���S���W�̐ݒ�

	this->location = location; /*������₷���悤�ɓ������̓��m*/
	//this->location x = location x;
	//this->location y = location y;
}

/*���a�̎擾*/
float SpherCollider::GetRadius() const { //���a�̎擾

	return radius;
}
