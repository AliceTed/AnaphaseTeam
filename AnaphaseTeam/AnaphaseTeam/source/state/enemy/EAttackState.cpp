#include "state/enemy/EAttackState.h"
#include "data/id/ENEMY_ANIMATION.h"
#include "math/Random.h"
Goblin::EAttackState::EAttackState(Goblin* _enemy)
	:ActorState(_enemy), m_secoundAttack(), m_timer(0.0f), funcPtr(nullptr)
{
}

void Goblin::EAttackState::start()
{
	//�֐��|�C���^�ϐ��B�����͑O�i
	funcPtr = std::bind(&Goblin::EAttackState::moveFront, this, std::placeholders::_1);
	m_timer.initialize();
	m_timer.setEndTime(0.8f);
	m_actor->lookAtToPlayer();//�v���C���[�̕���������
	Math::Random rnd;
	m_secoundAttack = rnd(0, 10) == 0 ? true : false;//��i�U�������邩
	m_actor->m_animatorOne.changeAnimationLerp(ENEMY_ANIMATION::ATTACK1);
	GameDevice::getInstacnce().sound().playSE(SE_ID::ENEMY_ATTACK);
}

void Goblin::EAttackState::action(float deltaTime)
{
	funcPtr(deltaTime);
}
void  Goblin::EAttackState::moveFront(float deltaTime)
{
	m_timer.update(deltaTime);
	m_actor->m_transform.translate_front(0.007f);
	if (m_timer.isEnd())
	{
		//�^�C�}�[���I������炠���蔻��𔭐�������
		funcPtr = std::bind(&Goblin::EAttackState::collisionStart, this, std::placeholders::_1);
	}
}
void Goblin::EAttackState::collisionStart(float deltaTime)
{
	m_actor->createAttackCollision();
	//�����ɏI�����菈���ɐ؂�ւ�
	funcPtr = std::bind(&Goblin::EAttackState::finshAction, this, std::placeholders::_1);
}
void Goblin::EAttackState::finshAction(float deltaTime)
{
	if (!m_actor->m_animatorOne.isEndCurrentAnimation())
		return;
	GameDevice::getInstacnce().sound().stopSE(SE_ID::ENEMY_ATTACK);
	ACTOR_STATE next;
	next = m_secoundAttack ? ACTOR_STATE::ESECOUNDATTACK : ACTOR_STATE::ETHINK;
	next = ACTOR_STATE::ESECOUNDATTACK;
	m_actor->changeState(next);
}
Goblin::EAttackState * Goblin::EAttackState::clone() const
{
	return new EAttackState(*this);
}
