#include "../../header/renderer/Draw3D.h"
#include "../../header/data/CastID.h"
#include "../../header/data/Model_ID.h"
#include"../../header/convenient/Transform.h"
#include "../../header/animation/Animator.h"
#include "../../header/animation/AnimatorOne.h"

Draw3D::Draw3D()
{
}

Draw3D::~Draw3D()
{
}

void Draw3D::drawMesh(MODEL_ID _id, const Transform & _transform, const AnimatorOne & _animator, const GScolor & _color) const
{
	glPushMatrix();
	_animator.bind();
	glColor4f(_color.r, _color.g, _color.b, _color.a);
	glMultMatrixf(_transform.getMatrix4());
	Data::CastID cast;
	gsDrawMesh(cast(_id));
	glPopMatrix();
}
void Draw3D::drawMesh_calcu(MODEL_ID _id, const Transform & _transform,GSmatrix4* _matrix,  AnimatorOne & _animator, const GScolor & _color) const
{
	Data::CastID cast;
	glPushMatrix();
	GSmatrix4* mat = new GSmatrix4[_animator.getNumBones()];
	_animator.matrixCalculate(mat);
	glColor4f(_color.r, _color.g, _color.b, _color.a);
	glMultMatrixf(_transform.getMatrix4());
	gsMeshDrawSkin(gsGetMesh(cast(_id)),mat);
	glPopMatrix();
	delete[] mat;
}
void Draw3D::drawSky(MESH_ID id, float angle)const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glRotatef(angle, 0.0f, 1.0f, 0.0f); /* y Ž²‰ñ“] */
	Data::CastID cast;
	gsDrawSkyBox(cast(id));
	glPopMatrix();
}
void Draw3D::drawSky(MESH_ID id)const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Data::CastID cast;
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	gsDrawSkyBox(cast(id));
}

void Draw3D::drawOctree(OCTREE_ID id)const
{
	Data::CastID cast;
	gsDrawOctree(cast(id));
}

void Draw3D::drawBox(const GSvector3 * pos, const GSvector3 * radius,
	const GSvector3 * rot, const GScolor & color)const
{
	glPushMatrix();
	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(rot->z, 0, 0, 1);
	glRotatef(rot->x, 1, 0, 0);
	glRotatef(rot->y, 0, 1, 0);

	glScaled(radius->x * 2, radius->y * 2, radius->z * 2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glutSolidCube(1);

	glPopMatrix();
}

void Draw3D::drawSphere(const GSvector3 * pos, float radius, const GScolor & color) const
{
	glPushMatrix();
	glTranslated(pos->x, pos->y, pos->z);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glutSolidSphere(radius, 20, 20);
	glPopMatrix();
}

void Draw3D::drawSphere(const GSmatrix4 & mat, float radius, const GScolor & color) const
{
	glPushMatrix();
	glMultMatrixf(mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glutSolidSphere(radius, 20, 20);
	glPopMatrix();
}

void Draw3D::drawCapsule(const GSvector3 * pos, float radius, float hight, float dir, float ele, const GScolor& color) const
{

	GLUquadricObj *qobj;
	qobj = gluNewQuadric();

	glPushMatrix();

	glTranslatef(pos->x, pos->y, pos->z);

	glRotatef(dir, 0.0f, 1.0f, 0.0f);
	glRotatef(ele, 1.0f, 0.0f, 0.0f);
	glRotatef(ele, 0.0f, 0.0f, 1.0f);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluCylinder(qobj, radius, radius, hight, 20, 20);

	drawSphere(&GSvector3(0, 0, 0), radius, color);
	drawSphere(&GSvector3(0, 0, hight), radius, color);

	glPopMatrix();
}

void Draw3D::drawLine(const GSvector3 * p1, const GSvector3 * p2, const GScolor& color, float size) const
{
	glPushMatrix();
	glLineWidth(size);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glBegin(GL_LINES);
	glVertex3f(p1->x, p1->y, p1->z);
	glVertex3f(p2->x, p2->y, p2->z);
	glEnd();

	glPopMatrix();
}

void Draw3D::drawPoint(const GSvector3 * p, float size, const GScolor& color) const
{
	glPushMatrix();
	glPointSize(size);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	
	glBegin(GL_POINTS);
	glVertex3f(p->x, p->y, p->z);
	glEnd();

	glPopMatrix();
}

void Draw3D::drawFog(const GSvector2 & clip, const GScolor & color) const
{
	glClearColor(color.r, color.g, color.b, color.a);
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, clip.x);
	glFogf(GL_FOG_END, clip.y);
	glFogfv(GL_FOG_COLOR, color);
}
