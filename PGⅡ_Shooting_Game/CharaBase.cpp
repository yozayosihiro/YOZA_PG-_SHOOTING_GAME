#include "CharaBase.h"
                                                                 /*�L�����N�^�[�E�������q���X�g*/
CharaBase::CharaBase(T_Location location, T_Location speed, float radius) : SpherCollider(location, radius), speed(speed), image(nullptr), bullets(nullptr)
{

}

BulletsBase** CharaBase::GetBullets()
{
    return bullets;
}

/*�e�̍폜����*/
void CharaBase::DeleteBullet(int BulletNum)
{
	delete bullets[BulletNum]; /*�e������(�f���[�g)*/
	bullets[BulletNum] = nullptr; /*NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/

	/*�z���O�ɋl�߂�E++ */
	//for (int i = BulletNum; i < 30 - 1; i++) /*28�܂Ń��[�v*/
	//{
	//	if (bullets[i + 1] == nullptr)
	//	{
	//		break;
	//	}
	//	bullets[i] = bullets[i + 1]; /*����O��*//*���[�v*/
	//	bullets[i + 1] = nullptr; /*����NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/
	//}
	//
	//BulleCount--;

	/*�z���O�ɋl�߂�E-- */
	for (int i = BulletNum + 1; i < 30; i++) /*2����n�܂���29�ŏI���*/
	{
		if (bullets[i] == nullptr)
		{
			break;
		}
		bullets[i - 1] = bullets[i]; /*����O��*//*���[�v*/
		bullets[i] = nullptr; /*����NULL POINTER(�k���E�|�C���^�[)�ŏ㏑��*/
	}
}