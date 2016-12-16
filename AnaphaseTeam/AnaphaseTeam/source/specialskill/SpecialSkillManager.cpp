#include "../../header/specialskill/SpecialSkillManager.h"
#include <algorithm>
#include "../../header/actor/Player/Gauge.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/ui/SpecialSkillUI.h"
#include "../../header/device/GameDevice.h"
SpecialSkillManager::SpecialSkillManager(Gauge* _gauge)
	:m_container(),m_current(),m_gauge(_gauge)
{
}
void SpecialSkillManager::add(SPECIALSKILL_TYPE _type, ISpecialSkill* _skill)
{
	m_container.insert(std::make_pair(_type, Special_Ptr(_skill)));
}
void SpecialSkillManager::start(SPECIALSKILL_TYPE _type)
{
	Special_Ptr next=m_container.at(_type);
	if (!m_gauge->down(next->consumption()))return;
	GameDevice::getInstacnce().sound().playSE(SE_ID::ENTER);
	m_current.insert(std::make_pair(_type, next));
	next->start();
}
void SpecialSkillManager::update(float deltaTime)
{
	for (auto& i:m_current)
	{
		i.second->update(deltaTime);
	}
	endRemove();
}
#include "../../header/renderer/define/StringRenderDesc.h"
void SpecialSkillManager::draw(IRenderer* _renderer)
{
	//Šm”F
	StringRenderDesc desc;
	
	for (auto& i : m_current)
	{
		switch (i.first)
		{
		case SPECIALSKILL_TYPE::RECOVERY:
			desc.string+="RECOVERY";
			break;
		case SPECIALSKILL_TYPE::SUPERARMOR:
			desc.string += "SUPERARMOR";
			break;
		case SPECIALSKILL_TYPE::SPECIALLATTACK:
			desc.string += "SPECIALLATTACK";
			break;
		}
		desc.string += ",";
	}
	desc.position = GSvector2(100, 100);
	_renderer->render(desc);
}
const bool SpecialSkillManager::isStart(SPECIALSKILL_TYPE _type)const
{
	return m_current.count(_type) != 0;
}
void SpecialSkillManager::clear()
{
	m_container.clear();
	m_current.clear();
}

void SpecialSkillManager::canSelectCheck(SpecialSkillUI * _skillUI) const
{
	for (auto& i:m_container)
	{
		if (m_gauge->isDown(i.second->consumption()))
		{
			_skillUI->canSelect(i.first);
		}
	}
}

void SpecialSkillManager::endRemove()
{
	std::vector<SPECIALSKILL_TYPE> deadtype;
	deadtype.clear();
	for (auto& i:m_current)
	{
		if (i.second->isEnd())
		{
			deadtype.emplace_back(i.first);
		}
	}
	for (auto& i : deadtype){m_current.erase(i);}
}