#pragma once
#include <GSvector3.h>
#include "CollisionActorType.h"
class Actor;
struct Hit
{
	Actor* m_paremt;
	CollisionActorType m_type;
	GSvector3 m_intersect;
};