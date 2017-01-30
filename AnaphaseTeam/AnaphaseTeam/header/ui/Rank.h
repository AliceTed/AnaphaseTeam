#pragma once
#include "../renderer/IRenderer.h"
#include "data/id/TEXTURE_ID.h"
#include "convenient/Timer.h"
#include <gslib.h>

class Rank
{
	enum class RANK : int
	{
		S = 100,
		A = 80,
		B = 50,
		C = 30,
		D = 0,
	};

public:
	Rank();
	~Rank();
	void initilize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	void calc_Rank(int _score);
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