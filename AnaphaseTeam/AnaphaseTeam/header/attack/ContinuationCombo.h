#pragma once
/**
* @file ContinuationCombo.h
* @brief �A���R���{�p�P���U��
* @author �����T��
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
class ContinuationCombo
{
public:
	ContinuationCombo(const AttackStatus& _status, ANIMATION_ID _animation, Shape_Ptr _shape);
	~ContinuationCombo();
	void openAnAttack(Player* _player, TestActor* _other);
	void initialize();
	void update(Player* _player);
	void anime(Player* _player);
	const bool isEndAnimation(Player *_player) const;

private:
	//!�U���X�e�[�^�X
	AttackStatus m_status;
	//!�A�j���[�V����
	ANIMATION_ID m_Animation;

	//����p�`��
	Shape_Ptr m_Shape;
};