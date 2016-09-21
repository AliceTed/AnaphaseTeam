#include "../../header/collision/CollisionManager.h"

CollisionManager::CollisionManager()
	:m_Container(), m_table()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::add(Obj_Ptr _obj)
{
	m_Container.add(_obj);
}

void CollisionManager::initialize()
{
	m_Container.clear();
	m_table.setNonCollision(Actor_Tag::TEST, Actor_Tag::TEST);
}

void CollisionManager::update(float deltaTime)
{
	m_Container.accept([&](Obj_Ptr _obj1)
	{
		m_Container.accept([&](Obj_Ptr _obj2)
		{
			collision(_obj1, _obj2);
		});
	});
	//描画しない場合(基本しない)draw関数のなか2行をコメントアウト
	m_Container.clear();
}

void CollisionManager::draw(const Renderer & renderer)
{
	//描画する場合updateのclearをコメントアウト
	/*m_Container.accept([&](Obj_Ptr _obj) {_obj->draw(renderer);});
	m_Container.clear();*/
}

void CollisionManager::collision(Obj_Ptr _obj1, Obj_Ptr _obj2)
{
	if (!_obj1->isCollision(_obj2.get(),m_table))
	{
		return;
	}
	_obj1->collision(_obj2.get());
	_obj2->collision(_obj1.get());
}
