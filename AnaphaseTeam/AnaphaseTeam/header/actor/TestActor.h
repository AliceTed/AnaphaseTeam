#pragma once
#include "Actor.h"

#include <unordered_map>
#include "../enemy/BreakPoint.h"
class Player;
class AttackStatus;
class CameraController;
class TestActor:public Actor
{
public:
	TestActor();
	~TestActor();
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void look_at(CameraController* _camera,Player* _actor);
private:
	void add(const Sphere& _sphere,CollisionActorType _type);
	void createPoint();
	void eachUpdate(float deltaTime, CollisionActorType _type,const GSvector3& _position);

	std::vector<GSmatrix4> getAnimEachPos();
	GSvector3 getPos(std::vector<GSmatrix4>& _mat, int index);
private:
	std::unordered_map<CollisionActorType,BreakPoint> m_points;
	Sphere m_core;
	GScolor m_corecolor;
	static const int HEAD = 6;
	static const int LEFTLEG = 56;
	static const int RIGHTLEG = 61;
};

