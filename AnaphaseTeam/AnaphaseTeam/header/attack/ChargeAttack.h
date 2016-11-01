#pragma once

#include "../data/ANIMATION_ID.h"
#include "AttackStatus.h"
#include "../../header/shape/Shape.h"
#include <memory>
#include"ECombo.h"
#include "IAttack.h"
class IComboMadiator;
class Player;
class CollisionMediator;
class AnimatorOne;
typedef std::shared_ptr<Shape> Shape_Ptr;

class ChargeAttack:IAttack
{
public:
	ChargeAttack(const AttackStatus& _status, ANIMATION_ID _animation, Shape_Ptr _shape);
	~ChargeAttack();
	void initialize();
	void update(float deltaTime, Player* _player);
	void endAttack(Player* _player,IComboMadiator * _manager);
	const bool isChargeEnd()const;
	const bool isStart() const;
	void attackStart(float _chargeTime);
	void motion(Player* _player);

	void chargeStart(Player* _player);
	void changeMotion(AnimatorOne& _animator, float _speed);
	const bool isNextAttack(const AnimatorOne& _animator)const;
	const bool isEndMotion(const AnimatorOne& _animator) const;
private:
	bool m_chargeKey;
	bool m_isKeyPushNow;
	float m_chargeTime;
	bool m_isStart;
	bool m_isFirstFrame;
	//!攻撃ステータス
	AttackStatus m_status;
	//!アニメーション
	ANIMATION_ID m_Animation;
	//!次の攻撃
	Combo m_nextCombo;
	//判定用形状
	Shape_Ptr m_Shape;
};