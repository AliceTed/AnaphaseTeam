#pragma once
#include<gslib.h>
class Quaternion_Utility
{
public:
	Quaternion_Utility();
	~Quaternion_Utility();

	//����GSquaternion
	const GSquaternion conjugate(const GSquaternion& _q)const;
	//�ʒu�⎲����]
	const GSvector3 rotation(const GSquaternion& _q, const GSvector3& _vec)const;
};