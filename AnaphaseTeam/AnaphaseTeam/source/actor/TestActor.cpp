#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/math/Calculate.h"

#include "../../header/actor/Player/Player.h"
#include "../../header/camera/CameraController.h"
//
TestActor::TestActor()
	:Actor(
		Transform(GSvector3(0,0,0),GSvector3(0,180,0)),
		MODEL_ID::BOSS,
		Sphere(GSvector3(0, 7, 0), 7.0f),
		Actor_Tag::TEST
		),
	m_points(),
	m_core(GSvector3(0,0,0),1),
	m_corecolor(1,1,1,1),
	m_group(std::make_shared<CollisionGroup>(this))
{
	
}

TestActor::~TestActor()
{
}

void TestActor::initialize()
{
	Actor::initialize();
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true);
	m_points.clear();
	createPoint();
	m_corecolor = GScolor(1, 1, 1, 1);
	std::for_each(m_points.begin(), m_points.end(), [&](BreakPoint& _point) {_point.createCollision(this,m_group);});
}

void TestActor::update(float deltatime)
{
	std::vector<GSvector3> pos = getAnimEachPos();
	//m_animatorOne.update(deltatime);
	m_core.transfer(pos.at(static_cast<unsigned int>(Element::HEAD)));
	std::for_each(m_points.begin(), m_points.end(), [&](BreakPoint& _point){_point.update(deltatime,pos);});
}

void TestActor::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	//alphaBlend(_camera);release時になぜか透明になる
	_renderer.getDraw3D().drawMesh(MODEL_ID::BOSS, m_transform, m_animatorOne, m_Color);
	std::for_each(m_points.begin(), m_points.end(), [&](BreakPoint& _point) {_point.draw(_renderer);});
	m_core.draw(_renderer, m_corecolor);
}

void TestActor::look_at(CameraController * _camera, Player * _actor)
{
	GSvector3 target = m_transform.getPosition();
	_actor->look_at(_camera,&target);
}

void TestActor::addCollisionGroup(TestCollisionManager * _manager)
{
	_manager->add(m_group);
}

void TestActor::createPoint()
{
	std::vector<GSvector3> pos = getAnimEachPos();
	m_points.emplace_back(CollisionActorType::ENEMY_LEFT,Element::LEFT_LEG);
	m_points.emplace_back(CollisionActorType::ENEMY_RIGHT, Element::RIGHT_LEG);

	m_core.transfer(pos.at(static_cast<GSuint>(Element::HEAD)));
}
std::vector<GSvector3> TestActor::getAnimEachPos()
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
	std::vector<GSvector3> res;
	for (GSuint i = 0; i < n; i++)
	{
		Transform transform(mat[i]);
		GSmatrix4 m =transform.parentSynthesis(m_transform);
		res.emplace_back(m.getPosition());
	}
	delete[] pmat;
	delete[] mat;
	delete[] animmat;
	return res;
}