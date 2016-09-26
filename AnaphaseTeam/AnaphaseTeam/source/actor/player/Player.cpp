#include "../../../header/actor/Player/Player.h"

#include "../../../header/actionstate/MoveState.h"
#include "../../../header/actionstate/StandState.h"
#include "../../../header/actionstate/JumpState.h"
#include "../../../header/actionstate/AttackState.h"
#include "../../../header/actionstate/AvoidState.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/shape/Ray.h"
#include "../../../header/data/PLAYERACTION_ID.h"
#include "../../../header/collision/CollisionMediator.h"
#include "../../../header/shape/Capsule.h"
#include "../../../header/camera/CameraController.h"


const float Player::MOVESPEED = 0.3f;
const float Player::ROTATESPEED = -2.0f;
const float Player::WALKSPEED = 0.1f;

Player::Player(const Input* _input, Camera * _camera)
	:Actor(Transform({ 0,0,5 }), MODEL_ID::PLAYER, Sphere(GSvector3(0, 0, 0), 0), Actor_Tag::PLAYER),
	m_action(nullptr),
	m_SubAction(this),
	m_attackManager(),
	m_isGround(false),
	m_jumpAttack(false),
	m_camera(_camera)
	//m_scythe(MODEL_ID::PLAYER),
	//m_gun(MODEL_ID::PLAYER)
{
}

Player::~Player()
{}

void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animatorOne.initialize();
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true, true);
	m_attackManager.initialize();
	m_jumpAttack = false;
}

void Player::update(float deltatime)
{
	m_action->action(this, deltatime);
	sphereChases(GSvector3(0, 1, 0));
	m_animatorOne.update(deltatime);
}

void Player::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	//m_animator.bind();
	_renderer.getDraw3D().drawMesh(MODEL_ID::PLAYER, m_transform, m_animatorOne, m_Color);
}

void Player::inGround()
{
	m_isGround = true;
}

void Player::createCollision(CollisionMediator * _mediator)
{
	GSvector3 pos(m_transform.getPosition() + GSvector3(0, 0.3f, 0));
	Shape_Ptr shape = std::make_shared<Capsule>(Segment(pos, GSvector3(0, 0.8f, 0)), 0.5f);
	Obj_Ptr obj = std::make_shared<CollisionObject>(this, shape, CollisionType::PLAYER);
	_mediator->add(obj);
}

void Player::stand(float deltaTime)
{
	moveMotionChange();
	subActionStart();
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true, true);
	control();
}

void Player::attack(float deltaTime)
{
	m_attackManager.update(deltaTime,this);
	if (m_attackManager.isEndAttack())
	{
		m_jumpAttack = false;
		if (!m_isGround)
		{
			actionChange(std::make_shared<JumpState>());
			return;
		}
		actionChange(std::make_shared<StandState>());
	}
}

void Player::damage(float deltaTime)
{
}

void Player::move(float deltaTime)
{
	moveMotionChange();
	subActionStart();
	control();
	moving(deltaTime);
}

void Player::jump(float deltaTime)
{
	m_SubAction.update(deltaTime);
	if (m_SubAction.isEnd(SubActionType::JUMP))
	{
		actionChange(std::make_shared<StandState>());
	}
}

void Player::avoid(float deltaTime)
{
	m_animatorOne.changeAnimation(ANIMATION_ID::AVOID);
	m_SubAction.update(deltaTime);
	if (m_SubAction.isEnd(SubActionType::AVOID))
	{
		actionChange(std::make_shared<StandState>());
	}
}
void Player::jumping(float _velocity)
{
	m_transform.translateY(_velocity);
}
void Player::subActionStart()
{
	if (m_Input->jumpTrigger())
	{
		GSvector3 nowPosition = GSvector3(0, m_transform.getPosition().y, 0);
		m_transform.translate(nowPosition);
		m_SubAction.initialize(SubActionType::JUMP);
		actionChange(std::make_shared<JumpState>());
		m_isGround = false;
	}

	if (m_Input->avoidTrigger())
	{
		m_SubAction.initialize(SubActionType::AVOID);
		actionChange(std::make_shared<AvoidState>());
	}
}

void Player::jumpMotion(JumpControl& _control, ANIMATION_ID _id)
{
	_control.changeMotion(m_animatorOne,_id);
}

void Player::avoidAction(const GSvector3 & _velocity) 
{
	m_transform.translate(_velocity);
}

void Player::attackmotion(Attack & _attack)
{
	_attack.changeMotion(m_animatorOne);
}

const bool Player::isEndAttackMotion(const Attack & _attack) const
{
	return _attack.isEndMotion(m_animatorOne);
}

void Player::moving(float deltaTime, bool isAnimation)
{
	float speed=0.3f;
	float time=1.0f;
	if (m_Input->walk())
	{
		speed = 0.1f;
		time = 0.4f;
	}
	movement(deltaTime,speed);
	if (!isAnimation)return;
	m_animatorOne.changeAnimation(ANIMATION_ID::RUN, true, true, time);
}


const bool Player::isJump() const
{
	return m_Input->jumpTrigger();
}
const bool Player::isGround() const
{
	return m_isGround;
}

const bool Player::isJumpAttack() const
{
	return m_jumpAttack&&m_isGround;
}

const bool Player::isEndAttack() const
{
	return m_attackManager.isEndAttack();
}
const bool Player::isAttack() const
{
	return m_Input->scytheTrigger();
}

const bool Player::isGunAttack() const
{
	return m_Input->gunTrigger();
}
const GSvector3 Player::inputDirection() const
{
	return m_transform.front()+ GSvector3(0,0,0);
}

void Player::actionChange(Action_Ptr _action)
{
	m_action = _action;
}

void Player::control()
{
	/*ボタン押したらAttackStateに切り替わる*/
	if (m_Input->attackTrigger())
	{
		actionChange(std::make_shared<AttackState>());
		m_attackManager.initialize();
		m_jumpAttack = true;
	}
}

void Player::look_at(CameraController * _camera, GSvector3 * _target)
{
	GSvector3 target = m_transform.getPosition();
	_camera->special_move1(&target, _target,10.0f,1.5f);
}

/**
* @fn
* @brief 動いていればMoveStateに切り替え、動いていなければStandStateに切り替える
*/
void Player::moveMotionChange()
{
	if (!m_Input->move())
	{
		actionChange(std::make_shared<StandState>());
		return;
	}
	actionChange(std::make_shared<MoveState>());
}

void Player::movement(float deltaTime, float _speed)
{
	Transform transform = m_camera->transform();
	GSvector3 forward(transform.front()*m_Input->vertical());
	GSvector3 side(transform.left()*m_Input->horizontal());
	GSvector3 velocity = forward + side;
	m_transform.translate(velocity*_speed*deltaTime);

	m_transform.setYaw(-velocity.getYaw());
}
