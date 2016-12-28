#include "../../../header/state/player/AttackState.h"
#include "../../../header/data/id/ANIMATION_ID.h"
#include "../../../header/device/GameDevice.h"

Player::AttackState::AttackState(Player* _player)
	:ActorState(_player),
	m_inputTimer(0.3f), m_isCombo(COMBOSTEP::NON)
{
}

void Player::AttackState::start()
{
	m_inputTimer.initialize();
	m_isCombo = COMBOSTEP::NON;
}
void Player::AttackState::action(float deltaTime)
{
	m_actor->m_combo.update(deltaTime);
	input(deltaTime);
	m_actor->m_Revision.update(deltaTime, &m_actor->m_transform.m_translate);
	m_actor->specialSkill();
	

	if (m_actor->m_isGround)
	{
		m_actor->subActionStart();
		return;
	}
	if (m_inputTimer.isEnd())
	{
		changeState(ACTOR_STATE::LIMITFALL);
	}
}
Player::AttackState* Player::AttackState::clone() const
{
	return new AttackState(*this);
}

void Player::AttackState::input(float deltaTime)
{
	//�A�j���[�V�����I��������t�J�n
	if (m_isCombo == COMBOSTEP::END)
	{
		if (m_actor->m_combo.isAttack(m_actor->m_animatorOne))
		{
			m_isCombo = COMBOSTEP::NON;
		}
		return;
	}
	if (m_isCombo == COMBOSTEP::NON)
	{
		m_isCombo = m_actor->m_animatorOne.isEndCurrentAnimation() ? COMBOSTEP::START : m_isCombo;
	}
	if (m_isCombo == COMBOSTEP::NON)
		return;
	///////////�U������X�^���h�֑J�ڊJ�n///////////

	m_actor->m_combo.finish(m_actor->m_animatorOne);

	//////////���[�v���I�������///////////////////
	if (!m_actor->m_animatorOne.getNext())
	{
		changeState(ACTOR_STATE::STAND);
		m_isCombo = COMBOSTEP::END;
		return;
	}
	Input_Ptr& input = GameDevice::getInstacnce().input();
	bool isSlow = input->slowAttackTrigger();
	//�U���{�^���������ꂽ��
	if (!input->quickAttackTrigger() && !isSlow)return;
	//���̍U���𔻒�
	//���ɂȂ���U����������false�Ԃ�
	if (m_actor->m_combo.next(isSlow))
	{
		m_isCombo = COMBOSTEP::END;
		return;
	}
	changeState(ACTOR_STATE::STAND);
}
