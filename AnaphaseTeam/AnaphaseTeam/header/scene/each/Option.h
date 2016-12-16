#pragma once
#include "../SceneChange.h"
#include "../IScene.h"
#include "../../ui/SlideImage.h"
#include "../../ui/OptionUI.h"
#include "../../device/GameDevice.h"
#include <vector>
#include <unordered_map>

class Option :public IScene
{
public:
	Option();
	~Option();
	void initialize();
	void update(float deltaTime);
	void draw(IRenderer * _renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;


	void optionDecision(OPTION _option);
	void padDecision(PAD _pad);
	bool isChnage();

private:
	SceneChange m_change;
	//std::vector<SlideImage> m_image;
	OptionUI m_option;
	bool m_optionChange;
	bool m_padChange;

};
