#pragma once
#include "SelectUI.h"
#include "Cursor.h"
class SceneChange;
class Input;
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
	void logoFade(Title& _title);
private:
	SelectUI m_select;
	SelectCursor m_cursor;
	float m_alpha;
	GameDevice* m_device;
};

