#include "SpherCollider.h"
#include"math.h"

/*�R���X�g���N�^*/
SpherCollider::SpherCollider(T_Location location, float radius) {

	this->location x = location x; //������₷���悤�ɓ������̓��m
	this->location y = location y;

	this->radius = radius;

}

/*SphereCollider�^���m�̓����蔻��*/
bool SpherCollider::HitSphere(const SpherCollider* collider) const { //SphereColl���� ��������}���邽��(4byt)�|�C���^���g�� const�ň�����ύX���Ȃ�

	/*��������A����ւ̃x�N�g�����v�Z����*/
	/*�v�Z�ŏo�����x�N�g���̑傫���ƁA�����Ƒ���̔��a�̍��v���x�N�g���̑傫������������΁A�������Ă���*/
	
	/*�����Ƒ���Ƃ̊Ԃ̃x�N�g�����v�Z*/
	float vectorX = fabsf(this->location.x = collider->GetLocaation().x); //���� ���� ����
	float vectorY = fabsf(this->location.y = collider->GetLocaation().y;) //���� ���� ����

	/*�x�N�g���̑傫�����v�Z*/
}

/*���S���W�̎擾*/
T_Location SpherCollider::GetLocaation() const { //���S���W�̎擾

	return location;

}

/*���S���W�̐ݒ�*/
void SpherCollider::SetLocation(T_Location location) { //���S���W�̐ݒ�

	this->location x = location x; //������₷���悤�ɓ������̓��m
	this->location y = location y;

}

/*���a�̎擾*/
float SpherCollider::GetRadius() const { //���a�̎擾

	return radius;

}
