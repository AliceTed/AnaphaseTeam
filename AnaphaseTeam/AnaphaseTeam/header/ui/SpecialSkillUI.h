#pragma once
#include <unordered_map>
#include"SkillUI.h"
#include "../specialskill/SPECIALSKILL_TYPE.h"
#include "../convenient/Timer.h"
class IRenderer;
class SpecialSkillUI
{
public:
	SpecialSkillUI(const GSvector2& _position);
	~SpecialSkillUI()=default;
	void initialize();
	void add(SPECIALSKILL_TYPE _type, const SkillUI & _skill);
	void open();
	void close();
	void select(SPECIALSKILL_TYPE _type);
	void update(float deltaTime);
	void draw(IRenderer* _renderer);
	const bool isOpen()const;
private:
	std::unordered_map<SPECIALSKILL_TYPE, SkillUI>m_conatiner;
	Timer m_retrovert;
	bool m_isSelect;
	bool m_isOpen;
	GSvector2 m_position;
};