#include "..\..\header\spawn\SpawnPoint.h"
#include "../../header/actor/Enemy/IEnemy.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/math/Random.h"
#include "../../header/actor/Enemy/EnemyManager.h"
#include <algorithm>
SpawnPoint::SpawnPoint(const SpawnData & _data)
	:m_data(_data),
	m_container()
{
}

void SpawnPoint::initialize()
{
	m_container.clear();
}

void SpawnPoint::update(float deltaTime)
{
	remove();
}
void SpawnPoint::draw(IRenderer * _renderer)
{
}

void SpawnPoint::createEnemy(EnemyManager & _manager/*, const EnemyFactory & _factory*/)
{
	for (unsigned int i = 0; i < m_data.spawnNum; i++)
	{
		cloneEnemy(_manager);
	}
}

const unsigned int SpawnPoint::getActiveNumber() const
{
	return m_data.activeNumber;
}

void SpawnPoint::cloneEnemy(EnemyManager & _manager/*const EnemyFactory & _factory*/)
{
	//std::shared_ptr<Enemy> enemy = _factory.create(m_data.type);
	float radius = m_data.area.radius;
	Math::Random rand;
	GSvector3 area(rand(-radius, radius), 0, rand(-radius, radius));
	area += m_data.area.position;
	Transform transform({ 0,0,0 }, area);
	std::shared_ptr<IEnemy> enemy = std::make_shared<Goblin>(transform, _manager);
	//weakポインタをContainerに登録
	m_container.emplace_back(enemy);
	_manager.add(enemy);
}

const bool SpawnPoint::isEnd() const
{
	return m_container.empty();
}

void SpawnPoint::remove()
{
	auto itr = std::remove_if(m_container.begin(), m_container.end(), [](EnemyWeak_Ptr& _enemy)
	{
		//開放済みか
		if (_enemy.expired())return  true;
		//weakは使用中に開放されるのを防ぐためシェアードポインタを取得しアクセスする
		return _enemy.lock()->isDead();
	});
	m_container.erase(itr, m_container.end());
}
