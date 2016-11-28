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
	void update(float deltaTime, Title& _title);
	void draw(const Renderer& _renderer);
	void finish();
private:
	void operation(Title& _title);
	void createSelect();
private:
	SelectUI m_select;
	GameDevice* m_device;
	Fade m_fade;
};

