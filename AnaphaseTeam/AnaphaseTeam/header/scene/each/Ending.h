#ifndef _ENDING_H_
#define _ENDING_H_
#include "../IScene.h"
#include "../SceneChange.h"
class Input;
class Ending :public IScene
{
public:
	Ending(const Input* _input);
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
	const Input* m_Input;
	SceneChange m_change;
};
#endif