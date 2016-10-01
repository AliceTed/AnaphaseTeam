#pragma once
#include "../SceneChange.h"
#include "../IScene.h"
class GameDevice;
class Option :public IScene
{
public:
	Option(GameDevice* _device);
	~Option();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	GameDevice* m_device;
	SceneChange m_change;
};
