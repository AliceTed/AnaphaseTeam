#include "..\..\header\collision\HitInformation.h"

HitInformation::HitInformation(Actor * _parent)
	:m_parent(_parent),m_tag(),m_intersect(0,0,0)
{
}
