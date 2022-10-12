#include "SpherCollider.h"
#include"math.h"

/*コンストラクタ*/
SpherCollider::SpherCollider(T_Location location, float radius) {

	this->location x = location x; //分かりやすいように同じもの同士
	this->location y = location y;

	this->radius = radius;

}

/*SphereCollider型同士の当たり判定*/
bool SpherCollider::HitSphere(const SpherCollider* collider) const { //SphereColl引数 メモリを抑えるため(4byt)ポインタを使う constで引数を変更しない

	/*自分から、相手へのベクトルを計算する*/
	/*計算で出したベクトルの大きさと、自分と相手の半径の合計よりベクトルの大きさが小さければ、当たっている*/
	
	/*自分と相手との間のベクトルを計算*/
	float vectorX = fabsf(this->location.x = collider->GetLocaation().x); //自分 引く 相手
	float vectorY = fabsf(this->location.y = collider->GetLocaation().y;) //自分 引く 相手

	/*ベクトルの大きさを計算*/
}

/*中心座標の取得*/
T_Location SpherCollider::GetLocaation() const { //中心座標の取得

	return location;

}

/*中心座標の設定*/
void SpherCollider::SetLocation(T_Location location) { //中心座標の設定

	this->location x = location x; //分かりやすいように同じもの同士
	this->location y = location y;

}

/*半径の取得*/
float SpherCollider::GetRadius() const { //半径の取得

	return radius;

}
