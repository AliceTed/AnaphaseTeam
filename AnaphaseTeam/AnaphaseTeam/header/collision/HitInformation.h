#pragma once

#include <GSvector3.h>
#include "Collision_Tag.h"
class Actor;
struct HitInformation
{
	Actor * m_parent;
	Collision_Tag m_tag;
	GSvector3 m_intersect;

	HitInformation(Actor* _parent);
};