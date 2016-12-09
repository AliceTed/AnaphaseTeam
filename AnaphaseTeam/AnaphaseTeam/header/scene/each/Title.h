#ifndef _TITLE_H_
#define _TITLE_H_
#include "../IScene.h"
#include "../SceneChange.h"
#include "../../ui/alpha.h"


class Title :public IScene
{
public:
	Title();
	~Title();
	void initialize();
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	bool m_IsExit;
	SceneChange m_change;
	alpha m_pressKey;
};
#endif