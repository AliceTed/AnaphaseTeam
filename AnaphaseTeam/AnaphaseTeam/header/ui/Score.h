#pragma once
#include "../../header/renderer/IRenderer.h"
#include "../../header/ui/IPlayUI.h"
#include "Number.h"

class Score :public IPlayUI
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
	void feverTime(int _limit, int _score, int _double);
	void reset();
	void draw(IRenderer* _renderer);
private:
	Number m_number;
	GSvector2 m_position;
	int m_score;
	float m_timer;
	bool m_hit;
};
