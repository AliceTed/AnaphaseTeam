#include "../../../header/actor/Player/Player.h"

#include "../../../header/actionstate/MoveState.h"
#include "../../../header/actionstate/StandState.h"
#include "../../../header/actionstate/AttackState.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/shape/Ray.h"
#include "../../../header/data/PLAYERACTION_ID.h"
#include "../../../header/collision/CollisionMediator.h"
#include "../../../header/shape/Capsule.h"

const float Player::MOVESPEED = 0.3f;
const float Player::ROTATESPEED = -2.0f;

Player::Player(const Input* _input)
	:Actor(Transform({ 0,0,5 }), MODEL_ID::PLAYER, Sphere(GSvector3(0, 0, 0), 0), Actor_Tag::PLAYER),
	m_action(nullptr),
	m_SubAction(),
	m_ChainMove(),
	m_attackManager()
	//m_scythe(MODEL_ID::PLAYER),
	//m_gun(MODEL_ID::PLAYER)
{}
Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animator.initialize();

	m_animator.addAnimation(ANIMATION_ID::STAND, 1.0f, true);
	m_animator.addAnimation(ANIMATION_ID::RUN, 1.0f, true);
	m_animator.addAnimation(ANIMATION_ID::ATTACK, 1.4f);
	m_animator.addAnimation(ANIMATION_ID::ATTACK2, 1.4f);
	m_animator.addAnimation(ANIMATION_ID::ATTACK3, 1.4f);
	m_animator.addAnimation(ANIMATION_ID::ATTACK4, 1.4f);
	m_animator.addAnimation(ANIMATION_ID::GUN, 1.4f);
	m_attackManager.initialize();

	m_animator.changeAnimation(ANIMATION_ID::STAND, true);


}
void Player::update(float deltatime)
{
	m_action->action(this, deltatime);
	sphereChases(GSvector3(0, 1, 0));
	m_animator.update(deltatime);

}

void Player::draw(const Renderer & _renderer, const Camera & _camera)
{
	//��肠�����������Ǐ]������
	const_cast<Camera&>(_camera).lookAt(m_transform.getPosition(), m_transform.getYaw());
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	//m_animator.bind();
	_renderer.getDraw3D().drawMesh(MODEL_ID::PLAYER, m_transform, m_animator, m_Color);
	//_renderer.getDraw2D().string("m_attacTime:" + std::to_string(m_attackTime), &GSvector2(20, 60), 20);

}

void Player::collisionGround(const Map & _map)
{
	GSvector3 intersect;
	//���݂̈ʒu���牺������Ray�����
	GSvector3 position = m_transform.getPosition();
	Ray ray(position);
	if (!ray.isCollitionMap(_map, &intersect))
	{
		return;
	}

	if (position.y >= intersect.y)
	{
		return;
	}
	//
	m_SubAction.groundHit();

	//map�ɖ��ߍ��܂�Ă�����y���W����_�Ɉړ�
	m_transform.setPositionY(intersect.y);
}
void Player::createCollision(CollisionMediator * _mediator)
{
	GSvector3 pos(m_transform.getPosition() + GSvector3(0, 0.3f, 0));
	Shape_Ptr shape = std::make_shared<Capsule>(Segment(pos, GSvector3(0, 0.8f, 0)), 0.5f);
	Obj_Ptr obj = std::make_shared<CollisionObject>(this, shape);
	_mediator->add(obj);
}

void Player::stand(float deltaTime)
{
	m_animator.changeAnimation(ANIMATION_ID::STAND, false);
	m_SubAction.action(this, deltaTime);
	
	control();
	m_attackManager.update(this);
}

void Player::attack(float deltaTime)
{
	m_attackManager.update(this);
	if (m_attackManager.isEndAttack(&m_animator))
	{
		actionChange(std::make_shared<StandState>());
	}


	//m_attackManager.update(this);
	/*if (m_animator.isEndAnimation(ANIMATION_ID::ATTACK))
	{
		actionChange(std::make_shared<StandState>());
	}
	if (m_animator.isEndAnimation(ANIMATION_ID::ATTACK2))
	{
		actionChange(std::make_shared<StandState>());
	}*/
}

void Player::animeID(ANIMATION_ID _animetion_id)
{
	m_animator.changeAnimation(_animetion_id);
}


void Player::damage(float deltaTime)
{
}

void Player::move(float deltaTime)
{
	m_animator.changeAnimation(ANIMATION_ID::RUN, true);

	m_transform.rotationY(m_Input->rotate()*deltaTime * ROTATESPEED);
	GSvector3 forward(m_transform.front()*m_Input->vertical());
	GSvector3 side(m_transform.left()*m_Input->horizontal());
	m_transform.translate((forward - side)*MOVESPEED*deltaTime);
	m_SubAction.action(this, deltaTime);
	control();
	m_attackManager.update(this);
	if (m_Input->move() == false) actionChange(std::make_shared<StandState>());
}

void Player::chain(float deltaTime)
{
	m_ChainMove.movement(deltaTime, this);
}
void Player::jumping(float _velocity)
{
	m_transform.translateY(_velocity);
}

void Player::chainMove(const GSvector3 & _target, float _time)
{
	m_transform.setPosition(m_transform.getPosition().lerp(_target, _time));
}

void Player::subActionStart(jumpControl * _jump, TestChainMove * _chainMove)
{
	if (m_Input->chainTrigger())
	{
		//	_chainMove->start();
		m_SubAction.chainMoveStart();
	}
	if (m_Input->jumpTrigger())
	{
		m_SubAction.jumpStart();
	}
}

void Player::subActionStart()
{
	if (m_Input->chainTrigger())
	{
		m_SubAction.chainMoveStart();
	}
	if (m_Input->jumpTrigger())
	{
		m_SubAction.jumpStart();
	}
}

void Player::actionChange(Action_Ptr _action)
{
	m_action = _action;
}

void Player::control()
{
	subActionStart();
	if (m_Input->move())
	{
		actionChange(std::make_shared<MoveState>());
	}
	/*�{�^����������AttackState�ɐ؂�ւ��*/
	if (m_Input->attackTrigger())
	{
		actionChange(std::make_shared<AttackState>());
	}

}