#include "../../header/collision/CollisionTable.h"


CollisionTable::CollisionTable()
	:table(static_cast<unsigned int>(Actor_Tag::SIZE), static_cast<unsigned int>(Actor_Tag::SIZE))
{
	unsigned int size = static_cast<unsigned int>(Actor_Tag::SIZE);
	for (unsigned int y = 0; y <size; y++)
	{
		for (unsigned int x = 0;x <size;x++)
		{
			table(y, x) = true;
		}
	}
}

CollisionTable::~CollisionTable()
{
}
void CollisionTable::setNonCollision(Actor_Tag _tag1, Actor_Tag _tag2)
{
	unsigned int t1,t2;
	t1 = static_cast<unsigned int>(_tag1);
	t2 = static_cast<unsigned int>(_tag2);
	table(t1,t2) = false;
	table(t2, t1) = false;
}
const bool CollisionTable::isConfirmTag(Actor_Tag _tag1, Actor_Tag _tag2) const
{
	return table(static_cast<unsigned int>(_tag1), static_cast<unsigned int>(_tag2));
}
