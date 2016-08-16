#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"
TestActor::TestActor()
	:Actor(Transform(),Sphere(GSvector3(0,0,0),1.0f)),
	target(0, 0, 0),
	animation(ANIMATION_ID::KARATE,SKELETON_ID::KARATE,0,
		AnimationTimer
		(
			gsGetEndAnimationTime(static_cast<GSuint>(ANIMATION_ID::KARATE),0)),true
		)
{
}

TestActor::~TestActor()
{
}

void TestActor::update(float deltatime)
{
	animation.update(deltatime);
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
	sphereChases(GSvector3(0, 1, 0));
}

void TestActor::draw(const Renderer & _renderer, const Camera & _camera)
{
	if (!isInsideView(_camera))
	{
		return;
	}
	alphaBlend(_camera);
	animation.bind();
	_renderer.getDraw3D().drawMesh(MESH_ID::KARATE,m_transform,color);
	debugSphereDraw(_renderer);
}
