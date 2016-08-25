#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"

int TestActor::DrawCount = 0;
TestActor::TestActor()
	:Actor(Transform(),ANIMATION_ID::KARATE, SKELETON_ID::KARATE,Sphere(GSvector3(0,0,0),1.0f)),
	target(0, 0, 0),
	m_animator(ANIMATION_ID::KARATE, SKELETON_ID::KARATE)
	/*animation(ANIMATION_ID::KARATE,SKELETON_ID::KARATE,20,
		AnimationTimer
		(
			gsGetEndAnimationTime(static_cast<GSuint>(ANIMATION_ID::KARATE),20)),true
		)*/
{
	DrawCount = 0;
	m_animator.addAnimation_A(PLAYERACTION_ID::STAND, true);
	m_animator.changeAnimation_A(PLAYERACTION_ID::STAND,false);
}

TestActor::~TestActor()
{
}

void TestActor::update(float deltatime)
{
	m_animator.update_A(deltatime);
	switch (rand() % 360)
	{
	case 0:
		target.x += 1;
		break;
	case 1:
		target.x -=1;
		break;
	case 2:
		target.z +=1;
		break;
	case 3:
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
	alphaBlend(_camera);
	m_animator.bind_A();
	_renderer.getDraw3D().drawMesh(MODEL_ID::KARATE,m_transform.getMatrix4(),m_Color);
	//sphereDraw(_renderer);
	//
	DrawCount++;
}
