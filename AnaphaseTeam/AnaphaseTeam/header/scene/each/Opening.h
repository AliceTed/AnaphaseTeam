#pragma once
#include "../SceneChange.h"
#include "../IScene.h"
#include "../../math/TimeLerpVector.h"

class Opening:public IScene
{
public:
	Opening();
	~Opening();
	void initialize();
	void update(float deltaTime);
	void draw(IRenderer * renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	SceneChange m_change;
	Math::TimeLerpVector<GScolor> m_lerp;
 };