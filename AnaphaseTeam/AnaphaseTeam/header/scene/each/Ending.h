#ifndef _ENDING_H_
#define _ENDING_H_
#include "../IScene.h"
#include "../SceneChange.h"

class Ending :public IScene
{
public:
	Ending();
	~Ending();
	void initialize();
	void update(float _deltaTime);
	void draw(const Renderer& _renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	bool m_IsEnd;
	SceneChange m_change;
};
#endif