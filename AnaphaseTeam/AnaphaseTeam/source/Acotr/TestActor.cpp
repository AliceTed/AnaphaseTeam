#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"
TestActor::TestActor()
	:Actor(Transform(),Sphere(GSvector3(0,0,0),0.5f)), target(0, 0, 0)
{
}

TestActor::~TestActor()
{
}

void TestActor::update(float deltatime)
{
	switch (rand() % 360)
	{
	case 0:
		target.x += 1;
		break;
	case 1:
		target.x -=1;
		break;
	case 2:
		target.y += 1;
		break;
	case 3:
		target.y -=1;
		break;
	case 4:
		target.z +=1;
		break;
	case 5:
		target.z -=1;
		break;
	}

	m_transform.setPosition(m_transform.getPosition().lerp(target, deltatime*0.1f));

	m_Sphere.transfer(m_transform.getPosition());
}

void TestActor::draw(const Renderer & _renderer, const Camera & _camera)
{
	if (!isInsideView(_camera))
	{
		m_isDead = true;
		return;
	}
	alphaBlend(_camera);
	m_Sphere.draw(_renderer,color);
}
