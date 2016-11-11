#pragma once
#include "CollisionActor.h"
#include "../transform/Transform.h"
//***�@�\�m�F�p
#include <string>
//**
class WeaponCollision:public CollisionActor
{
public:
	WeaponCollision(Transform* _transform);
	~WeaponCollision();
private:
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;

	//�ȉ��ꎞ�I�ȃe�X�g�p
	void doDraw(const Renderer& _renderer)override;
	void collision_Stay(HitInformation& _hit)override;
	void collision_Exit(HitInformation& _hit)override;
private:
	Transform* m_transform;
	//****
	std::string m_text;
};