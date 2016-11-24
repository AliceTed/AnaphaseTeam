#pragma once
/**
* @file CollisionActor.h
* @brief ����I�u�W�F�N�g�N���X�̌�
* @author �����T��
* @date 2016/11/09
*/
#include <memory>
#include <vector>
#include <functional>
#include "../shape/Shape.h"
#include "Collision_Tag.h"
class Actor;
class IRenderer;
struct HitInformation;
class CollisionActor;
typedef std::shared_ptr<CollisionActor> Collision_Ptr;
class CollisionActor
{
public:
	CollisionActor(Shape* _shape,Collision_Tag _tag);
	virtual ~CollisionActor();
	
	void update(float deltaTime);
	void draw(IRenderer * _renderer);	
	void collision(Collision_Ptr&  _other, HitInformation& _hit);
	void exit(Collision_Ptr& _other, HitInformation& _hit);
	const bool isCollision(Collision_Ptr&  _other, HitInformation* _out1, HitInformation* _out2)const;
	const bool isDead()const;
protected:
	void destroy();
private:
	virtual void doUpdate(float deltaTime);
	virtual void doDraw(IRenderer * _renderer);
	virtual void collision_Enter(HitInformation& _hit);
	virtual void collision_Stay(HitInformation& _hit);
	virtual void collision_Exit(HitInformation& _hit);
private:
	//previous�Ɏw���actor�����邩
	const bool isPreviousFind(Collision_Ptr& _other);
	//previous�Ɏw��actor������΍폜��true��Ԃ�
	const bool isPreviousRemove(Collision_Ptr&  _other);
	//previous�̎w������ɍ����v�f���폜(erase)��true��Ԃ�
	const bool previousRemove(std::function<bool(Collision_Ptr&)> _func);
protected:
	typedef std::shared_ptr<Shape> Shape_Ptr;
	Shape_Ptr m_shape;
private:
	bool m_isDead;
	std::vector<Collision_Ptr>m_previous;
	Collision_Tag m_tag;
};