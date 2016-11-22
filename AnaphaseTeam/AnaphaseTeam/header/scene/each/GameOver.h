#pragma once
#include "../IScene.h"
#include "../SceneChange.h"
class Input;
class GameOver :public IScene
{
public:
	GameOver(const Input* _input);
	~GameOver();
	void initialize();
	void update(float _deltaTime);
	void draw(const Renderer& _renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	bool m_IsEnd;
	const Input* m_Input;
	SceneChange m_change;
};