#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_
#include "../IScene.h"
class GamePlay :public IScene
{
public:
	GamePlay();
	~GamePlay();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
private:
	bool m_IsEnd;

};
#endif