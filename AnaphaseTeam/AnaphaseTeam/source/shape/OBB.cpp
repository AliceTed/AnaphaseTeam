//#include "OBB.h"
//
//#include "Renderer3D.h"
//
//
//OBB::OBB(GSvector3 pos, GSvector3 radius, GSvector3 rot)
//	:position(pos), radius(radius), rot(rot),
//	axisX(GSvector3(1, 0, 0)), axisY(GSvector3(0, 1, 0)), axisZ(GSvector3(0, 0, 1))
//{
//	rotToAxis();
//}
//OBB::~OBB() {}
//
//void OBB::expand(const GSvector3& _radius)
//{
//	radius += _radius;
//}
//void OBB::translate(const GSvector3 & _position)
//{
//	position += _position;
//}
//void OBB::transfer(const GSvector3 & _position)
//{
//	position = _position;
//}
//void OBB::rotate(GSvector3 _rot)
//{
//	rot += _rot;
//	rotToAxis();
//}
//
///*���܂藝�����Ă��Ȃ�*/
//const bool OBB::intersects(const OBB& other)const
//{
//	// ���S�Ԃ̋����x�N�g���Z�o
//	GSvector3 vDistance = other.position - position;
//
//	const std::vector<GSvector3> myAxis = { axisX,axisY,axisZ };
//	const  std::vector<GSvector3> otherAxis = { other.axisX,other.axisY,other.axisZ };
//
//	// ���������r
//	if (compareAxis(other, myAxis, vDistance))return false;
//	if (compareAxis(other, otherAxis, vDistance))return false;
//
//
//	// ���������m�̊O�ς��r
//	std::vector<GSvector3> crossAxis;
//	for (unsigned int i = 0; i < myAxis.size(); i++)
//	{
//		for (unsigned int j = 0; j < otherAxis.size(); j++)
//		{
//			crossAxis.emplace_back(myAxis[i].cross(otherAxis[j]));
//		}
//	}
//	if (compareAxis(other,crossAxis, vDistance))return false;
//	return true;
//}
//void OBB::draw(const Renderer3D& renderer)
//{
//	renderer.drawBox(&position, &radius, &rot);
//}
//const SHAPETYPE OBB::getType() const
//{
//	return SHAPETYPE::OBB;
//}
//const GSvector3 OBB::overVector(const GSvector3 & position, const GSvector3 & dir, const GSvector3 & point, float L) const
//{
//	if (L <= 0) return GSvector3(0, 0, 0);  // L=0�͌v�Z�ł��Ȃ�
//
//	float s = gsVector3Dot(&(point - position), &dir) / L;
//
//	// s�̒l����A�͂ݏo��������������΂��̃x�N�g����Ԃ�
//	s = fabs(s);
//	if (s > 1)
//	{
//		return (1 - s)*L* dir;   // �͂ݏo���������̃x�N�g���Z�o
//	}
//
//	return GSvector3(0, 0, 0);
//}
//const float OBB::point_distance(const GSvector3 & point) const
//{
//	GSvector3 v(0, 0, 0);   // �ŏI�I�ɒ��������߂�x�N�g��
//
//	v = overVector(position, axisX, point, radius.x);
//	v += overVector(position, axisY, point, radius.y);
//	v += overVector(position, axisZ, point, radius.z);
//
//	return v.length();   // �������o��
//}
//const bool OBB::compareAxis(const OBB & other, const std::vector<GSvector3> axis, const GSvector3& distance) const
//{
//	for each (GSvector3 _axis in axis)
//	{
//		if (!compareLengthOBB(other, _axis, distance)) return false;
//	}
//	return false;
//}
//const bool OBB::compareLengthOBB(const OBB& othre, const GSvector3& vSep, const GSvector3& vDistance)const
//{
//	// ���������A����B�̋���
//	float length = fabsf(vSep.dot(vDistance));
//
//	// ���������A����ł�����A�̒��_�܂ł̋���
//	float lenA =
//		fabsf(axisX.dot(vSep)*radius.x)
//		+ fabsf(axisY.dot(vSep)*radius.y)
//		+ fabsf(axisZ.dot(vSep)*radius.z);
//
//	// ���������B����ł�����B�̒��_�܂ł̋���
//	float lenB =
//		fabsf(othre.axisX.dot(vSep)*othre.radius.x)
//		+ fabsf(othre.axisY.dot(vSep)*othre.radius.y)
//		+ fabsf(othre.axisZ.dot(vSep)*othre.radius.z);
//	if (length > lenA + lenB)
//	{
//		return false;
//	}
//	return true;
//}
//// ���������X�V
//void OBB::rotToAxis()
//{
//	GSmatrix4 mRot;
//	gsMatrix4YawPitchRoll(&mRot, rot.y, rot.x, rot.z);
//
//	axisX = mRot.getAxisX();
//	axisY = mRot.getAxisY();
//	axisZ = mRot.getAxisZ();
//}