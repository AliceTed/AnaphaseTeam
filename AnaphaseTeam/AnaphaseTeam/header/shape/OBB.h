#pragma once
#ifndef _BOXOBB_H_
#define _BOXOBB_H_
#include <gslib.h>
#include  "Shape.h"

class Renderer;
/*
OBB
*/
class OBB:public Shape
{
public:
	OBB(const GSvector3 &_position,const GSvector3& _radius, const GSvector3& _rotate);
	~OBB();
	const bool isCollision(const Sphere* _sphere)const;
	const bool isCollision(const Capsule* _capsule)const;
	const bool isCollision(const Segment* _segment)const;
	const bool isCollision(const OBB* _obb)const;

	const bool isCollision(const Shape* _shape)const;
	void draw(const Renderer & renderer, const GScolor& color=GScolor(1,1,1,1));

	const bool isCollisionSphere(const GSvector3& _center, float _radius)const;
	
	//���肪�ɂ����ǎ�肠��������(+���g�����t�@�N�^�Ώ�)
	const bool isCollisionSegment(const GSvector3& _begin, const GSvector3& _vector)const;
	const bool isCollisionCapsule(const GSvector3& _position, const GSvector3 &_vector, float _radius)const;
private:
	// �e���ɂ��Ă͂ݏo�������̃x�N�g�����Z�o
	const GSvector3 axisProtrudedVector(const GSvector3& _axis,float radius,const GSvector3& _point)const;

	//�_�Ƃ̍ŒZ����
 	const float distance_point(const GSvector3 &_point)const;

	//Axis�̔�r
	const bool axisCompare(const OBB* _other, const GSvector3 & _distance)const;
	//���g��Axis�Ɣ�r
	const bool selfAxisCompare(const OBB* _other, const GSvector3 & _distance)const;
	//�����Axis�Ɣ�r
	const bool otherAxisCompare(const OBB* _other, const GSvector3 & _distance)const;
	// ���������m�̊O�ς��r
	const bool crossAxisCompare(const OBB* _other, const GSvector3 & _distance)const;
	// ��]�p�x���番���������߂�(��]���ƃR���X�g���N�^�ŋ��߂�)
	void rotateToAxis();

	//OBB�̓��e������r
	const bool compareLengthOBB(const OBB *_other, const GSvector3 vSep, const GSvector3 vDistance)const;
	//��������ōł��������_�܂ł̋���
	const float farthestDistance(const GSvector3& _vSeq)const;


	//slab�Ɛ��������s���ǂ����𔻒肵�������邩�m�F
	const bool parallel_Slab_Segment(float _radius, float _dir, float _pos)const;
	//�e�X���u�Ő����ƌ������邩
	const bool each_Slab_Segment(const GSvector3& _radius,const GSvector3& _dir, const GSvector3& _pos, const GSvector3& _axis)const;
private:
	GSvector3 m_radius;//���a
	GSvector3 m_position;//���S�ʒu
	GSvector3 m_rotate;    // ��]�p�x

	GSvector3 m_axisX;  // ������X
	GSvector3 m_axisY;  // ������Y
	GSvector3 m_axisZ;  // ������Z
};
#endif

