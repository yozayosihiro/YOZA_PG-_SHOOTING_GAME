#pragma once
#include"Common.h"


class SpherCollider
{
private: /*変数設定*/

	T_Location location; //Location(中心座標)
	
	float radius;  //半径

public: /*const設定*/

	SpherCollider(T_Location location, float radius);

public: /*関数設定*/

	 bool HitSphere(const SpherCollider* collider) const; //SphereColl引数 メモリを抑えるため(4byt)ポインタを使う constで引数を変更しない

	 /*中心座標の取得*/
	T_Location GetLocation() const; //中心座標の取得

	/*中心座標の設定*/
	void SetLocation(T_Location location); //中心座標の設定

	/*半径の取得*/
	float GetRadius() const; //半径の取得
};

