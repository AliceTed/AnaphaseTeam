#pragma once
#include<gslib.h>
class Quaternion_Utility
{
public:
	Quaternion_Utility();
	~Quaternion_Utility();

	//‹¤–ðGSquaternion
	const GSquaternion conjugate(const GSquaternion& _q)const;
	//ˆÊ’u‚âŽ²‚ð‰ñ“]
	const GSvector3 rotation(const GSquaternion& _q, const GSvector3& _vec)const;
};