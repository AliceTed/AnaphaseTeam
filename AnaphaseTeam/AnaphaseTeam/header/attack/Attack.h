#pragma once
/**
* @file ContinuationCombo.h
* @brief 連続コンボ用単発攻撃
* @author 松尾裕也
* @date 2016/8/26
*/
#include "../data/ANIMATION_ID.h"
#include "AttackStatus.h"
#include "../../header/shape/Shape.h"
#include <memory>
#include "ECombo.h"
#include "IAttack.h"
class TestActor;
class Player;
class CollisionMediator;
class AnimatorOne;

class Attack :public IAttack
{
public:
	Attack(const AttackStatus& _status, ANIMATION_ID _animation, Combo _Qnext, Combo _Snext);
	~Attack();
	void initialize(Player * _player);
	void update(float deltaTime, Player* _player);
	void motion(Player* _player);
	
	void changeMotion(AnimatorOne& _animator, float _speed);
	const bool isNextAttack(const AnimatorOne& _animator)const;
	const bool isEndMotion(const AnimatorOne& _animator) const;
	const Combo weakAttackNext() const;
	const Combo strengthAttackNext() const;
private:
	//!攻撃ステータス
	AttackStatus m_status;
	//!アニメーション
	ANIMATION_ID m_Animation;
	//!次の攻撃
	Combo m_nextQCombo;
	Combo m_nexySCombo;
};