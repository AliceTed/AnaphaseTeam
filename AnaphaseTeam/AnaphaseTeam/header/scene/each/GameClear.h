#pragma once
#include "../IScene.h"
class Input;
class GameClear : public IScene
{
public:
	GameClear(const Input* _input);
	~GameClear();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	bool m_IsEnd;
	const Input* m_Input;
};