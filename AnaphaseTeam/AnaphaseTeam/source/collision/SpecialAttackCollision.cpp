#include "../../header/collision/SpecialAttackCollision.h"
#include "../../header/shape/Sphere.h"
#include "effect\effectmanager.h"
Player::SpecialAttackCollision::SpecialAttackCollision(Player* _player)
	:CollisionActor(new Sphere(GSvector3(0, 0, 0), 5.0f), Collision_Tag::PLAYER_SPECIALATTACK),
	m_player(_player),
	m_destroyTime(0.1f)
{
	m_destroyTime.initialize();
	GSvector3 pos = m_player->m_transform.m_translate;
	pos.y += 1.0f;
	EffectManager::getInstance().effectPlay(EFFECT_ID::SPATTACK, pos);
}
void Player::SpecialAttackCollision::doUpdate(float deltaTime)
{
	m_shape->transfer(m_player->m_transform.m_translate);
	m_destroyTime.update(deltaTime);
	if(m_destroyTime.isEnd())
	{
		destroy();
	}
}

void Player::SpecialAttackCollision::doDraw(IRenderer * _renderer)
{
	//m_shape->draw(_renderer);
}
