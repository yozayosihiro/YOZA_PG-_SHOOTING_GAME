#pragma once
#include"Common.h"


class SpherCollider
{
private: /*�ϐ��ݒ�*/

	T_Location location; //Location(���S���W)
	
	float radius;  //���a

public: /*const�ݒ�*/

	SpherCollider(T_Location location, float radius);

public: /*�֐��ݒ�*/

	 bool HitSphere(const SpherCollider* collider) const; //SphereColl���� ��������}���邽��(4byt)�|�C���^���g�� const�ň�����ύX���Ȃ�

	 /*���S���W�̎擾*/
	T_Location GetLocation() const; //���S���W�̎擾

	/*���S���W�̐ݒ�*/
	void SetLocation(T_Location location); //���S���W�̐ݒ�

	/*���a�̎擾*/
	float GetRadius() const; //���a�̎擾
};

