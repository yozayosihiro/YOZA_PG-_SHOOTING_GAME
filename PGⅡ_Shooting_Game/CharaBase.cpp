#include "CharaBase.h"
                                                                 /*キャラクター・初期化子リスト*/
CharaBase::CharaBase(T_Location location, T_Location speed, float radius) : SpherCollider(location, radius), speed(speed), image(nullptr), bullets(nullptr)
{

}

BulletsBase** CharaBase::GetBullets()
{
    return bullets;
}