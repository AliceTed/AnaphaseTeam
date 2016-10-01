#pragma once
#include "../SceneChange.h"
#include "../IScene.h"
class Input;
class Option :public IScene
{
public:
	Option(Input* _input);
	~Option();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	Input* m_input;
	SceneChange m_change;
};
