#include "..\..\header\spawn\SpawnPoint.h"
#include "../../header/actor/Enemy/Enemy.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/math/Random.h"
#include <algorithm>
SpawnPoint::SpawnPoint(const SpawnData & _data)
	:m_isStart(false),
	m_data(_data),
	m_container()
{
}

void SpawnPoint::initialize()
{
	m_isStart=false;
	m_container.clear();
}

void SpawnPoint::update(float deltaTime)
{
	remove();
}

void SpawnPoint::draw(IRenderer * _renderer)
{
}

const unsigned int SpawnPoint::getActiveNumber() const
{
	return m_data.activeNumber;
}

std::shared_ptr<Enemy> SpawnPoint::createEnemy(const EnemyFactory & _factory) 
{
	//std::shared_ptr<Enemy> enemy = _factory.create(m_data.type);
	float radius = m_data.area.radius;
	Math::Random rand;
	GSvector3 area(rand(-radius,radius),0, rand(-radius, radius));
	area += m_data.area.position;
	Transform transform({ 0,0,0 }, area);
	std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(transform);
	//weakポインタをContainerに登録
	m_container.emplace_back(enemy);
	return enemy;
}

const bool SpawnPoint::isEnd() const
{
	return m_container.empty()&& m_isStart;
}

void SpawnPoint::remove()
{
	auto itr = std::remove_if(m_container.begin(),m_container.end(), [](EnemyWeak_Ptr& _enemy)
	{
		//開放済みか
		if (_enemy.expired())return  true;
		//weakは使用中に開放されるのを防ぐためシェアードポインタを取得しアクセスする
		return _enemy.lock()->isDead();
	});
	m_container.erase(itr, m_container.end());
}
