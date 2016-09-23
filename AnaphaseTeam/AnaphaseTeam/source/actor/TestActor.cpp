#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/math/Calculate.h"
//
TestActor::TestActor()
	:Actor(
		Transform(),
		MODEL_ID::BOSS, 
		Sphere(GSvector3(0,0, 0),7.0f), 
		Actor_Tag::TEST),
	sphs()
{
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true);
}

TestActor::~TestActor()
{
}

void TestActor::update(float deltatime)
{
	getSphere();
	sphereChases(GSvector3(0,7, 0));
}

void TestActor::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	_renderer.getDraw3D().drawMesh(MODEL_ID::BOSS, m_transform, m_animatorOne, m_Color);
	for each (auto sph in sphs){sph.draw(_renderer);}
	_renderer.getDraw2D().string(std::to_string(dead), &GSvector2(10, 10), 20);
}

void TestActor::othercollision(Actor * _other)
{
	_other->othercollision(this);
}

void TestActor::collision(Player * _other)
{
	dead = 1;
}

void TestActor::getSphere()
{
	sphs.clear();
	std::vector<GSmatrix4> mat = getAnimEachPos();

	sphs.emplace_back(Sphere(getPos(mat, HEAD),2.0f));
	sphs.emplace_back(Sphere(getPos(mat, LEFTLEG),2.0f));
	sphs.emplace_back(Sphere(getPos(mat, RIGHTLEG),2.0f));
}

std::vector<GSmatrix4> TestActor::getAnimEachPos()
{
	const GSuint n = gsGetSkeletonNumBones(static_cast<GSuint>(MODEL_ID::BOSS));
	GSmatrix4 *pmat = new GSmatrix4[n],
		*mat = new GSmatrix4[n],
		*animmat = new GSmatrix4[n];
	for (GSuint i = 0; i < n; i++)
	{
		pmat[i] = GS_MATRIX4_IDENTITY;
	}
	gsCalculateAnimation(
		static_cast<GSuint>(MODEL_ID::BOSS),
		static_cast<GSuint>(ANIMATION_ID::STAND),
		0, animmat);

	gsCalculateSkeleton(pmat, animmat, mat);
	std::vector<GSmatrix4> res;
	for (int i = 0; i <n; i++)
	{
		res.emplace_back(mat[i]);
	}
	delete[] pmat;
	delete[] mat;
	delete[] animmat;
	return res;
}

GSvector3 TestActor::getPos(std::vector<GSmatrix4>& _mat, int index)
{
	Transform t(_mat[index]);
	GSmatrix4 m = t.parentSynthesis(m_transform);
	return m.getPosition();
}
