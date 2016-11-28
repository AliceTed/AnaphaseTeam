#pragma once
#include "SelectUI.h"
#include "Fade.h"
class Title;
class GameDevice;
class TitleUI
{
public:
	TitleUI(GameDevice* _device);
	~TitleUI();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& _renderer);
	void finish();
	void operation(Title& _title);
private:
	void createSelect();
private:
	SelectUI m_select;
	GameDevice* m_device;
	Fade m_fade;
};

