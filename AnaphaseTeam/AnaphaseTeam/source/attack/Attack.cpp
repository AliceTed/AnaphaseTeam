#include "../../header/attack/Attack.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/device/GameDevice.h"
Attack::Attack(const AttackParameter & _paramerer)
	:m_parameter(_paramerer),
	m_spawnTimer(_paramerer.shapeData.spawnTime),
	isSpawn(false), isFinished(false)
{
}
Attack::~Attack()
{
}
void Attack::initialize(Player* _player)
{
	GameDevice::getInstacnce().sound().playSE(SE_ID::PLAYER_ATTACK);
	motion(_player);
	_player->revision();
	m_spawnTimer.initialize();
	isSpawn = false;
	isFinished = false;
}
void Attack::update(float deltaTime, Player * _player)
{
	if (isSpawn)return;
	float attackSpeed = _player->getAttackSpeed()*m_parameter.speed;
	m_spawnTimer.update(deltaTime * attackSpeed);
	if (m_spawnTimer.isEnd())
	{
		isSpawn = true;
		_player->createAttackCollision(m_parameter.shapeData,m_parameter.speed);
	}

}
void Attack::motion(Player * _player)
{
	_player->attackmotion(*this);
}
void Attack::changeMotion(Animator & _animator, float _speed)
{
	_animator.changeAnimation(m_parameter.animationID, true, false, false, 10.0f, _speed* m_parameter.speed);
}

bool Attack::finish(Animator & _animator)
{
	if (isFinished)return true;
	float millsecond = m_parameter.nextInput*60.0f;
	_animator.changeAnimation(ANIMATION_ID::STAND, true, false, false, millsecond/*ラープタイム*/);
	isFinished = true;
	return true;
}


const std::string& Attack::next(bool _isSlow) const
{
	return _isSlow ? m_parameter.slowID : m_parameter.quickID;
}

const AttackStatus & Attack::getStatus() const
{
	return m_parameter.status;
}
const unsigned int Attack::getID()const
{
	return m_parameter.animationID;
}
