#pragma once
#include "scene\IScene.h"
#include "../SceneChange.h"
#include "../header/ui/Flash.h"

class GameOver : public IScene
{
public:
	GameOver();
	~GameOver();
	void initialize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
	void count();
private:
	void change();
private:
	SceneChange m_change;
	Flash m_pressKey;
};