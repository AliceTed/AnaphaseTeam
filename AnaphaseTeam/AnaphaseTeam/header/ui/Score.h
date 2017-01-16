#pragma once
#include "../../header/renderer/IRenderer.h"
#include "../../header/ui/IPlayUI.h"
#include "Number.h"

#include <vector>

class Score : public IPlayUI
{
public:
	Score();
	~Score();
	void initialize();
	void add(int _score);
	void update(float deltaTime);
	void hit();
	void timerSet();
	void timerStart();
	void timer(bool _start);
	void feverTime(int _limit, int _score, int _double);
	void reset();
	void draw(IRenderer* _renderer);
	void record(int _score);
	int total();

private:
	Number m_number;
	GSvector2 m_position;
	int m_score;
	int m_total;
	float m_timer;
	bool m_hit;
	std::vector<int> m_current;
	
	
};
