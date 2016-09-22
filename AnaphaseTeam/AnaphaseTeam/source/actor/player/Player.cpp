#include "../../../header/actor/Player/Player.h"

#include "../../../header/actionstate/MoveState.h"
#include "../../../header/actionstate/StandState.h"
#include "../../../header/actionstate/JumpState.h"
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
const float Player::WALKSPEED = 0.1f;

Player::Player(const Input* _input)
	:Actor(Transform({ 0,0,5 }), MODEL_ID::PLAYER, Sphere(GSvector3(0, 0, 0), 0), Actor_Tag::PLAYER),
	m_action(nullptr),
	m_SubAction(this),
	m_attackManager(),
	m_GroundHit(false)
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
}

void Player::update(float deltatime)
{
	m_action->action(this, deltatime);
	sphereChases(GSvector3(0, 1, 0));
	m_animatorOne.update(deltatime);
}

void Player::draw(const Renderer & _renderer, const Camera & _camera)
{
	//取りあえず無理やり追従させる
	const_cast<Camera&>(_camera).lookAt(m_transform.getPosition(), m_transform.getYaw());
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	//m_animator.bind();
	_renderer.getDraw3D().drawMesh(MODEL_ID::PLAYER, m_transform, m_animatorOne, m_Color);
}

void Player::inGround()
{
	m_GroundHit = true;
	//m_SubAction.groundHit();
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
	moveMotionChange();
	subActionStart();
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true, true);
	control();
	m_attackManager.update(this);
}

void Player::attack(float deltaTime)
{
	m_attackManager.update(this);
	if (m_attackManager.isEndAttack(&m_animatorOne))
	{
		actionChange(std::make_shared<StandState>());
	}
}

void Player::animeID(ANIMATION_ID _animetion_id)
{
	m_animatorOne.changeAnimation(_animetion_id);
}


void Player::damage(float deltaTime)
{
}

void Player::move(float deltaTime)
{
	moveMotionChange();
	subActionStart();
	control();
	if (m_Input->walk())
	{
		walk(deltaTime);
		return;
	}
	movement(deltaTime, MOVESPEED);
	m_animatorOne.changeAnimation(ANIMATION_ID::RUN, true, true);
}

void Player::jump(float deltaTime)
{
	m_SubAction.update(deltaTime);
	if (m_SubAction.isEnd())
	{
		actionChange(std::make_shared<StandState>());
	}
}

void Player::walk(float deltaTime)
{
	movement(deltaTime, WALKSPEED);
	m_animatorOne.changeAnimation(ANIMATION_ID::RUN, true, true, 0.4f);
}

void Player::chain(float deltaTime)
{
	//m_ChainMove.movement(deltaTime, this);
}

void Player::jumping(float _velocity)
{
	m_transform.translateY(_velocity);
}

void Player::chainMove(const GSvector3 & _target, float _time)
{
	m_transform.setPosition(m_transform.getPosition().lerp(_target, _time));
}

void Player::subActionStart()
{
	if (m_Input->jumpTrigger())
	{
		GSvector3 nowPosition = GSvector3(0, m_transform.getPosition().y, 0);
		m_transform.translate(nowPosition);
		m_SubAction.initialize();
		actionChange(std::make_shared<JumpState>());
		m_GroundHit = false;
	}
}

//ジャンプ中のアニメーション
void Player::jumpUp()
{
	m_animatorOne.changeAnimation(ANIMATION_ID::JUMPUP, true, true);
}

//着地のアニメーション
void Player::jumpRigor()
{
	m_animatorOne.changeAnimation(ANIMATION_ID::LANDING, true, true);
}

const bool Player::isJump() const
{
	return m_Input->jumpTrigger();
}


const bool Player::isGround() const
{
	return m_GroundHit;
}

const bool Player::isEndAttack() const
{
	return m_attackManager.isEndAttack(&m_animatorOne);
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
	}
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
	m_transform.rotationY(m_Input->rotate()*deltaTime * ROTATESPEED);
	GSvector3 forward(m_transform.front()*m_Input->vertical());
	GSvector3 side(m_transform.left()*m_Input->horizontal());
	m_transform.translate((forward - side)*_speed*deltaTime);
}
