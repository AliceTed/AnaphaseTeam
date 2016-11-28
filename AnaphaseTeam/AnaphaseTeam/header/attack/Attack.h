#pragma once
/**
* @file ContinuationCombo.h
* @brief �A���R���{�p�P���U��
* @author �����T��
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
	//!�U���X�e�[�^�X
	AttackStatus m_status;
	//!�A�j���[�V����
	ANIMATION_ID m_Animation;
	//!���̍U��
	ATTACK_TYPE m_nextQuick;
	ATTACK_TYPE m_nextSlow;
};