#pragma once
#include "renderer/IRenderer.h"
#include "ui/MoveText.h"

#include <vector>

class StaffRollUI
{
public:
	StaffRollUI();
	~StaffRollUI();
	void initilize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
private:
	void read();
private:
	using WordConteiner = std::vector<std::string>;
	WordConteiner m_words;
	using TextConteiner = std::vector<MoveText>;
	TextConteiner m_texts;
};