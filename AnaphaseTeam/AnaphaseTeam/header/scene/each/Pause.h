#pragma once
/**
* @file Pause.h
* @brief É|Å[ÉYâÊñ 
* @author hisaaki
* @date 2016/12/05
*/
class IRenderer;
class SceneChange;
#include "../../ui/ScaleImage.h"
#include "../../ui/PauseUI.h"
#include <vector>
class Pause
{
public:
	Pause(SceneChange& _change);
	~Pause();
	void initialize();
	void update(float deltatime);
	void draw(IRenderer* _renderer);
	void finish();
	void select();
	void decision();
	bool isPause();
private:
	void clamp();
private:
	int m_currentSelect;
	bool m_isPause;
	PauseUI m_image;
	SceneChange& m_change;
};