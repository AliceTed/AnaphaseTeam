#include "../../header/attack/Scythe.h"

#include "../../header/animation/AnimatorOne.h"
#include "../../header/renderer/Renderer.h"
#include "../../header/collision/CollisionGroup.h"
#include "../../header/collision/WeaponCollision.h"
Scythe::Scythe()
	:m_bone(14),//14は右手の配列番号
	m_local(
		140.8678508f, GSvector3(0.642011f, -0.639324f, -0.42319f),//初期位置(調整)
		GSvector3(0.092351f, 0.009981f, -0.177121f)),
	m_world(),
	m_collision(GSvector3(0.0f, 1.2f, 0.3f), GSquaternion(0, 0, 0, 0))
{}
Scythe::~Scythe()
{}

void Scythe::initialize()
{
	//初期位置(調整)
	//m_local = Transform(76.345917f, GSvector3(0.987102f, 0.14814f, 0.06064f), GSvector3(-0.149978f, -0.104426f, -0.332818f));
	//m_world = Transform();
	//m_collision = Transform(GSvector3(0.0f, 1.2f, 0.4f), GSquaternion(0, 0, 0, 0));
}

void Scythe::addCollision(CollisionGroup* _group)
{
	//actor.set_update([=](float deltaTime, Shape* _shape) {_shape->transfer(m_collision.parent_synthesis(m_world).m_translate);});
	//actor.set_draw([](const Renderer& _renderer, Shape* _shape) {_shape->draw(_renderer);});
	Collision_Ptr actor = std::make_shared<WeaponCollision>(&m_collision_world);
	_group->add(actor);
}

void Scythe::update(float deltaTime, const AnimatorOne & _animator, const Transform & _parent)
{
	Transform right = _animator.getOrientedMat(m_bone);
	Transform world_right = right.parent_synthesis(_parent);
	m_world = m_local.parent_synthesis(world_right);
	m_collision_world = m_collision.parent_synthesis(m_world);
}

void Scythe::draw(const Renderer & _renderer)
{
	_renderer.getDraw3D().drawMesh(static_cast<GSuint>(MESH_ID::WEAPON), m_world);
}
