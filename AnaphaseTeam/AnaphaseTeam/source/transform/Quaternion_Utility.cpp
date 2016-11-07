#include "../../header/transform/Quaternion_Utility.h"

Quaternion_Utility::Quaternion_Utility()
{
}

Quaternion_Utility::~Quaternion_Utility()
{
}
const GSquaternion Quaternion_Utility::conjugate(const GSquaternion & _q)const
{
	return GSquaternion(-_q.x, -_q.y, -_q.z, _q.w);
}

const GSvector3 Quaternion_Utility::rotation(const GSquaternion & _q, const GSvector3 & _vec)const
{
	GSquaternion q_con(conjugate(_q));
	//GSquaternion q_con(_q);
	GSquaternion q_vec(_vec.x, _vec.y, _vec.z, 1.0f);
	GSquaternion q = _q*q_vec*q_con;
	return GSvector3(q.x, q.y, q.z);
}
