#pragma once
#include "../SceneChange.h"
#include "../IScene.h"
#include "../../math/TimeLerpVector.h"
class GameDevice;
class Opening:public IScene
{
public:
	Opening(GameDevice* _device);
	~Opening();
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
	Math::TimeLerpVector<GScolor> m_lerp;
 };