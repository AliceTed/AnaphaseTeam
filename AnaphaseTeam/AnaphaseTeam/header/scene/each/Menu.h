#pragma once
#include "../IScene.h"
#include "../../renderer/Renderer.h"
#include "../../ui/TitleUI.h"
#include "../SceneChange.h"
#include "../../ui/Score.h"
class Menu :public IScene
{
public:
	Menu();
	~Menu();
	void initialize();
	void update(float deltaTime);
	void draw(IRenderer * _renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;

	void decision(Select _select);
private:
	bool m_IsExit;
	MenuParticle m_menuParticle;
	SceneChange m_change;
	TitleUI m_menu;
};