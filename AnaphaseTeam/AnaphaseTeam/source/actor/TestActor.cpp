#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/collision/CollisionMediator.h"
#include "../../header/shape/Sphere.h"
//
int TestActor::DrawCount = 0;
TestActor::TestActor()
	:Actor(Transform(), MODEL_ID::KARATE, Sphere(GSvector3(0, 0, 0), 1.0f), Actor_Tag::TEST),
	target(0, 0, 0)
{
	DrawCount = 0;
	m_animator.addAnimation(ANIMATION_ID::STAND, true);
	m_animator.changeAnimation(ANIMATION_ID::STAND, false);
}

TestActor::~TestActor()
{
}

void TestActor::update(float deltatime)
{
	m_animator.update(deltatime);
	switch (rand() % 360)
	{
	case 0:
		target.x += 1;
		break;
	case 1:
		target.x -= 1;
		break;
	case 2:
		target.z += 1;
		break;
	case 3:
		target.z -= 1;
		break;
	}

	m_transform.setPosition(m_transform.getPosition().lerp(target, deltatime*0.1f));
	sphereChases(GSvector3(0, 1, 0));
	//
	DrawCount = 0;
}

void TestActor::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	m_animator.bind();
	_renderer.getDraw3D().drawMesh(MODEL_ID::KARATE, m_transform,m_animator, m_Color);
	//sphereDraw(_renderer);
	
	DrawCount++;
}

void TestActor::createCollision(CollisionMediator * _mediator)
{
	GSvector3 pos(m_transform.getPosition() + GSvector3(0, 0.5f, 0));
	Shape_Ptr shape = std::make_shared<Sphere>(pos, 1.0f);
	Obj_Ptr obj = std::make_shared<CollisionObject>(this, shape);
	_mediator->add(obj);
}

void TestActor::collision(const Actor * _other)
{
	if (_other->isSameTag(Actor_Tag::PLAYER))
		m_isDead = true;
}
