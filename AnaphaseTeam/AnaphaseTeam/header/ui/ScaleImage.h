#pragma once
#include <gslib.h>
#include "../data/id/TEXTURE_ID.h"
#include "../math/TimeLerpVector.h"
#include "../ui/alpha.h"
class IRenderer;
class ScaleImage
{
public:
	ScaleImage(TEXTURE_ID _id, const GSvector2& _position,bool _isPexis=true);
	~ScaleImage();
	void start(const GSvector2& _start, const GSvector2& _end, float _time);
	void moveStart(const GSvector2& _end, float _time);
	void update(float deltaTime);
	void draw(IRenderer* _renderer);
	void scroll();
	void alpha(float _timer);
	bool isEndscroll();
private:
	const GSvector2 getTextureSize()const;
	const GSvector2 getSizeMarge(const GSvector2& _scale)const;
private:
	TEXTURE_ID m_id;
	GSvector2 m_position;
	bool m_isPexis;
	Math::TimeLerpVector<GSvector2> m_scaleLerp;
	Math::TimeLerpVector<GSvector2> m_moveLerp;
	bool m_changeScroll;
	//alpha m_alpha;
	float m_alpha;
	float m_value;
	float m_speed;
};
