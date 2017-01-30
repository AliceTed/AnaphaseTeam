#pragma once
#include "../renderer/IRenderer.h"
#include "../ui/SoulManager.h"
#include "../ui/Rank.h"
#include "../convenient/Timer.h"

#include <vector>

class ResultManager
{
public:
	ResultManager();
	~ResultManager();
	void initilize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
private:
	void read();
	void create();
private:
	int m_scoreValue;
	SoulManager m_soul;
	Rank m_rank;
	Timer m_score;
	Timer m_createInterval;
	std::vector<GSvector2> m_soulPos;


};