#pragma once
#include <list>
#include <memory>
class Phase;
class ActorManager;
class CameraController;
class IRenderer;
class PhaseManager
{
public:
	PhaseManager();
	~PhaseManager()=default;
	void add(Phase* _phase);
	void update(float deltaTime, ActorManager& _actors, CameraController& _camera);
	void draw(IRenderer* _renderer);
	void changeFirst();
	const bool isEnd()const;
private:
	using PhasePtr = std::shared_ptr<Phase>;
	using Container = std::list<PhasePtr>;

	Container m_container;
	PhasePtr m_current;
};