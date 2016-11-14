#pragma once
#include "CollisionActor.h"
#include "../transform/Transform.h"
//***機能確認用
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

	//以下一時的なテスト用
	void doDraw(const Renderer& _renderer)override;
	void collision_Stay(HitInformation& _hit)override;
	void collision_Exit(HitInformation& _hit)override;
private:
	Transform* m_transform;
	//****
	std::string m_text;
};