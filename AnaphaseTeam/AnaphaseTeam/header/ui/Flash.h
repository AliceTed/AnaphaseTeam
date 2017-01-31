#pragma once
#include "../data/id/TEXTURE_ID.h"
#include "../renderer/Renderer.h"
class Flash
{
public:
	struct Param
	{
		float speed;
		float alpha;
		int sign;
		Param()
			:speed(1.0f),
			alpha(1.0f),
			sign(1)
		{
		}
		Param(float _speed, float _alpha = 1.0f, int _sign = 1)
			:speed(_speed),
			alpha(_alpha),
			sign(_sign)
		{
		}
	};
public:
	Flash(TEXTURE_ID _ID, const GSvector2& _position, const Param& _param);
	~Flash();
	void initilize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);

private:
	TEXTURE_ID m_textureID;
	GSvector2 m_position;
	Param m_param;
	const Param m_initparam;
};
