#include "CharaBase.h"
                                    /*�������q���X�g*/
CharaBase::CharaBase(T_Location location, T_Location speed, float radius) : SpherCollider(location, radius), speed(speed), image(nullptr)
{

}