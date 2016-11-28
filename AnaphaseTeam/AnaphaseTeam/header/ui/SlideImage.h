#pragma once
#include <gslib.h>
#include "../../header/math/TimeLerpVector.h"
enum class MODE
{
	NORMAL,
	REVERSE
};
#include "../data/TEXTURE_ID.h"
class Renderer;
class SlideImage
{
public:
	SlideImage(TEXTURE_ID _id,const GSvector2& _begin,const GSvector2& _end);
	~SlideImage();
	void slide(float _time=1.0f,MODE _mode=MODE::NORMAL);
	void update(float deltaTime);
	void draw(const Renderer& _renderer);
private:
	GSvector2 m_begin;
	GSvector2 m_end;
	TEXTURE_ID m_id;
	Math::TimeLerpVector<GSvector2> m_lerp;
};