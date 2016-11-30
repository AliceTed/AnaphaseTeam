#pragma once

#include "SceneMode.h"
#include "../ui/Fade.h"
class SceneChange
{
public:
	SceneChange();
	~SceneChange();
	void initialize();
	const bool update(float deltaTime);
	void draw(IRenderer * _renderer);
	void begin(float _fadetime=1.0f);
	void end(SceneMode _next,float _fadetime = 1.0f);
	const SceneMode next()const;
	const bool isEnd()const;
private:
	bool m_isEnd;
	SceneMode m_next;
	Fade m_Fade;
};
