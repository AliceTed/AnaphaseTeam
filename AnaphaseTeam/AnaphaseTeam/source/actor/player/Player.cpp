#include "../../../header/actor/Player/Player.h"

#include "../../../header/actionstate/MoveState.h"
#include "../../../header/actionstate/StandState.h"
#include "../../../header/actionstate/JumpState.h"
#include "../../../header/actionstate/AttackState.h"
#include "../../../header/actionstate/AvoidState.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/shape/Ray.h"
#include "../../../header/data/PLAYERACTION_ID.h"
#include "../../../header/camera/CameraController.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/shape/Capsule.h"

#include "../../../header/actor/Boss/Boss.h"
const float Player::MOVESPEED = 0.3f;
const float Player::ROTATESPEED = -2.0f;
const float Player::WALKSPEED = 0.1f;
Player::Player(GameDevice* _device, Camera * _camera)
	:Actor(
		Transform({ 0,0,-30 }),
		MODEL_ID::PLAYER,
		Sphere(GSvector3(0, 0, 0), 0),
		Actor_Tag::PLAYER
		),
	m_device(_device),
	m_action(nullptr),
	m_SubAction(this),
	m_attackManager(),
	m_isGround(false),
	m_camera(_camera),
	m_status(),
	m_isJumpAttack(false),
	m_group(std::make_shared<CollisionGroup>(this)),
	m_Gauge(),
	m_avoid(this)
{
	//m_matrix = std::make_shared<GSmatrix4>(new GSmatrix4[m_animatorOne.getNumBones()]);
}

Player::~Player()
{}

void Player::addCollisionGroup(CollisionManager * _manager)
{
	_manager->add(m_group);
}

void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animatorOne.initialize();
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true, true);
	m_isJumpAttack = false;
	createColision();
	m_Gauge.initialize();
	m_status.initialize();
}

void Player::update(float deltatime)
{
	m_action->action(this, deltatime);
	sphereChases(GSvector3(0, 1, 0));
	m_animatorOne.update(deltatime);
	
	m_status.change(m_Gauge);
	//	m_animatorOne.getAnimMatrix(m_matrix.get());
}

void Player::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	_renderer.getDraw3D().drawMesh_calcu(MODEL_ID::PLAYER, m_transform,m_animatorOne, m_Color);
	m_Gauge.draw(_renderer);
}

void Player::inGround()
{
	m_isGround = true;
}

void Player::stand(float deltaTime)
{
	if (!m_isGround)
	{
		actionChange(std::make_shared<JumpState>());
		return;
	}
	moveMotionChange();
	subActionStart();
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true, true);
	control();
}

