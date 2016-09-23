#include "../../header/actor/TestActor.h"
#include "../../header/shape/Sphere.h"
#include "../../header/camera/Camera.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/math/Calculate.h"
#include "../../header/collision/CollisionMediator.h"
//
TestActor::TestActor()
	:Actor(
		Transform(),
		MODEL_ID::BOSS,
		Sphere(GSvector3(0, 0, 0), 7.0f),
		Actor_Tag::TEST),
	sphs(),
	point()
{
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true);
	for (int i = 0; i < 3; i++)
	{
		point.emplace_back(false);
	}
}

TestActor::~TestActor()
{
}

void TestActor::update(float deltatime)
{
	getSphere();
	sphereChases(GSvector3(0, 7, 0));
}

void TestActor::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	_renderer.getDraw3D().drawMesh(MODEL_ID::BOSS, m_transform, m_animatorOne, m_Color);
	for (unsigned int i = 0; i < sphs.size(); i++)
	{
		GScolor c = point[i] ? GScolor(1, 0, 0, 1) : GScolor(1, 1, 1, 1);
		sphs[i].draw(_renderer, c);
	}
}
void TestActor::createCollision(CollisionMediator * _mediator)
{
	for (unsigned int i = 0; i < sphs.size(); i++)
	{
		createEachCollsion(_mediator, i);
	}
}

void TestActor::othercollision(CollisionType _myType, CollisionType _otherType, Actor * _other)
{
	_other->collision(_myType, _otherType, this);
}

void TestActor::collision(CollisionType _myType, CollisionType _otherType, Player * _other)
{
	if (_myType == CollisionType::ENEMY_HEAD)
	{
		if (point[1] && point[2])
		{
			point[0] = true;
		}
	}

	if (_myType == CollisionType::ENEMY_LEFT)
	{
		point[1] = true;
	}
	if (_myType == CollisionType::ENEMY_RIGHT)
	{
		point[2] = true;
	}
}

void TestActor::getSphere()
{
	sphs.clear();
	std::vector<GSmatrix4> mat = getAnimEachPos();

	sphs.emplace_back(Sphere(getPos(mat, HEAD), 2.0f));
	sphs.emplace_back(Sphere(getPos(mat, LEFTLEG), 2.0f));
	sphs.emplace_back(Sphere(getPos(mat, RIGHTLEG), 2.0f));
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

void TestActor::createEachCollsion(CollisionMediator * _mediator, unsigned int _index)
{
	CollisionType type[] =
	{
		CollisionType::ENEMY_HEAD,
		CollisionType::ENEMY_LEFT,
		CollisionType::ENEMY_RIGHT
	};

	Shape_Ptr shape = std::make_shared<Sphere>(sphs.at(_index));
	Obj_Ptr obj = std::make_shared<CollisionObject>(this, shape, type[_index]);
	_mediator->add(obj);
}
