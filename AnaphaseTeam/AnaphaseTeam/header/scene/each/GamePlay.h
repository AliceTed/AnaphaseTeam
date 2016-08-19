#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_
#include "../IScene.h"
#include "../../actor/Player/Player.h"
#include <memory>
class Input;
class GamePlay :public IScene
{
public:
	GamePlay(const Input* _input);
	~GamePlay();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
private:
	bool m_IsEnd;
	const Input* m_Input;
	Player m_player;
};
#endif