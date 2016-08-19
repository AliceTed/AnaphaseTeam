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
///*あまり理解していない*/
//const bool OBB::intersects(const OBB& other)const
//{
//	// 中心間の距離ベクトル算出
//	GSvector3 vDistance = other.position - position;
//
//	const std::vector<GSvector3> myAxis = { axisX,axisY,axisZ };
//	const  std::vector<GSvector3> otherAxis = { other.axisX,other.axisY,other.axisZ };
//
//	// 分離軸を比較
//	if (compareAxis(other, myAxis, vDistance))return false;
//	if (compareAxis(other, otherAxis, vDistance))return false;
//
//
//	// 分離軸同士の外積を比較
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
//	if (L <= 0) return GSvector3(0, 0, 0);  // L=0は計算できない
//
//	float s = gsVector3Dot(&(point - position), &dir) / L;
//
//	// sの値から、はみ出した部分があればそのベクトルを返す
//	s = fabs(s);
//	if (s > 1)
//	{
//		return (1 - s)*L* dir;   // はみ出した部分のベクトル算出
//	}
//
//	return GSvector3(0, 0, 0);
//}
//const float OBB::point_distance(const GSvector3 & point) const
//{
//	GSvector3 v(0, 0, 0);   // 最終的に長さを求めるベクトル
//
//	v = overVector(position, axisX, point, radius.x);
//	v += overVector(position, axisY, point, radius.y);
//	v += overVector(position, axisZ, point, radius.z);
//
//	return v.length();   // 長さを出力
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
//	// 分離軸上のAからBの距離
//	float length = fabsf(vSep.dot(vDistance));
//
//	// 分離軸上でAから最も遠いAの頂点までの距離
//	float lenA =
//		fabsf(axisX.dot(vSep)*radius.x)
//		+ fabsf(axisY.dot(vSep)*radius.y)
//		+ fabsf(axisZ.dot(vSep)*radius.z);
//
//	// 分離軸上でBから最も遠いBの頂点までの距離
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
//// 分離軸を更新
//void OBB::rotToAxis()
//{
//	GSmatrix4 mRot;
//	gsMatrix4YawPitchRoll(&mRot, rot.y, rot.x, rot.z);
//
//	axisX = mRot.getAxisX();
//	axisY = mRot.getAxisY();
//	axisZ = mRot.getAxisZ();
//}