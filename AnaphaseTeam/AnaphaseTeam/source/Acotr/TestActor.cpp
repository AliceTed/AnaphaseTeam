#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"
//
int TestActor::DrawCount = 0;
TestActor::TestActor()
	:Actor(Transform(),Sphere(GSvector3(0,0,0),1.0f)),
	target(0, 0, 0),
	animation(ANIMATION_ID::KARATE,SKELETON_ID::KARATE,20,
		AnimationTimer
		(
			gsGetEndAnimationTime(static_cast<GSuint>(ANIMATION_ID::KARATE),20)),true
		)
{
	DrawCount = 0;
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
	//
	DrawCount = 0;
}

void TestActor::draw(const Renderer & _renderer, const Camera & _camera)
{
	if (!isInsideView(_camera))
	{
		return;
	}
	//
	DrawCount++;
	
	alphaBlend(_camera);
	animation.bind();
	_renderer.getDraw3D().drawMesh(MESH_ID::KARATE,m_transform,m_Color);
	//sphereDraw(_renderer);
}
