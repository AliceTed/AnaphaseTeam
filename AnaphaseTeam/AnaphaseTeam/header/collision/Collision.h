/*
現状必要ない
*/


//#pragma once
//#ifndef _COLLISION_H_
//#define _COLLISION_H_
//
//#include "Shape.h"
//#include "OBB.h"
//#include "Sphere.h"
//#include "Segment.h"
//#include "Capsule.h"
//#include "AABB.h"
//
//#include "CollisionTable.h"
//class Collision
//{
//public:
//	Collision();
//	~Collision();
//
//	//表を確認　判定を行うならtrue
//	const bool isConfirmCollisionTable(GAMEOBJECT_TYPE type1, GAMEOBJECT_TYPE type2)const;
//	const bool isCollision(const Shape& shape1, const Shape& shape2)const;
//private:
//	const bool sphereCollision(const Sphere& sphere, const Shape& shape2)const;
//	const bool segmentCollision(const Segment& segment, const Shape& shape2)const;
//	const bool boxOBBCollision(const OBB& box, const Shape& shape2)const;
//	const bool boxAABBCollision(const AABB& box, const Shape& shape2)const;
//	const bool capsuleCollision(const Capsule& capsule, const Shape& shape2)const;
//
//
//	/*球と線分*/
//	const bool sphere_segment(const Sphere& sphere, const Segment& segment)const;
//	const bool sphere_capsule(const Sphere& sphere, const Capsule& capsule)const;
//	const bool boxOBB_sphere(const OBB& box, const Sphere& sphere)const;
//	const bool boxAABB_sphere(const AABB& box, const Sphere& sphere)const;
//
//	const bool capsule_capsule(const Capsule& capsule1, const Capsule& capsule2)const;
//	/*線と線*/
//	const bool segment_segment(const Segment& seg1, const Segment& seg2)const;
//	const bool sphere_sphere(const Sphere& sphere1, const Sphere& sphere2)const;
//	const bool boxOBB_boxOBB(const OBB& box1, const OBB& box2)const;
//	const bool boxAABB_boXAABB(const AABB& box1, const AABB& box2)const;
//
//private:
//	CollisionTable table;
//};
//#endif
//
