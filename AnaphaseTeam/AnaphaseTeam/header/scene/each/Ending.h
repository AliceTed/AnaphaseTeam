#ifndef _ENDING_H_
#define _ENDING_H_
#include "../IScene.h"
#include "../SceneChange.h"
class GameDevice;
class Ending :public IScene
{
public:
	Ending(GameDevice* _device);
	~Ending();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	bool m_IsEnd;
	GameDevice* m_device;
	SceneChange m_change;
};
#endif