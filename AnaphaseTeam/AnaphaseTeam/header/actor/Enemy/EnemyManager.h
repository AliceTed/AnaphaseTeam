#pragma once
#include <vector>
#include <memory>
class Enemy;
class IRenderer;
class Actor;
class Player;
//���j�[�N�|�C���^���V�F�A�[�h�|�C���^�ɕύX
using Enemy_Ptr = std::shared_ptr<Enemy>;
class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager() = default;
	void initialize();
	void add(Enemy* _enemy);
	void update(float deltaTime);
	void collisionGround(const Map& _map);

	void collision(Actor& _actor);
	void draw(IRenderer * _renderer);

	Enemy_Ptr nearEnemy(Player* _player);

	void thinks(Player* _player);

	const unsigned int size()const;
private:
	void remove();
private:
	std::vector<Enemy_Ptr>m_enemys;
};
