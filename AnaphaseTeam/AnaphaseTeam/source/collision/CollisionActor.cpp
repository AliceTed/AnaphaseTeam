#include "../../header/collision/CollisionActor.h"
#include <algorithm>
#include "../../header/collision/HitInformation.h"
CollisionActor::CollisionActor(Shape * _shape, Collision_Tag _tag)
	:m_shape(_shape),m_tag(_tag), m_isDead(false), m_previous()
{
}

CollisionActor::~CollisionActor()
{
	m_previous.clear();
}

void CollisionActor::update(float deltaTime)
{
	previousRemove([](Collision_Ptr& _actor)->bool{return _actor->isDead();});
	doUpdate(deltaTime);
}

void CollisionActor::draw(IRenderer * _renderer)
{
	doDraw(_renderer);
}

void CollisionActor::collision(Collision_Ptr&  _other,HitInformation& _hit)
{
	if (isPreviousFind(_other))
	{
		collision_Stay(_hit);
		return;
	}
	//‰ß‹Ž‚É‚È‚©‚Á‚½‚ç,“o˜^‚ÆŒÄ‚Ño‚µ
	m_previous.emplace_back(_other);
	collision_Enter(_hit);
}

void CollisionActor::exit(Collision_Ptr&  _other,HitInformation& _hit)
{
	//íœ‚µ‚½‚çexit‚ðŒÄ‚Ô
	bool isremove =isPreviousRemove(_other);
	if (!isremove)return;
	collision_Exit(_hit);
}

const bool CollisionActor::isCollision(Collision_Ptr&  _other, HitInformation* _out1, HitInformation* _out2) const
{
	_out1->m_tag = m_tag;
	_out2->m_tag = _other->m_tag;
	GSvector3 intersect;
	bool isHit= _other->m_shape->isCollision(m_shape.get(), &intersect);
	_out1->m_intersect = intersect;
	_out2->m_intersect = intersect;
	return isHit;
}

const bool CollisionActor::isDead() const
{
	return m_isDead;
}

void CollisionActor::destroy()
{
	m_isDead = true;
}

void CollisionActor::doUpdate(float deltaTime)
{
}

void CollisionActor::doDraw(IRenderer * _renderer)
{
}

void CollisionActor::collision_Enter(HitInformation& _hit)
{
}

void CollisionActor::collision_Stay(HitInformation& _hit)
{
}

void CollisionActor::collision_Exit(HitInformation& _hit)
{
}
const bool CollisionActor::isPreviousFind(Collision_Ptr&  _other)
{
	return std::any_of(m_previous.begin(), m_previous.end(), [&_other](Collision_Ptr&  _actor) {return _other == _actor;});
}

const bool CollisionActor::isPreviousRemove(Collision_Ptr&  _other)
{
	return previousRemove([&_other](Collision_Ptr&  _actor) {return _actor ==_other;});
}

const bool CollisionActor::previousRemove(std::function<bool(Collision_Ptr&)> _func)
{
	auto itr = std::remove_if(m_previous.begin(), m_previous.end(), _func);
	if (itr == m_previous.end())return false;
	m_previous.erase(itr);
	return true;
}
