#include "CharaBase.h"
                                                                 /*キャラクター・初期化子リスト*/
CharaBase::CharaBase(T_Location location, T_Location speed, float radius) : SpherCollider(location, radius), speed(speed), image(nullptr), bullets(nullptr)
{

}

BulletsBase** CharaBase::GetBullets()
{
    return bullets;
}

/*弾の削除処理*/
void CharaBase::DeleteBullet(int BulletNum)
{
	delete bullets[BulletNum]; /*弾を消す(デリート)*/
	bullets[BulletNum] = nullptr; /*NULL POINTER(ヌル・ポインター)で上書き*/

	/*配列を前に詰める・++ */
	//for (int i = BulletNum; i < 30 - 1; i++) /*28までループ*/
	//{
	//	if (bullets[i + 1] == nullptr)
	//	{
	//		break;
	//	}
	//	bullets[i] = bullets[i + 1]; /*後ろを前に*//*ループ*/
	//	bullets[i + 1] = nullptr; /*後ろをNULL POINTER(ヌル・ポインター)で上書き*/
	//}
	//
	//BulleCount--;

	/*配列を前に詰める・-- */
	for (int i = BulletNum + 1; i < 30; i++) /*2から始まって29で終わる*/
	{
		if (bullets[i] == nullptr)
		{
			break;
		}
		bullets[i - 1] = bullets[i]; /*後ろを前に*//*ループ*/
		bullets[i] = nullptr; /*後ろをNULL POINTER(ヌル・ポインター)で上書き*/
	}
}