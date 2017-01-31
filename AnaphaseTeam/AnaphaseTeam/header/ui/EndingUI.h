#pragma once
#include "../renderer/Renderer.h"
#include "../ui/alpha.h"
#include "../ui/StaffRollUI.h"
class EndingUI
{
public:
	EndingUI();
	~EndingUI();
	void initilize();
	void update(float _deltaTime);
	void draw(IRenderer* _renderer);
	void creditSkip();
	bool isNext();
private:
	GSvector3 m_position;
	bool m_change;
	int m_count;
	alpha m_still;
	StaffRollUI m_staffRoll;
};
