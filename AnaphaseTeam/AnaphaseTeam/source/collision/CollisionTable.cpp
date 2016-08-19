//#include "CollisionTable.h"
//
//
//CollisionTable::CollisionTable()
//	:table()
//{
//	unsigned int size = static_cast<unsigned int>(GAMEOBJECT_TYPE::MAX);
//	table.setSize(size,size);
//	for (unsigned int y = 0; y <size; y++)
//	{
//		for (unsigned int x = 0;x <size;x++)
//		{
//			table(y, x) = true;
//		}
//	}
//}
//
//CollisionTable::~CollisionTable()
//{
//}
//void CollisionTable::setNonCollision(GAMEOBJECT_TYPE type1, GAMEOBJECT_TYPE type2)
//{
//	unsigned int t1,t2;
//	t1 = static_cast<unsigned int>(type1);
//	t2 = static_cast<unsigned int>(type2);
//	table(t1,t2) = false;
//	table(t2, t1) = false;
//}
//const bool CollisionTable::isConfirmCollisionTable(GAMEOBJECT_TYPE type1, GAMEOBJECT_TYPE type2) const
//{
//	return table(static_cast<unsigned int>(type1), static_cast<unsigned int>(type2));
//}
