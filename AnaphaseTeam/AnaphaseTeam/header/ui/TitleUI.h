#pragma once
#include "SelectUI.h"
#include "Fade.h"
class Title;
class TitleUI
{
public:
	TitleUI();
	~TitleUI();
	void initialize();
	void update(float deltaTime);
	void draw(IRenderer* _renderer);
	void finish();
	void operation(Title& _title);
private:
	void createSelect();
private:
	SelectUI m_select;
	Fade m_fade;
};

