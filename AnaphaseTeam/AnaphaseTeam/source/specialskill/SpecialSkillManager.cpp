#include "../../header/specialskill/SpecialSkillManager.h"
#include <algorithm>
#include "../../header/actor/Player/Gauge.h"
#include "../../header/renderer/IRenderer.h"
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

void SpecialSkillManager::draw(IRenderer* _renderer)
{

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