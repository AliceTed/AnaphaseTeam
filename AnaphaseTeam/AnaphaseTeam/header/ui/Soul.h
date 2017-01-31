#pragma once
#include <gslib.h>
#include "../data/id/TEXTURE_ID.h"
#include "../renderer/IRenderer.h"
#include "math/TimeLerpVector.h"
class Soul
{
public:
	Soul(const GSvector2 & _position, const GSvector2 & _target,int _lerpTime);
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	bool isDead() const;
private:
	Math::TimeLerpVector<GSvector2> m_lerp;
};