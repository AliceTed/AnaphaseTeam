#pragma once
#include <gslib.h>
#include "../data/id/TEXTURE_ID.h"
#include "../renderer/IRenderer.h"
#include "math/TimeLerpVector.h"

class ResultUI
{
public:
	ResultUI(const GSvector2 & _position, const GSvector2 & _target, int _lerpTime);
	~ResultUI();
	void Initilize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	bool isDead() const;
private:
	Math::TimeLerpVector<GSvector2> m_lerp;
	GSvector2 m_position;
	GSvector2 m_target;
	int m_lerpTime;

};
