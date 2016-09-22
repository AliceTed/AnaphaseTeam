#ifndef _TITLE_H_
#define _TITLE_H_
#include "../IScene.h"
#include "../../ui/TitleUI.h"
#include "../SceneChange.h"
class Input;
class Title :public IScene
{
public:
	Title(const Input* _input);
	~Title();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;

	void decision(Select _select);
	void select(SelectUI& _select);
private:
	bool m_IsExit;
	SceneChange m_change;
	TitleUI m_title;
	const Input* m_Input;
};
#endif