void Player::attack(float deltaTime)
{
	m_SubAction.jumpPowerOff();
	m_attackManager.update(deltaTime, this);
	if (m_attackManager.isEnd())
	{
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
	m_SubAction.update(deltaTime, SubActionType::JUMP);
	if (m_SubAction.isEnd(SubActionType::JUMP))
	{
		m_isJumpAttack = false;
		actionChange(std::make_shared<StandState>());
	}
}

void Player::avoid(float deltaTime)
{
	m_animatorOne.changeAnimation(ANIMATION_ID::AVOID);
	//m_SubAction.update(deltaTime, SubActionType::AVOID);
	m_avoid.update(deltaTime);
	//m_SubAction.jumpPowerOff();
	//if (m_SubAction.isEnd(SubActionType::AVOID))
	if (m_avoid.isEnd())
	{
		actionChange(std::make_shared<StandState>());
	}
}

void Player::createColision()
{
	//Segment segment = Segment(m_transform.getPosition(), GSvector3(0, -0.1f, 0));
	Shape_Ptr shape = std::make_shared<Capsule>(Segment( m_transform.getPosition(),GSvector3(0,0.8f,0)), 0.5f);
	Collision_Ptr obj = std::make_shared<CollisionActor>(shape, CollisionActorType::PLAYER);
	obj->set_update([&](float deltaTime, Shape_Ptr _shape) 
	{
		GSvector3 target = m_transform.getPosition() + GSvector3(0.0f, 0.5f, 0.0f);
		_shape->transfer(target);
	});
	obj->set_draw([&](const Renderer& _renderer, Shape_Ptr _shape) { _shape->draw(_renderer); });
	m_group->add(obj);
}

void Player::jumping(float _velocity)
{
	m_transform.translateY(_velocity);
}

void Player::subActionStart()
{
	if (m_device->input()->jump())
	{
		GSvector3 nowPosition = GSvector3(0, m_transform.getPosition().y, 0);
		m_transform.translate(nowPosition);
		m_SubAction.initialize(SubActionType::JUMP);
		actionChange(std::make_shared<JumpState>());
		m_isGround = false;
		return;
	}

	if (m_device->input()->avoid())
	{
		if (m_Gauge.down(5))
		{
			//m_SubAction.initialize(SubActionType::AVOID);
			m_avoid.initialize();
			actionChange(std::make_shared<AvoidState>());
		}
	}
}

void Player::moveStart()
{
	if (m_device->input()->move())
		actionChange(std::make_shared<MoveState>());
}

void Player::justAvoid(Avoid* _avoid)
{
	_avoid->justAvoidRange(m_group, m_transform);
}

void Player::attackRange(Attack* _attack)
{
	//_attack->range(m_group, m_transform, [=]()->bool {return isEndAttackMotion(*_attack); });
}

void Player::gaugeUp(float _scale)
{
	m_Gauge.up(_scale);
}

void Player::attackhoming(Boss * _boss)
{
	if (m_attackManager.isEnd())
	{
		return;
	}
	if (isAttack())
	{
		GSvector3 vector = _boss->getPosition() - m_transform.getPosition();
		float radian = atan2(vector.x, vector.z);
		float degree = radian * 180.0f / M_PI;
		m_transform.setYaw(degree);

		GSvector3 forward(m_transform.front() * 1);
		m_transform.translate(forward);
	}
}

void Player::startJump(JumpControl * _control, float _scale)
{
	_control->setPower(_scale);
}

void Player::jumpMotion(JumpControl& _control, ANIMATION_ID _id, float _animSpeed)
{
	_control.changeMotion(m_animatorOne, _id, _animSpeed);
}

void Player::avoidAction(const GSvector3 & _velocity)
{
	m_transform.translate(_velocity);
}

void Player::attackmotion(IAttack & _attack)
{
	_attack.changeMotion(m_animatorOne,m_status.attackSpeed() );
}

const bool Player::isNextAttack(IAttack & _attack) const
{
	return _attack.isNextAttack(m_animatorOne);
}

const bool Player::isEndAttackMotion(const IAttack & _attack) const
{
	return _attack.isEndMotion(m_animatorOne);
}

const bool Player::isChargeAttack() const
{
	return m_device->input()->charge();
}


void Player::moving(float deltaTime, bool isAnimation)
{
	//float speed = m_status.getMoveSpeed(false, false);
	float time = 1.0f;
	if (m_device->input()->walk())
	{
		//speed = m_status.getWalkSpeed();
		time = 0.4f;
	}
	movement(deltaTime, 0.5f);
	if (!isAnimation)return;
	m_animatorOne.changeAnimation(ANIMATION_ID::RUN, true, true, time);
}

void Player::actionChange(Action_Ptr _action)
{
	m_action = _action;
}

void Player::control()
{
	///////////////////////////////////////////////////////////
	if (m_device->input()->gaugeAttack1())
	{
		m_Gauge.downGauge(RankGauge::FIRST);
		return;
	}
	if (m_device->input()->gaugeAttack2())
	{
		m_Gauge.downGauge(RankGauge::SECOND);
		return;
	}
	if (m_device->input()->gaugeAttack3())
	{
		m_Gauge.downGauge(RankGauge::THIRD);
		return;
	}
	/*ƒ{ƒ^ƒ“‰Ÿ‚µ‚½‚çAttackState‚ÉØ‚è‘Ö‚í‚é*/
	if (m_device->input()->scythe())
	{
		actionChange(std::make_shared<AttackState>());
		m_attackManager.initialize();
		m_isJumpAttack = !m_isGround;
		m_Gauge.up(10.0f);
	}
	
}

void Player::look_at(CameraController * _camera, GSvector3 * _target)
{
	GSvector3 target = m_transform.getPosition();
	_camera->special_move1(&target, _target, 10.0f, 1.5f);
}

void Player::buildup()
{
	//m_status.powerUp();
}

void Player::avoidStart()
{
	/*if (m_device->input()->avoid())
	{
		m_SubAction.initialize(SubActionType::AVOID);
		actionChange(std::make_shared<AvoidState>());
	}*/
}

/**
* @fn
* @brief “®‚¢‚Ä‚¢‚ê‚ÎMoveState‚ÉØ‚è‘Ö‚¦A“®‚¢‚Ä‚¢‚È‚¯‚ê‚ÎStandState‚ÉØ‚è‘Ö‚¦‚é
*/
void Player::moveMotionChange()
{
	if (!m_device->input()->move())
	{
		actionChange(std::make_shared<StandState>());
	}
	moveStart();
}

void Player::rotate(float deltaTime, Transform & _transform)
{
	GSvector2 dir = m_device->input()->velocity();
	GSvector3 forward(_transform.front()*-dir.y);
	GSvector3 side(_transform.left()*dir.x);
	GSvector3 velocity = forward + side;
	Math::ATan atan;
	float degree = atan(velocity.x, velocity.z);
	m_transform.setYaw(degree);
}

void Player::movement(float deltaTime, float _speed)
{
	Transform transform = m_camera->transform();
	if (m_device->input()->move())
		rotate(deltaTime, transform);
	int speed = 1;
	if (!m_device->input()->move())speed = 0;
	GSvector3 forward(m_transform.front()*speed);
	m_transform.translate(forward*deltaTime*_speed);
}

const bool Player::isJump() const
{
	return m_device->input()->jump();
}

const bool Player::isAvoid() const
{
	return m_device->input()->avoid();
}

const bool Player::isGround() const
{
	return m_isGround;
}

const bool Player::isJumpAttack() const
{
	return m_isJumpAttack;
}

const bool Player::isEndAttack() const
{
	return m_attackManager.isEnd();
}

const bool Player::isAnimationEnd() const
{
	return m_animatorOne.isEndCurrentAnimation();
}

const bool Player::isAttack() const
{
	return m_device->input()->scythe();
}

const bool Player::isGunAttack() const
{
	return m_device->input()->gun();
}
const GSvector3 Player::inputDirection() const
{
	return m_transform.front();
}
const GSvector3 Player::getPosition() const
{
	return m_transform.getPosition();
}
