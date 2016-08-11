#ifndef _TITLE_H_
#define _TITLE_H_
#include "../IScene.h"

class Title :public IScene
{
public:
	Title();
	~Title();
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