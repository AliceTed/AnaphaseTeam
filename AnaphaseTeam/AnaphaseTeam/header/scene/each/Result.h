#pragma once
#include "../SceneChange.h"
#include "../IScene.h"
#include "../../ui/Number.h"
#include "../../ui/ResultManager.h"
#include "../../scene/each/GamePlay.h"

class Result : public IScene
{
public:
	Result();
	~Result();
	void initialize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	void finish();
	const SceneMode next() const;
	const bool isEnd() const;
	const bool isExit() const;
private:
	SceneChange m_change;
	Number m_number;
	ResultManager m_manager;
	GamePlay m;

};
