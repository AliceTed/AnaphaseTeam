#pragma once
/**
* @file CollisionActor.h
* @brief 新しい判定オブジェクト
* @author 松尾裕也
* @date 2016/9/28
*/
#include <functional>
#include <memory>
#include <vector>
#include <algorithm>
#include "../shape/Shape.h"
#include "CollisionActorType.h"
class Actor;
class Renderer;
typedef std::shared_ptr<Shape> Shape_Ptr;
class CollisionActor
{
public:
	CollisionActor(Shape_Ptr _shape, CollisionActorType _type);
	~CollisionActor();
	void update(float deltaTime);
	const bool isCollision(CollisionActor* _other)const;
	void collision(Actor* _otherActor, CollisionActor* _other);
	void exit(Actor * _otherActor, CollisionActor * _other);
	void draw(const Renderer& _renderer);
	const bool isDead()const;
public:
	void set_dead(const std::function<const bool()>& _function);
	void set_update(const std::function<void(float, Shape_Ptr)>& _function);
	void set_draw(const std::function<void(const Renderer& _renderer)>& _function);
	void set_collision_enter(const std::function<void(Actor*, CollisionActorType)>& _function);
	void set_collision_stay(const std::function<void(Actor*, CollisionActorType)>& _function);
	void set_collision_exit(const std::function<void(Actor*, CollisionActorType)>& _function);
private:
	const bool is_find(std::vector<std::shared_ptr<CollisionActor>>& _container, CollisionActor* _other);
private:
	Shape_Ptr m_shape;
	CollisionActorType m_type;
	std::vector<std::shared_ptr<CollisionActor>>m_previous;
private:
	std::function<const bool()>m_destroy;
	std::function<void(float, Shape_Ptr)>m_update;
	std::function<void(const Renderer& _renderer)>m_draw;
	std::function<void(Actor*, CollisionActorType)>m_collision_enter;
	std::function<void(Actor*, CollisionActorType)>m_collision_stay;
	std::function<void(Actor*, CollisionActorType)>m_collision_exit;
};
