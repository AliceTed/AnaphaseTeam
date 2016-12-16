#pragma once
#include <gslib.h>
#include "../math/TargetLerp.h"

#include "../transform/Transform.h"
#include "../convenient/Timer.h"
class KnockBack
{
public:
	KnockBack(Transform & _transform);
	~KnockBack()=default;
	void start(const GSvector3& blowOff);
	void update(float deltaTime);
	const bool isBlow()const;
private:
	Transform& m_transform;
	GSvector3 m_current;
	Math::TargetLerp<GSvector3> m_lerp;
	GSvector3 m_blowOff;
	bool m_blowAway;
	Timer m_timer;

	//‰¼
	float m_easing;
};