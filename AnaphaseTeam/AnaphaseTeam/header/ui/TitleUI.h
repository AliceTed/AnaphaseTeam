#pragma once
#include "SelectUI.h"
#include "Cursor.h"
class SceneChange;
class Input;
class Title;
class TitleUI
{
public:
	TitleUI();
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
	SelectCursor m_cursor;
};

