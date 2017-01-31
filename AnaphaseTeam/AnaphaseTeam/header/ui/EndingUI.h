#pragma once
#include "../renderer/Renderer.h"
#include "../ui/Flash.h"
#include "../ui/StaffRollUI.h"
class EndingUI
{
public:
	EndingUI();
	~EndingUI();
	void initilize();
	void update(float deltatime);
	void draw(IRenderer* _renderer);
private:
	GSvector3 m_position;
	Flash m_credit;
	Flash m_still;
	StaffRollUI m_staffRoll;
};
