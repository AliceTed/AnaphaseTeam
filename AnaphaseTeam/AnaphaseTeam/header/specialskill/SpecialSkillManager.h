#pragma once
#include <unordered_map>
#include <memory>
#include "SPECIALSKILL_TYPE.h"
#include "ISpecialSkill.h"
#include "../../header/ui/IPlayUI.h"
class Gauge;
class SpecialSkillUI;
class IRenderer;
class SpecialSkillManager:public IPlayUI
{
public:
	SpecialSkillManager(Gauge* _gauge);
	~SpecialSkillManager()=default;
	void add(SPECIALSKILL_TYPE _type, ISpecialSkill* _skill);
	bool start(SPECIALSKILL_TYPE _type);
	void update(float deltaTime);
	void draw(IRenderer* _renderer);
	const bool isStart(SPECIALSKILL_TYPE _type)const;
	void clear();

	void canSelectCheck(SpecialSkillUI* _skillUI)const;
private:
	void endRemove();
private:
	using Special_Ptr= std::shared_ptr<ISpecialSkill>;
	using Container = std::unordered_map<SPECIALSKILL_TYPE,Special_Ptr>;
	Container m_container;
	Container m_current;

	Gauge* m_gauge;
};