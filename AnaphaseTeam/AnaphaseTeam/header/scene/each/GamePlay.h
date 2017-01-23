#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_
#include <memory>
#include "../IScene.h"
#include "../SceneChange.h"
#include "Pause.h" 
class Stage;
class GamePlay :public IScene
{
public:
	GamePlay();
	~GamePlay();
	void initialize();
	void update(float deltaTime);
	void draw(IRenderer * renderer);
	void finish();

	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;

private:
	void endingScene();
private:
	SceneChange m_change;
	Pause m_pause;
	using Stage_Ptr = std::unique_ptr<Stage>;
	Stage_Ptr m_stage;
};
#endif