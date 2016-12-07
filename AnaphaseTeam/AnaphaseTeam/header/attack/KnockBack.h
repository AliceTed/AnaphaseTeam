#pragma once
#include <gslib.h>
#include "../math/TargetLerp.h"
#include "../transform/Transform.h"
class KnockBack
{
public:
	KnockBack(Transform & _transform);
	~KnockBack()=default;
	void start(const GSvector3& blowOff);
	void update(float deltaTime);
private:
	Transform& m_transform;
	GSvector3 m_current;
	Math::TargetLerp<GSvector3> m_lerp;
};