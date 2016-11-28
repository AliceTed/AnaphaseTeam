#include "../../header/attack/Scythe.h"

#include "../../header/animation/AnimatorOne.h"
#include "../../header/renderer/Renderer.h"
#include "../../header/collision/CollisionGroup.h"
Scythe::Scythe()
	:m_bone(14),//14は右手の配列番号
	m_local(
		140.8678508f, GSvector3(0.642011f, -0.639324f, -0.42319f),//初期位置(調整)
		GSvector3(0.092351f, 0.009981f, -0.177121f)),
	m_world()
{}
Scythe::~Scythe()
{}

void Scythe::initialize()
{
}
void Scythe::update(float deltaTime, const AnimatorOne & _animator, const Transform & _parent)
{
	Transform right = _animator.getOrientedMat(m_bone);
	Transform world_right = right.parent_synthesis(_parent);
	m_world = m_local.parent_synthesis(world_right);
}

void Scythe::draw(const Renderer & _renderer)
{
	_renderer.getDraw3D().drawMesh(static_cast<GSuint>(MESH_ID::WEAPON), m_world);
}
