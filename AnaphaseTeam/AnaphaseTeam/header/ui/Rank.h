#pragma once
#include "../renderer/IRenderer.h"
#include "data/id/TEXTURE_ID.h"
#include "convenient/Timer.h"
#include <gslib.h>

class Rank
{
	enum class RANK : int
	{
		S = 30,
		A = 20,
		B = 10,
		C = 5,
		D = 0,
	};

public:
	Rank();
	~Rank();
	void initilize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	void calc_Rank(int _score);
	bool isDead();
private:
	RANK calc(int _score)const;
	GSrect getCut()const;

private:
	float m_alpha;
	RANK m_rank;
	Timer m_timer;
	float m_add;
	bool m_isDraw;
};