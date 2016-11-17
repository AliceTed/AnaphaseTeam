#include "../../header/collision/SpecialAttackCollision.h"
#include "../../header/shape/Sphere.h"
#include "../../header/actor/Player/Player.h"

//****
#include "../../header/renderer/Renderer.h"
SpecialAttackCollision::SpecialAttackCollision(Player* _player, SpecialAttack* _specialAttack)
	:CollisionActor(new Sphere(GSvector3(0, 0, 0), 3.0f), Collision_Tag::PLAYER_SPECIALATTACK),
	m_text("Non"),
	m_player(_player),
	m_specialAttack(_specialAttack)
{
}
SpecialAttackCollision::~SpecialAttackCollision()
{
}

void SpecialAttackCollision::chase(const GSvector3 & _position)
{
	m_shape->transfer(_position + GSvector3(0, 0.2f, 0));
}

void SpecialAttackCollision::doUpdate(float deltaTime)
{
	m_player->collisionChase(this);
	if (m_specialAttack->isEnd())
	{
		destroy();
	}
}

void SpecialAttackCollision::doDraw(const Renderer & _renderer)
{
	m_shape->draw(_renderer);
	_renderer.getDraw2D().string(m_text, &GSvector2(10, 10), 20);
}
