#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/collision/CollisionMediator.h"
#include "../../header/shape/Sphere.h"

#include "../../header/attack/AttackStatus.h"

#include "../../header/actor/Player/Player.h"
//
TestActor::TestActor()
	:Actor(
		Transform(GSvector3(0,0,0), GSvector3(0, 0, 0), GSvector3(1.5f,1.5f,1.5f)),
		MODEL_ID::BOSS, 
		Sphere(GSvector3(0,5, 0),10.0f), 
		Actor_Tag::TEST)
{
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true);
}

TestActor::~TestActor()
{
}

void TestActor::update(float deltatime)
{
	sphereChases(GSvector3(0,10, 0));
}

void TestActor::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	_renderer.getDraw3D().drawMesh(MODEL_ID::BOSS, m_transform,m_animatorOne, m_Color);
}