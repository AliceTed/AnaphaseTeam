#include "../../header/collision/WeaponCollision.h"
#include "../../header/shape/Sphere.h"
#include "../../header/collision/HitInformation.h"

//****
#include "../../header/renderer/Renderer.h"
WeaponCollision::WeaponCollision(Transform* _transform)
	:CollisionActor(new Sphere(GSvector3(0, 0, 0),0.3f),Collision_Tag::PLAYER_WEAPON),
	m_transform(_transform)
{
}
WeaponCollision::~WeaponCollision()
{
}

void WeaponCollision::doUpdate(float deltaTime)
{
	m_shape->transfer(m_transform->m_translate);
}

void WeaponCollision::collision_Enter(HitInformation & _hit)
{
}

void WeaponCollision::doDraw(const Renderer & _renderer)
{
	//m_shape->draw(_renderer);
	//_renderer.getDraw2D().string(m_text,&GSvector2(10,10),20);
}

void WeaponCollision::collision_Stay(HitInformation & _hit)
{
	//m_text = "Stay";
	if(gsGetKeyTrigger(GKEY_A))destroy();
}

void WeaponCollision::collision_Exit(HitInformation & _hit)
{
}
