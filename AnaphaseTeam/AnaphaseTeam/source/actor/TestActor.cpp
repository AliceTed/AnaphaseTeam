#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/math/Calculate.h"
#include "../../header/collision/CollisionMediator.h"

#include "../../header/actor/Player/Player.h"
#include "../../header/camera/CameraController.h"
//
TestActor::TestActor()
	:Actor(
		Transform(),
		MODEL_ID::BOSS,
		Sphere(GSvector3(0, 7, 0), 7.0f),
		Actor_Tag::TEST),
	m_points(),
	m_core(GSvector3(0,0,0),2),
	m_color(1,1,1,1)
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
}

void TestActor::update(float deltatime)
{
	std::vector<GSmatrix4> mat = getAnimEachPos();
	//m_animatorOne.update(deltatime);
	m_core.transfer(getPos(mat, HEAD));
	//eachUpdate(deltatime, CollisionType::ENEMY_HEAD, getPos(mat, HEAD));
	eachUpdate(deltatime, CollisionType::ENEMY_LEFT, getPos(mat,LEFTLEG));
	eachUpdate(deltatime, CollisionType::ENEMY_RIGHT, getPos(mat,RIGHTLEG));
}

void TestActor::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	_renderer.getDraw3D().drawMesh(MODEL_ID::BOSS, m_transform, m_animatorOne, m_Color);
	std::for_each(m_points.begin(), m_points.end(),
		[&](std::pair<const CollisionType, BreakPoint>& point)
	{
		point.second.draw(_renderer);
	});
	m_core.draw(_renderer, m_color);
}
void TestActor::createCollision(CollisionMediator * _mediator)
{
	Shape_Ptr shape = std::make_shared<Sphere>(m_core);
	Obj_Ptr obj = std::make_shared<CollisionObject>(this, shape, CollisionType::ENEMY_HEAD,
		[&](Actor* _parent, CollisionType _type)
	{
		if (std::all_of(m_points.begin(), m_points.end(), [&](std::pair<const CollisionType, BreakPoint>& point) { return point.second.isBreak(); }))
		{
			m_color = GScolor(0, 0, 1, 1);
		}
	});
	_mediator->add(obj);

	std::for_each(m_points.begin(), m_points.end(),
		[&](std::pair<const CollisionType, BreakPoint>& point) 
	{
		point.second.createCollision(this,_mediator); 
	});
}
void TestActor::look_at(CameraController * _camera, Player * _actor)
{
	GSvector3 target = m_transform.getPosition();
	_actor->look_at(_camera,&target);
}
void TestActor::add(const Sphere & _sphere, CollisionType _type)
{
	BreakPoint point(_sphere, _type);
	m_points.insert(std::make_pair(_type, point));
}
void TestActor::createPoint()
{
	std::vector<GSmatrix4> mat = getAnimEachPos();
	//add(Sphere(getPos(mat, HEAD), 2.0f), CollisionType::ENEMY_HEAD);
	add(Sphere(getPos(mat, LEFTLEG), 2.0f), CollisionType::ENEMY_LEFT);
	add(Sphere(getPos(mat, RIGHTLEG), 2.0f), CollisionType::ENEMY_RIGHT);

	m_core.transfer(getPos(mat, HEAD));
}

void TestActor::eachUpdate(float deltaTime, CollisionType _type, const GSvector3 & _position)
{
	m_points.at(_type).update(deltaTime, _position);
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
	for (int i = 0; i < n; i++)
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