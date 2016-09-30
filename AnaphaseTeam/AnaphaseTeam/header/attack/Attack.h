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
typedef std::shared_ptr<Shape> Shape_Ptr;

class TestActor;
class Player;
class CollisionMediator;
class AnimatorOne;
class Attack
{
public:
	Attack(const AttackStatus& _status, ANIMATION_ID _animation, Shape_Ptr _shape);
	~Attack();
	void initialize();
	void update(float deltaTime,Player* _player);
	void motion(Player* _player);
	
	void changeMotion(AnimatorOne& _animator);
	const bool isNextAttack(const AnimatorOne& _animator)const;
	const bool isEndMotion(const AnimatorOne& _animator) const;
	//bool isEndAttackTime(AnimatorOne * _animator);
private:
	//!攻撃ステータス
	AttackStatus m_status;
	//!アニメーション
	ANIMATION_ID m_Animation;

	//判定用形状
	Shape_Ptr m_Shape;
};