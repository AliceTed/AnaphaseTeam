#include "../../header/collision/EnemyCollision.h"
#include "../../header/actor/Enemy/Enemy.h"
#include "../../header/shape/Capsule.h"
#include "../../header/collision/HitInformation.h"
#include "../../header/actor/Player/Player.h"
EnemyCollision::EnemyCollision(Enemy * _enemy)
	:CollisionActor(new Capsule(Segment(GSvector3(0, 0.2f, 0), GSvector3(0, 1.2f, 0)), 0.4f), Collision_Tag::ENEMY),
	m_enemy(_enemy)
{
}

EnemyCollision::~EnemyCollision()
{
}

void EnemyCollision::chase(const GSvector3 & _position)
{
	m_shape->transfer(_position+GSvector3(0,0.2f,0));
}

void EnemyCollision::doUpdate(float deltaTime)
{
	m_enemy->collisionChase(this);
}

void EnemyCollision::collision_Enter(HitInformation & _hit)
{
	Actor* act = _hit.m_parent;
	if (!act->isSameTag(Actor_Tag::PLAYER))return;
	Player* player = dynamic_cast<Player*>(act);
	if (player == nullptr)return;
	m_enemy->damage(player);
}

void EnemyCollision::doDraw(const Renderer & _renderer)
{
	//m_shape->draw(_renderer);
}