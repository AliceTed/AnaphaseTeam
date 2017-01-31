#pragma once
#include "renderer/IRenderer.h"
#include "ui/MoveText.h"
#include "convenient/Timer.h"

#include <vector>

class StaffRollUI
{
public:
	StaffRollUI();
	~StaffRollUI();
	void initilize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	void push();
	bool isEnd()const;
private:
	void read();
	void createText();
	void remove();
private:
	using WordConteiner = std::vector<std::string>;
	WordConteiner m_words;
	using TextConteiner = std::vector<MoveText>;
	TextConteiner m_texts;

	Timer m_timer;
	int m_count;
};