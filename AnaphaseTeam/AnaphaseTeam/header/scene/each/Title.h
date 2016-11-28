#ifndef _TITLE_H_
#define _TITLE_H_
#include "../IScene.h"
#include "../../ui/TitleUI.h"
#include "../SceneChange.h"
class GameDevice;
class Title :public IScene
{
public:
	Title(GameDevice* _device);
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
	const bool isLogofade();
private:
	bool m_IsExit;
	SceneChange m_change;
	TitleUI m_title;
	GameDevice* m_device;
	bool m_isLogoFadeStart;
};
#endif