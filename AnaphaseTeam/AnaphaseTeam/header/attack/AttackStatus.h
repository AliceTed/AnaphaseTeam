#pragma once
/**
* @file AttackStatus.h
* @brief 攻撃のパラメータ
* @author 松尾裕也
* @date 2016/8/26
*/
#include <gslib.h>
class TestActor;
class Player;
class AttackStatus
{
public:
	AttackStatus(float _attackPower,float _distanceDecay,const GSvector3& _blowOffPower);
	~AttackStatus();

	//威力と吹っ飛びを渡す
	void giveDamage(Player* _player,TestActor* _other);
private:
	//!攻撃力
	float m_Power;
	//!距離減衰
	float m_DistanceDecay;
	//!吹っ飛び値(取りあえずベクター3で実装)
	GSvector3 m_BlowOff;
};

