#pragma once
/**
* @file ContinuationCombo.h
* @brief 連続コンボ用単発攻撃
* @author 松尾裕也
* @date 2016/8/26
*/
#include "../data/ANIMATION_ID.h"
#include "AttackStatus.h"
#include "ATTACK_TYPE.h"
class Player;
class CollisionMediator;
class AnimatorOne;

class Attack
{
public:
	Attack(const AttackStatus& _status, ANIMATION_ID _animation, ATTACK_TYPE _nextQuick, ATTACK_TYPE _nextSlow);
	~Attack();
	void initialize(Player * _player);
	void motion(Player* _player);
	void changeMotion(AnimatorOne& _animator, float _speed);
	const ATTACK_TYPE next(bool _isSlow) const;
private:
	//!攻撃ステータス
	AttackStatus m_status;
	//!アニメーション
	ANIMATION_ID m_Animation;
	//!次の攻撃
	ATTACK_TYPE m_nextQuick;
	ATTACK_TYPE m_nextSlow;
};