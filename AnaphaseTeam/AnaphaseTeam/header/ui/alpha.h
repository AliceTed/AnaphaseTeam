#pragma once
#include "../data/id/TEXTURE_ID.h"
#include "../renderer/Renderer.h"
class alpha
{
public:
	alpha(TEXTURE_ID _ID, GSvector2 _position, float _alpha);
	~alpha();
	void initilize();
	void update();
	void draw(IRenderer * _renderer);
	void decrease(float _time);
	void increase(float _time);
	void flashing(float _time);
	bool scrollUp(float _position);
	bool scrollDown(float _position);

private:
	TEXTURE_ID m_textureID;
	GSvector2 m_position;
	GSvector2 m_currentPosition;
	float m_alpha;
	float m_currentAlpha;
	float m_value;
	bool m_change;
};
