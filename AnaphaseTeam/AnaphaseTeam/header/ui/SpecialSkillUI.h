#pragma once
#include "../specialskill/SPECIALSKILL_TYPE.h"
class IRenderer;
class SpecialSkillUI
{
public:
	SpecialSkillUI();
	~SpecialSkillUI()=default;

	void start();
	void select(SPECIALSKILL_TYPE _type);
	void update(float deltaTime);
	void draw(IRenderer* _renderer);
private:

};