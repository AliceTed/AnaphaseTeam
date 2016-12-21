#include "../../header/shape/Capsule.h"
#include "../../header/renderer/IRenderer.h"

#include "../../header/shape/Sphere.h"
#include "../../header/math/Calculate.h"
Capsule::Capsule(const Segment & _segment, float _radius)
	:m_Segment(_segment), m_Radius(_radius)
{
}

Capsule::~Capsule()
{
}

void Capsule::translate(const GSvector3 & _position)
{
	m_Segment.translate(_position);
}

void Capsule::transfer(const GSvector3 & _position)
{
	m_Segment.transfer(_position);
}

//const bool Capsule::isCollision(const Ray * _ray) const
//{
//	return false;
//}

const bool Capsule::isCollision(const Sphere * _sphere, GSvector3* _out) const
{
	return _sphere->isCollision(this, _out);
}

const bool Capsule::isCollision(const Capsule * _capsule, GSvector3* _out) const
{
	return gsCollisionCupsuleAndCupsule
	(
		&m_Segment.begin(), &m_Segment.end(), m_Radius,
		&_capsule->m_Segment.begin(), &_capsule->m_Segment.end(), _capsule->m_Radius
		, _out, NULL
	) == GS_TRUE;
}

const bool Capsule::isCollision(const Segment * _segment, GSvector3* _out) const
{
	return _segment->isCollisionCapsule(m_Segment, m_Radius, _out);
}

const bool Capsule::isCollision(const Shape * _shape, GSvector3* _out) const
{
	return _shape->isCollision(this, _out);
}
void Capsule::draw(IRenderer * renderer, const GScolor& color)
{
	/*GSvector3 v = m_Segment.vector();
	float ele = v.getPitch();

	Math::ATan aTan;
	float dir = aTan(v.x, v.z);

	GLUquadricObj *qobj;
	qobj = gluNewQuadric();

	glPushMatrix();
	GSvector3 pos = m_Segment.begin();
	glTranslatef(pos.x, pos.y, pos.z);

	glRotatef(dir, 0.0f, 1.0f, 0.0f);
	glRotatef(ele, 1.0f, 0.0f, 0.0f);
	glRotatef(ele, 0.0f, 0.0f, 1.0f);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluCylinder(qobj, m_Radius, m_Radius, v.length(), 20, 20);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glutSolidSphere(m_Radius, 20, 20);

	glTranslatef(0, 0, v.length());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glutSolidSphere(m_Radius, 20, 20);

	glPopMatrix();*/
}

const bool Capsule::isCollisionSphere(const GSvector3 & _center, float _radius, GSvector3* _out) const
{
	return m_Segment.isCollisionSphere(_center, _radius + m_Radius, _out);
}
