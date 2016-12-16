#pragma once
#include <vector>
#include <memory>
class Phase;
class ActorManager;
class IRenderer;
class PhaseManager
{
public:
	PhaseManager();
	~PhaseManager()=default;
	void add(Phase* _phase);
	void update(float deltaTime, ActorManager& _actors);
	void draw(IRenderer* _renderer);
	void changeFirst();
	const bool isEnd()const;
private:
	using PhasePtr = std::shared_ptr<Phase>;
	using Container = std::vector<PhasePtr>;

	Container m_container;
	PhasePtr m_current;
};