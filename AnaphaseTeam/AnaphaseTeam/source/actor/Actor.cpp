#include "../../header/actor/Actor.h"
#include "../../header/map/Map.h"
#include "../../header/shape/Ray.h"
#include "../../header/math/Calculate.h"
#include "../../header/state/IActorState.h"
const float Actor::GRAVITY = -0.1f;

Actor::Actor(const Transform & _transform, MODEL_ID _modelID,Actor_Tag _tag)
	:m_transform(_transform), 
	m_isDead(false),
	m_isGround(false),
	m_animatorOne(_modelID),
	m_Tag(_tag),
	m_collision(this),
	m_states(),
	m_currentState(nullptr),
	m_currentStateKey(ACTOR_STATE::STAND)
{
}

Actor::~Actor()
{
	m_collision.initialize();
}

void Actor::initialize()
{
	m_collision.initialize();
	m_isDead = false;
}

void Actor::finish()
{
}
void Actor::collisionGround(const Map& _map)
{
	GSvector3 intersect;
	//åªç›ÇÃà íuÇ©ÇÁâ∫ï˚å¸ÇÃRayÇçÏÇÈ
	GSvector3 position = m_transform.m_translate;
	Ray ray(position);
	if (!ray.isCollitionMap(_map, &intersect))
	{
		return;
	}
	m_isGround = position.y <= intersect.y;
	if (!m_isGround)
	{
		m_transform.translate_up(GRAVITY);
		return;
	}
	//mapÇ…ñÑÇﬂçûÇ‹ÇÍÇƒÇ¢ÇΩÇÁyç¿ïWÇåì_Ç…à⁄ìÆ
	m_transform.m_translate.y = intersect.y;
}
const ACTOR_STATE Actor::getState() const
{
	return m_currentStateKey;
}
void Actor::collision(Actor & _other)
{
	m_collision.collision(_other.m_collision);
}
const float Actor::distanceActor(const Actor & _other) const
{
	return m_transform.m_translate.distance(_other.m_transform.m_translate);
}
const float Actor::distance(const GSvector3 & _position) const
{
	return m_transform.m_translate.distance(_position);
}
const GSquaternion Actor::targetDirection(const Actor & _target) const
{
	GSvector3 vector = _target.m_transform.m_translate - m_transform.m_translate;
	Math::ATan atan;
	float radian = atan(vector.z, vector.x);
	return GSquaternion(radian, { 0,1,0 });
}
void Actor::changeState(ACTOR_STATE _state)
{
	m_currentStateKey = _state;
	m_currentState = m_states.at(m_currentStateKey);
	m_currentState->start();
}
const bool Actor::isSameActor(const Actor * _other) const
{
	return this==_other;
}
const bool Actor::isSameTag(Actor_Tag _tag) const
{
	return m_Tag==_tag;
}
void Actor::action(float deltaTime)
{
	m_currentState->action(deltaTime);
}
void Actor::registerState(ACTOR_STATE _name, IActorState * _state)
{
	m_states.insert(std::make_pair(_name,StatePtr(_state)));
}
const bool Actor::isDead() const
{
	return m_isDead;
}
