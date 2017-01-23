#pragma once
#include "../renderer/IRenderer.h"
class ResultManager
{
public:
	ResultManager();
	~ResultManager();
	void initilize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
private:
	int m_num;
	int m_score;

};