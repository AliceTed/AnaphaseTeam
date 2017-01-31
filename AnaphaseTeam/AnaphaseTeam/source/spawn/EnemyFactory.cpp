#include "spawn\EnemyFactory.h"

EnemyFactory::EnemyFactory()
{

}
EnemyFactory::~EnemyFactory()
{

}
const std::shared_ptr<IEnemy> EnemyFactory::createEnemy(Transform& _transform, EnemyMediator& _mediator,ENEMY_TYPE _type)const 
{
	switch (_type)
	{
	case ENEMY_TYPE::GOBRIN:
		return std::make_shared<Goblin>(_transform, _mediator);
		break;
	case ENEMY_TYPE::SLAHHAND:
		return std::make_shared<Boss>(_transform, _mediator);
		break;
	}
	return nullptr;
}