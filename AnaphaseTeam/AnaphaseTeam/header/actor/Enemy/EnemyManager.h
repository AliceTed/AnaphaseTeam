#pragma once
#include <vector>
#include "EnemyMediator.h"
#include <memory>
class Enemy;
class IRenderer;
class Actor;
class Player;
class Map;
//ユニークポインタをシェアードポインタに変更
using Enemy_Ptr = std::shared_ptr<Enemy>;
class EnemyManager :public EnemyMediator
{
public:
	EnemyManager();
	~EnemyManager() = default;
	void initialize();
	void add(Enemy* _enemy);
	void add(Enemy_Ptr _enemy);
	void update(float deltaTime);
	void collisionGround(const Map& _map);

	void collision(Actor& _actor);
	void draw(IRenderer * _renderer);

	std::weak_ptr<Enemy> nearEnemy(Player* _player);

	void thinks(Player* _player);

	const unsigned int size()const;
	virtual float requestDistancePlayer(Enemy * _enemy) override;
	virtual bool requestDistanceOtherEnemy(Enemy * _enemy)override;
	virtual bool reqestGoToNear()override;
	virtual bool reqestGoToMid()override;
private:
	void remove();
private:
	std::vector<Enemy_Ptr>m_enemys;
	// EnemyMediator を介して継承されました
};
