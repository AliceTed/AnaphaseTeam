#include "../../header/attack/Attack.h"
#include "../../header/actor/Player/Player.h"
Attack::Attack(const AttackStatus & _status, ANIMATION_ID _animation, Shape_Ptr _shape)
	:m_status(_status), m_Animation(_animation), m_Shape(_shape)
{
}
Attack::~Attack()
{

}
void Attack::initialize(Player* _player)
{
	motion(_player);
	_player->attackRange(this);
}
void Attack::update(float deltaTime,Player * _player)
{
	motion(_player);
}
void Attack::motion(Player * _player)
{
	_player->attackmotion(*this);
}
void Attack::changeMotion(AnimatorOne & _animator)
{
	_animator.changeAnimation(m_Animation, false, false, 2.0f);
}
const bool Attack::isNextAttack(const AnimatorOne & _animator) const
{
	float end = _animator.getCurrentAnimationEndTime();
	float current = _animator.getCurrentAnimationTime();
	float limit = 20.0f;
	return (end- limit)<=current;
}
const bool Attack::isEndMotion(const AnimatorOne & _animator) const
{
	return _animator.isEndCurrentAnimation();
}
void Attack::range(Group_Ptr _group, Transform & _transform, std::function<bool()> _isDead)
{
	//–³—‚â‚èUŒ‚’†‚É‹…”»’è‚ğƒLƒƒƒ‰‚Ì‘O‚Éì‚é
	float radius = 1.5f;
	GSvector3 front = _transform.front()*(radius*1.5f);
	GSvector3 pos(_transform.getPosition() + front);
	pos.y += 1.0f;
	Collision_Ptr actor = std::make_shared<CollisionActor>(m_Shape, CollisionActorType::PLAYER_ATTACK);
	actor->set_dead([=]()->bool {return _isDead(); });
	actor->set_update([&](float deltaTime, Shape_Ptr _shape)
	{
		float radius = 1.5f;
		GSvector3 front = _transform.front()*(radius*1.5f);
		GSvector3 pos(_transform.getPosition() + front);
		pos.y += 1.0f;
		_shape->transfer(pos);
	});
	actor->set_draw([](const Renderer& _renderer, Shape_Ptr _shape) { _shape->draw(_renderer); });
	_group->add(actor);
}

