#pragma once
#include <gslib.h>
#include "../transform/Transform.h"
class CollisionActor;
class AttackIncidence
{
public:
	AttackIncidence(const Transform& _local=Transform());
	~AttackIncidence()=default;

	void setWorldTransform(const Transform& _transform);
	void synthesisWorldTransform(const Transform& _parent);
	//world��local���������ʒu�������o���Ă���
	const GSvector3 point()const;
private:
	Transform m_local;
	Transform m_world;
};