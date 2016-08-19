//#include "AABB.h"
//#include <cmath>
//#include "Renderer3D.h"
//AABB::AABB(const GSvector3& position, const GSvector3& radius)
//	:position(position),radius(radius)
//{
//}
//
//AABB::~AABB()
//{
//}
//
//const bool AABB::intersects(const AABB & other) const
//{
//	if (position.x-radius.x > (other.position.x + other.radius.x))return false;
//	if ((position.x + radius.x) < other.position.x-other.radius.x)return false;
//
//	if (position.y-radius.y > (other.position.y + other.radius.y))return false;
//	if ((position.y + radius.y) < other.position.y - other.radius.y)return false;
//
//	if (position.z -radius.z> (other.position.z + other.radius.z))return false;
//	if ((position.z + radius.z) < other.position.z-other.radius.z)return false;
//	return true;
//}
//
//void AABB::translate(const GSvector3 & _position)
//{
//	position += _position;
//}
//
//void AABB::transfer(const GSvector3 & _position)
//{
//	position = _position;
//}
//
//void AABB::expand(const GSvector3 & _size)
//{
//	radius += _size;
//}
//
//const float AABB::point_distance(const GSvector3 & point) const
//{
//	float sqLen = 0;   // �����ׂ̂���̒l���i�[
//	sqLen += margin(position.x+radius.x,position.x-radius.x,point.x);
//	sqLen += margin(position.y + radius.y, position.y - radius.y, point.y);
//	sqLen += margin(position.z + radius.z, position.z - radius.z, point.z);
//
//	return std::sqrt(sqLen);
//}
//
//const float AABB::margin(float max, float min, float point) const
//{
//	// �e���œ_���ŏ��l�ȉ��������͍ő�l�ȏ�Ȃ�΁A�����l��
//	if (point < min)  // i=0��X�A1��Y�A2��Z�̈Ӗ��ł�
//		return (point - min) * (point- min);
//	if (point > max)
//		return  (point -max) * (point - max);
//	
//	return 0;
//}
//
//void AABB::draw(const Renderer3D & renderer)
//{
//	renderer.drawBox(&position,&radius,&GSvector3(0,0,0));
//}
//
//const SHAPETYPE AABB::getType() const
//{
//	return SHAPETYPE::AABB;
//}
