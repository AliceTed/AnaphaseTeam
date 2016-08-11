#ifndef _ENDING_H_
#define _ENDING_H_
#include "../IScene.h"
class Ending :public IScene
{
public:
	Ending();
	~Ending();
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