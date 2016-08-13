#include "../../header/renderer/Draw3D.h"
#include "../../header/data/CastID.h"
Draw3D::Draw3D()
{
}

Draw3D::~Draw3D()
{
}

void Draw3D::drawMesh(
	MESH_ID id,
	const GSvector3 * _position,
	const GSvector3 * _scaling,
	const GSvector3 * axis,
	float direction)const
{
	glPushMatrix();
	if (_position != NULL)
	{
		glTranslatef(_position->x, _position->y, _position->z);
	}

	if (axis != NULL)
	{
		glRotatef(direction, axis->x, axis->y, axis->z);
	}
	else
	{
		glRotatef(direction, 0.0f, 1.0f, 0.0f);
	}

	if (_scaling != NULL)
	{
		glScalef(_scaling->x, _scaling->y, _scaling->z);
	}
	Data::CastID cast;
	gsDrawMesh(cast(id));
	glPopMatrix();
}

void Draw3D::drawMesh(MESH_ID id, const GSmatrix4 & mat) const
{
	glPushMatrix();
	glMultMatrixf(mat);
	Data::CastID cast;
	gsDrawMesh(cast(id));
	glPopMatrix();
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
	glMaterialfv(GL_FRONT, GL_DIFFUSE,color);
	glutSolidCube(1);

	glPopMatrix();
}

void Draw3D::drawSphere(const GSvector3 * pos, float radius, const GScolor & color) const
{
	glPushMatrix();
	glTranslated(pos->x, pos->y, pos->z);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,color);
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