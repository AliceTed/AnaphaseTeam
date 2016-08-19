//#include "Collision.h"
//
//
//Collision::Collision()
//	:table()
//{
//	table.setNonCollision(GAMEOBJECT_TYPE::PLAYER, GAMEOBJECT_TYPE::PLAYER);
//	table.setNonCollision(GAMEOBJECT_TYPE::ENEMY, GAMEOBJECT_TYPE::ENEMY);
//	table.setNonCollision(GAMEOBJECT_TYPE::ATTACKRANGE, GAMEOBJECT_TYPE::ATTACKRANGE);
//	table.setNonCollision(GAMEOBJECT_TYPE::PLAYER, GAMEOBJECT_TYPE::ATTACKRANGE);
//}
//
//Collision::~Collision()
//{
//}
//
//
//const bool Collision::isConfirmCollisionTable(GAMEOBJECT_TYPE type1, GAMEOBJECT_TYPE type2) const
//{
//	return table.isConfirmCollisionTable(type1,type2);
//}
//
//const bool Collision::isCollision(const Shape & shape1, const Shape & shape2) const
//{
//	switch (shape1.getType())
//	{
//	case SHAPETYPE::SHPERE:
//		return sphereCollision(dynamic_cast<const Sphere&>(shape1), shape2);
//
//	case SHAPETYPE::SEGMENT:
//		return segmentCollision(dynamic_cast<const Segment&>(shape1), shape2);
//		
//	case SHAPETYPE::OBB:
//		return boxOBBCollision(dynamic_cast<const OBB&>(shape1), shape2);
//
//	case SHAPETYPE::AABB:
//		return boxAABBCollision(dynamic_cast<const AABB&>(shape1), shape2);
//
//	case SHAPETYPE::CAPSULE:
//		return capsuleCollision(dynamic_cast<const Capsule&>(shape1), shape2);
//
//	}
//	return false;
//}
//
//const bool Collision::sphereCollision(const Sphere & sphere, const Shape & shape2)const
//{
//	switch (shape2.getType())
//	{
//	case SHAPETYPE::SHPERE:
//		return sphere_sphere(sphere, dynamic_cast<const Sphere&>(shape2));
//
//	case SHAPETYPE::SEGMENT:
//		return sphere_segment(sphere, dynamic_cast<const Segment&>(shape2));
//
//	case SHAPETYPE::OBB:
//		return  boxOBB_sphere(dynamic_cast<const OBB&>(shape2), sphere);
//
//	case SHAPETYPE::AABB:
//		return  boxAABB_sphere(dynamic_cast<const AABB&>(shape2), sphere);
//
//	case SHAPETYPE::CAPSULE:
//		return  sphere_capsule(sphere, dynamic_cast<const Capsule&>(shape2));
//	}
//	return false;
//}
//
//const bool Collision::segmentCollision(const Segment & segment, const Shape & shape2) const
//{
//	switch (shape2.getType())
//	{
//	case SHAPETYPE::SHPERE:
//		return sphere_segment(dynamic_cast<const Sphere&>(shape2),segment);
//
//	case SHAPETYPE::SEGMENT:
//		return segment_segment(segment, dynamic_cast<const Segment&>(shape2));
//
//	//case SHAPETYPE::OBB:
//	//	return  false;//boxOBB_segment(dynamic_cast<const OBB&>(shape2),segment);
//
//	//case SHAPETYPE::AABB:
//	//	return false;//boxAABB_segment(dynamic_cast<const BoxAABB&>(shape2), segment);
//
//	//case SHAPETYPE::CAPSULE:
//	//	return  false;//segment_capsule(segment,dynamic_cast<const Capsule&>(shape2));
//	}
//	return false;
//}
//
//const bool Collision::boxOBBCollision(const OBB & box, const Shape & shape2) const
//{
//	switch (shape2.getType())
//	{
//	case SHAPETYPE::SHPERE:
//		return boxOBB_sphere(box, dynamic_cast<const Sphere&>(shape2));
//
//	//case SHAPETYPE::SEGMENT:
//	//	return false;//boxOBB_segment(box,dynamic_cast<const Segment&>(shape2));
//
//	//case SHAPETYPE::OBB:
//	//	return  boxOBB_boxOBB(box, dynamic_cast<const OBB&>(shape2));
//
//	//case SHAPETYPE::AABB:
//	//	return  false;//boxOBB_boxAABB(box,dynamic_cast<const BoxAABB&>(shape2));
//
//	//case SHAPETYPE::CAPSULE:
//	//	return false;//boxOBB_capsule(box,dynamic_cast<const Capsule&>(shape2));
//	}
//	return false;
//}
//
//const bool Collision::boxAABBCollision(const AABB & box, const Shape & shape2) const
//{
//	switch (shape2.getType())
//	{
//	case SHAPETYPE::SHPERE:
//		return boxAABB_sphere(box, dynamic_cast<const Sphere&>(shape2));
//
//	//case SHAPETYPE::SEGMENT:
//	//	return false;//boxOBB_segment(box,dynamic_cast<const Segment&>(shape2));
//
//	//case SHAPETYPE::OBB:
//	//	return  false;//boxAABB_boxOBB(box,dynamic_cast<const OBB&>(shape2));
//
//	case SHAPETYPE::AABB:
//		return  boxAABB_boXAABB(box, dynamic_cast<const AABB&>(shape2));
//
//	//case SHAPETYPE::CAPSULE:
//	//	return false;//boxAABB_capsule(box, dynamic_cast<const Capsule&>(shape2));
//	}
//	return false;
//}
//
//const bool Collision::capsuleCollision(const Capsule & capsule, const Shape & shape2) const
//{
//	switch (shape2.getType())
//	{
//	case SHAPETYPE::SHPERE:
//		return sphere_capsule(dynamic_cast<const Sphere&>(shape2),capsule);
//
//	//case SHAPETYPE::SEGMENT:
//	//	return false;//capsile_segment(capsule,dynamic_cast<const Segment&>(shape2));
//
//	//case SHAPETYPE::OBB:
//	//	return false;//apsule_boxOBB(cpsule,dynamic_cast<const OBB&>(shape2));
//
//	//case SHAPETYPE::AABB:
//	//	return false;//capsule_boxAABB(capsule,dynamic_cast<const BoxAABB&>(shape));
//
//	case SHAPETYPE::CAPSULE:
//		return  capsule_capsule(capsule, dynamic_cast<const Capsule&>(shape2));
//	}
//	return false;
//}
//
//const bool Collision::segment_segment(const Segment & seg1, const Segment & seg2)const
//{
//	return seg1.intersects(seg2);
//}
//
//const bool Collision::sphere_sphere(const Sphere & sphere1, const Sphere & sphere2) const
//{
//	return sphere1.intersects(sphere2);
//}
//
//const bool Collision::boxOBB_boxOBB(const OBB & box1, const OBB & box2) const
//{
//	return box1.intersects(box2);
//}
//
//const bool Collision::boxAABB_boXAABB(const AABB & box1, const AABB & box2) const
//{
//	return box1.intersects(box2);
//}
//const bool Collision::boxOBB_sphere(const OBB & box, const Sphere & sphere)const
//{
//	return  box.point_distance(sphere.center) <= sphere.radius;
//}
//
//const bool Collision::boxAABB_sphere(const AABB & box, const Sphere & sphere) const
//{
//	return box.point_distance(sphere.center) <= sphere.radius;
//}
//
//const bool Collision::sphere_segment(const Sphere & sphere, const Segment & segment) const
//{
//	GSvector3 v = segment.v();
//	float r2 = sphere.radius*sphere.radius;
//
//	//p1‚ÌŠO‘¤‚É‚ ‚Á‚Ä‹«ŠE‰~‚æ‚è’†S‚Ü‚Å‚Ì‹——£‚ª”¼ŒaˆÈ‰º‚©H
//	//p1‚Ì’[“_‚ÅÚG‚µ‚Ä‚¢‚é
//	GSvector3 v1 = sphere.center - segment.position;
//	float t = gsVector3Dot(&v, &v1) / gsVector3Dot(&v, &v);//’†S‚©‚çü•ª‚É‰º‚µ‚½“_‚Æp1‚Ü‚Å‚Ì‹——£‚Ì”ä
//	if ((t < 0) && (v1.lengthSq() <= r2))
//	{
//		return true;
//	}
//
//	//p2‚ÌŠO‘¤‚É‚ ‚Á‚Ä‹«ŠE‰~‚æ‚è’†S‚Ü‚Å‚Ì‹——£‚ª”¼ŒaˆÈ‰º‚©H
//	//p2‚Ì’[“_‚ÅÚG‚µ‚Ä‚¢‚é
//	GSvector3 v2 = sphere.center - segment.endPosition();
//	if ((1 < t) && (v2.lengthSq() <= r2))
//	{
//		return true;
//	}
//
//	//‹«ŠE‰~‚Ì’†S‚ªp1p2‚ÌŠÔ‚É‚ ‚Á‚Äü•ª‚ÉÚG‚µ‚Ä‚¢‚éê‡
//	GSvector3 vn = v1 - v * t; //–@ü•ûŒü‚ÌƒxƒNƒgƒ‹
//	if ((0 <= t) && (t <= 1) && (vn.lengthSq() <= r2))
//	{
//		return true;
//	}
//	return false;
//}
//
//const bool Collision::sphere_capsule(const Sphere & sphere, const Capsule & capsule) const
//{
//	Sphere sph(sphere);
//	sph.expand(capsule.radius);
//	return sphere_segment(sph, capsule.segment);
//}
//
//const bool Collision::capsule_capsule(const Capsule & capsule1, const Capsule & capsule2) const
//{
//	return !!gsCollisionCupsuleAndCupsule
//		(
//			&capsule1.segment.position,&capsule1.segment.endPosition(),capsule1.radius,
//			&capsule2.segment.position, &capsule2.segment.endPosition(), capsule2.radius,
//			NULL,NULL
//		);
//	/*GSvector3 a = capsule1.segment.v();
//	GSvector3 b = capsule2.segment.v();
//	GSvector3 c = capsule2.segment.position - capsule1.segment.position;
//	GSvector3 n;
//	gsVector3Normalize(&n, &a.cross(b));
//	float L = c.dot(n);
//	float D = capsule1.radius + capsule2.radius;
//
//	GSvector3 n1;
//	gsVector3Normalize(&n1, &n.cross(a));
//	GSvector3 n2;
//	gsVector3Normalize(&n2, &n.cross(b));
//
//	GSvector3 P3 = capsule2.segment.position - L * n;
//	GSvector3 P4 = capsule2.segment.endPosition() - L * n;
//	GSvector3 v1 = capsule1.segment.position - P3;
//	GSvector3 v2 = capsule1.segment.endPosition() - P3;
//	GSvector3 v3 = P3 - capsule1.segment.position;
//	GSvector3 v4 = P4 - capsule1.segment.position;
//
//	float L1 = n2.dot(v1);
//	float L2 = n2.dot(v2);
//	float L3 = n1.dot(v3);
//	float L4 = n1.dot(v4);
//
//	float t1 = L3 / (L3 - L4);
//	float t2 = L1 / (L1 - L2);
//
//	if ((L * L < D * D) && (0 < t1 && t1 < 1) && (0 < t2 && t2 < 1))
//	{
//		return true;
//	}
//
//	if (sphere_capsule(Sphere(capsule1.segment.position, capsule1.radius), capsule2))
//	{
//		return true;
//	}
//	if (sphere_capsule(Sphere(capsule1.segment.endPosition(), capsule1.radius), capsule2))
//	{
//		return true;
//	}
//	if (sphere_capsule(Sphere(capsule2.segment.position, capsule2.radius), capsule1))
//	{
//		return true;
//	}
//	if (sphere_capsule(Sphere(capsule2.segment.endPosition(), capsule2.radius), capsule1))
//	{
//		return true;
//	}
//	return false;*/
//}