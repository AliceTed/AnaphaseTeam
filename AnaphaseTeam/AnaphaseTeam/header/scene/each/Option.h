#pragma once
#include "../SceneChange.h"
#include "../IScene.h"
#include "../../ui/SlideImage.h"
#include <vector>

class Option :public IScene
{
public:
	Option();
	~Option();
	void initialize();
	void update(float deltaTime);
	void slideStart(unsigned int _index);
	void draw(IRenderer * renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	SceneChange m_change;
	std::vector<SlideImage> m_image;
	float m_timer;
	bool m_slideStart[2];
};
