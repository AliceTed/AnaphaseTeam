#pragma once

#include "../data/ANIMATION_ID.h"
#include "AttackStatus.h"
#include "../../header/shape/Shape.h"
#include <memory>
#include "ECombo.h"
#include "IAttack.h"
typedef std::shared_ptr<Shape> Shape_Ptr;
class Player;
class CollisionMediator;
class AnimatorOne;
class ComboAttack:IAttack
{
public:
	ComboAttack(const AttackStatus& _status, ANIMATION_ID _animation, Combo next, Shape_Ptr _shape);
	~ComboAttack();
	void initialize();
	void update(float deltaTime, Player* _player);
	void motion(Player* _player);

	void changeMotion(AnimatorOne& _animator);
	const bool isNextAttack(const AnimatorOne& _animator)const;
	const bool isEndMotion(const AnimatorOne& _animator) const;
	const Combo next()const;
	//bool isEndAttackTime(AnimatorOne * _animator);
private:
	//!�U���X�e�[�^�X
	AttackStatus m_status;
	//!�A�j���[�V����
	ANIMATION_ID m_Animation;
	//!���̍U��
	Combo m_nextCombo;
	//����p�`��
	Shape_Ptr m_Shape;
};
