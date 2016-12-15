#include "../../header/attack/Attack.h"
#include "../../header/actor/Player/Player.h"
#include "../../header/device/GameDevice.h"
Attack::Attack(const AttackParameter & _paramerer)
	:m_parameter(_paramerer),
	m_spawnTimer(_paramerer.shapeData.spawnTime),
	isSpawn(false)
{
}
Attack::~Attack()
{
}
void Attack::initialize(Player* _player)
{
	GameDevice::getInstacnce().sound().playSE(SE_ID::ENTER);
	motion(_player);
	_player->homing();
	m_spawnTimer.initialize();
	isSpawn = false;
}
void Attack::update(float deltaTime, Player * _player)
{
	if (isSpawn)return;
	m_spawnTimer.update(deltaTime);
	if (m_spawnTimer.isEnd())
	{
		isSpawn = true;
		_player->createAttackCollision(m_parameter.shapeData);
	}

}
void Attack::motion(Player * _player)
{
	_player->attackmotion(*this);
}
void Attack::changeMotion(AnimatorOne & _animator, float _speed)
{
	_animator.changeAnimation(m_parameter.animationID,true, false, false,3.0f, _speed);
}

const std::string& Attack::next(bool _isSlow) const
{
	return _isSlow ? m_parameter.slowID : m_parameter.quickID;
}

const AttackStatus & Attack::getStatus() const
{
	return m_parameter.status;
}

