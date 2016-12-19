#pragma once
#include "Number.h"
class Score
{
public:
	Score();
	~Score();
	void initialize();
	void add(int _score);

	void update(float _deltaTime);
	void countStart();
	void Continuation();
	void reset();
	void draw(IRenderer* _renderer);

private:
	Number m_number;
	int m_score;
	float m_timer;

};
