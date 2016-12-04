#include "..\..\header\ui\SpecialSkillUI.h"
#include <algorithm>
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/renderer/IRenderer.h"
SpecialSkillUI::SpecialSkillUI(const GSvector2& _position)
	:m_position(_position),
	m_conatiner(),
	m_isOpen(),
	m_retrovert(0.3f),
	m_isSelect(false)
{
}

void SpecialSkillUI::initialize()
{
	m_isSelect=false;
	m_retrovert.initialize();
	add(SPECIALSKILL_TYPE::SPECIALLATTACK, SkillUI(TEXTURE_ID::SPECIAL_ATTACK, MYANIMATION_ID::SPECIAL_ATTACK_POP, MYANIMATION_ID::SPECIAL_ATTACK_BACK, GScolor(1, 0, 0, 1)));
	add(SPECIALSKILL_TYPE::SUPERARMOR, SkillUI(TEXTURE_ID::SPECIAL_SUPERARMOR, MYANIMATION_ID::SPECIAL_SUPERARMOR_POP, MYANIMATION_ID::SPECIAL_SUPERARMOR_BACK, GScolor(0,0, 1, 1)));
	add(SPECIALSKILL_TYPE::RECOVERY, SkillUI(TEXTURE_ID::SPECIAL_RECOVERY, MYANIMATION_ID::SPECIAL_RECOVERY_POP, MYANIMATION_ID::SPECIAL_RECOVERY_BACK, GScolor(0,1,0, 1)));
}

void SpecialSkillUI::add(SPECIALSKILL_TYPE _type, const SkillUI & _skill)
{
	m_conatiner.insert(std::make_pair(_type, _skill));
}

void SpecialSkillUI::open()
{
	if (isOpen())return;
	for (auto& i : m_conatiner) { i.second.initialize(); }
	for (auto& i:m_conatiner){i.second.open();}
}

void SpecialSkillUI::close()
{
	if (!isOpen())return;
	for (auto& i : m_conatiner){i.second.close();}
}

void SpecialSkillUI::canSelect(SPECIALSKILL_TYPE _type)
{
	m_conatiner.at(_type).canSelect();
}

void SpecialSkillUI::select(SPECIALSKILL_TYPE _type)
{
	m_isSelect = true;
	m_conatiner.at(_type).select();
}

void SpecialSkillUI::update(float deltaTime)
{
	for (auto& i : m_conatiner) { i.second.update(deltaTime); }
	if (!m_isSelect)return;
	m_retrovert.update(deltaTime);
	if (m_retrovert.isEnd())
	{
		for (auto& i : m_conatiner) { i.second.initialize(); }
		m_retrovert.initialize();
		m_isSelect = false;
		//close();
	}
}

void SpecialSkillUI::draw(IRenderer * _renderer)
{
	for (auto& i : m_conatiner)
	{
		i.second.draw(_renderer,m_position);
	}
	SpriteRenderDesc s;
	s.matrix.translate(m_position);
	s.center =GSvector2(77,78);
	s.textureID = static_cast<GSuint>(TEXTURE_ID::SPECIAL_MAIN);
	_renderer->render(s);
}

const bool SpecialSkillUI::isOpen() const
{
	return std::all_of(m_conatiner.begin(), m_conatiner.end(), [](const auto& _value) 
	{
		return _value.second.isOpen();
	});
}
