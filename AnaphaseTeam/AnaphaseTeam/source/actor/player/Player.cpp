#include "../../../header/actor/Player/Player.h"

#include "../../../header/actionstate/MoveState.h"
#include "../../../header/actionstate/StandState.h"
#include "../../../header/actionstate/JumpState.h"
#include "../../../header/actionstate/AttackState.h"
#include "../../../header/actionstate/DamageState.h"
#include "../../../header/actionstate/AvoidState.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/shape/Ray.h"
#include "../../../header/data/PLAYERACTION_ID.h"
#include "../../../header/camera/CameraController.h"
#include "../../../header/math/Calculate.h"

#include "../../../header/actor/Boss/Boss.h"
#include "../../../header/camera/LockOn.h"
#include "../../../header/actor/Enemy/Enemy.h"

//これ追加 by有冨
#include "../../../header/camera/CameraWork/E_CameraWorkID.h"

const float Player::MOVESPEED = 0.3f;
const float Player::ROTATESPEED = -2.0f;
const float Player::WALKSPEED = 0.1f;
Player::Player(GameDevice* _device, Camera * _camera, LockOn* _lockon)
	:Actor(
		Transform({ 0,0,-30 }, GSquaternion(0, 0, 0, 1)),
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
	m_Gauge(),
	m_avoid(this),
	m_lockon(_lockon),
	m_scythe(),
	m_SpecialSkillManager(m_Gauge, this),
	m_currentAction(nullptr)
{
}

Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animatorOne.initialize();
	m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), true, true, true);
	m_isJumpAttack = false;
	createColision();
	m_Gauge.initialize();
	m_status.initialize();
	m_scythe.initialize();
	m_scythe.addCollision(&m_collision);
	m_SpecialSkillManager.initialize(SPECIALTYPE::NONE);
}

void Player::update(float deltatime)
{
	m_action->action(this, deltatime);
	sphereChases(GSvector3(0, 1, 0));
	m_animatorOne.update(deltatime);
	m_scythe.update(deltatime, m_animatorOne, m_transform);
	m_status.change(m_Gauge);
	m_SpecialSkillManager.update(deltatime);

	m_collision.update(deltatime);
	m_Gauge.update(deltatime);

	if (m_status.getHp() <= 0)
	{
		m_isDead = true;
	}
}

void Player::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	m_animatorOne.draw(_renderer,m_transform);
	m_collision.draw(_renderer);
	m_Gauge.draw(_renderer);
	m_scythe.draw(_renderer);
	_renderer.getDraw2D().textrue(TEXTURE_ID::BLACK, &GSvector2(0, 0),
		&GSrect(0, 0, 100, 30), &GSvector2(0, 0), &GSvector2(1, 1), 0.0f);
	_renderer.getDraw2D().textrue(TEXTURE_ID::CLEAR, &GSvector2(0, 0),
		&GSrect(0, 0, m_status.getHp(), 30), &GSvector2(0, 0), &GSvector2(1, 1), 0.0f, &GScolor(0.0f, 1.0f, 0.0f, 1.0f));

	//_renderer.getDraw2D().string(std::to_string(m_status.getHp()), &GSvector2(0, 0), 30);
}

void Player::inGround()
{
	m_isGround = true;
}

void Player::stand(float deltaTime)
{
	m_currentAction = std::make_shared<StandState>();
	if (!m_isGround)
	{
		actionChange(std::make_shared<JumpState>());
		return;
	}
	moveMotionChange();
	subActionStart();
	m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), true, true, true);
	control();
}

void Player::attack(float deltaTime)
{
	m_currentAction = std::make_shared<AttackState>();
	m_SubAction.jumpPowerOff();
	m_attackManager.update(deltaTime, this);
	if (m_attackManager.isEnd())
	{
		actionChange(std::make_shared<StandState>());
	}
}

void Player::damage(float deltaTime)
{
	if (m_SpecialSkillManager.isSuperArmor())
	{
		actionChange(m_currentAction);
		return;
	}
	m_currentAction = std::make_shared<DamageState>();
	m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::DAMAGE), false);
	if (isAnimationEnd())
	{
		actionChange(std::make_shared<StandState>());
	}
}

void Player::move(float deltaTime)
{
	m_currentAction = std::make_shared<MoveState>();
	moving(deltaTime);
	moveMotionChange();
	subActionStart();
	control();
}

void Player::jump(float deltaTime)
{
	m_currentAction = std::make_shared<JumpState>();
	m_SubAction.update(deltaTime, SubActionType::JUMP);
	if (m_SubAction.isEnd(SubActionType::JUMP))
	{
		m_isJumpAttack = false;
		actionChange(std::make_shared<StandState>());
	}
}

void Player::avoid(float deltaTime)
{
	m_currentAction = std::make_shared<AvoidState>();
	m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::STAND), true);
	m_avoid.update(deltaTime);
	if (m_avoid.isEnd())
	{
		actionChange(std::make_shared<StandState>());
	}
}

void Player::createColision()
{
	//Segment segment = Segment(m_transform.getPosition(), GSvector3(0, -0.1f, 0));
	//Shape_Ptr shape = std::make_shared<Capsule>(Segment(m_transform.getPosition(), GSvector3(0, 0.8f, 0)), 0.5f);
	//Collision_Ptr obj = std::make_shared<CollisionActor>(shape, CollisionActorType::PLAYER);
	//obj->set_update([&](float deltaTime, Shape_Ptr _shape)
	//{
	//	GSvector3 target = m_transform.getPosition() + GSvector3(0.0f, 0.5f, 0.0f);
	//	_shape->transfer(target);
	//});
	////obj->set_draw([&](const Renderer& _renderer, Shape_Ptr _shape) { _shape->draw(_renderer); });
	//m_group->add(obj);
}

void Player::jumping(float _velocity)
{
	m_transform.translate_up(_velocity);
}

void Player::subActionStart()
{
	if (m_device->input()->jump())
	{
		GSvector3 nowPosition = GSvector3(0, m_transform.m_translate.y, 0);
		m_transform.translate(nowPosition);
		m_SubAction.initialize(SubActionType::JUMP);
		actionChange(std::make_shared<JumpState>());
		m_isGround = false;
		return;
	}

	if (m_device->input()->avoid())
	{
		m_status.down();
		actionChange(std::make_shared<DamageState>());
		/*if (m_Gauge.down(5))
		{
		m_SubAction.initialize(SubActionType::AVOID);
			m_avoid.initialize();
		actionChange(std::make_shared<AvoidState>());
		}*/
	}
}

void Player::moveStart()
{
	if (m_device->input()->move())
		actionChange(std::make_shared<MoveState>());
}
void Player::gaugeUp(float _scale)
{
	m_Gauge.up(_scale);
}

void Player::attackhoming(Enemy * _enemy)
{
	if (m_attackManager.isEnd())
	{
		return;
	}
	Math::Clamp clamp;

	if (_enemy == nullptr) return;
	if (m_device->input()->velocity().y >= 0)
	{
		m_transform.m_rotate = targetDirection(*_enemy);
	}

	float velocity = distanceActor(*_enemy) / 5.0f;
	velocity = clamp(m_Gauge.scale(velocity), 0.0f, distanceActor(*_enemy) - 1.0f);
	//velocity /= 5.0f;
	m_transform.translate_front(velocity);
}

void Player::homing()
{
	m_lockon->homing();
}

void Player::specialAttack()
{
	m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::SPECIALATTACK), true);
}

void Player::collisionChase(SpecialAttackCollision * _collision)
{
	_collision->chase(m_transform.m_translate);
}

void Player::gaugeAdd()
{
	m_Gauge.up(10);
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
	_attack.changeMotion(m_animatorOne, m_status.attackSpeed());
}

const bool Player::isNextAttack(const IAttack & _attack) const
{
	return _attack.isNextAttack(m_animatorOne);
}

const bool Player::isEndAttackMotion(const IAttack & _attack) const
{
	return _attack.isEndMotion(m_animatorOne);
}

void Player::moving(float deltaTime, bool isAnimation)
{
	float time = 1.0f;
	if (m_device->input()->walk())
	{
		time = 0.4f;
	}
	movement(deltaTime, 0.5f);
	if (!isAnimation)return;
	m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::RUN), true, true, true, time);
}


const bool Player::isJump() const
{
	return m_device->input()->jump();
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

const bool Player::isSlowAttack() const
{
	return m_device->input()->slowAttackTrigger();
}

const bool Player::isQuickAttack() const
{
	return m_device->input()->quickAttackTrigger();
}

const GSvector3 Player::inputDirection() const
{
	return m_transform.front();
}

void Player::actionChange(Action_Ptr _action)
{
	m_action = _action;
}

void Player::control()
{
	if (m_device->input()->gaugeAttack1())
	{
		m_SpecialSkillManager.initialize(SPECIALTYPE::RECOVERY);
	}
	if (m_device->input()->gaugeAttack2())
	{
		m_SpecialSkillManager.initialize(SPECIALTYPE::SUPERARMOR);
	}
	if (m_device->input()->gaugeAttack3())
	{
		if (m_SpecialSkillManager.initialize(SPECIALTYPE::SPECIALATTACK))
		{
			m_SpecialSkillManager.addAttackCollision(&m_collision);
		}
	}
	/*ボタン押したらAttackStateに切り替わる*/
	if (m_device->input()->quickAttackTrigger())
	{
		actionChange(std::make_shared<AttackState>());
		m_attackManager.initialize();
		m_isJumpAttack = !m_isGround;
		m_attackManager.Start(true);
		m_lockon->homing();
	}

	if (m_device->input()->slowAttackTrigger())
	{
		actionChange(std::make_shared<AttackState>());
		m_attackManager.initialize();
		m_isJumpAttack = !m_isGround;
		m_attackManager.Start(false);
		m_lockon->homing();
	}
}

void Player::look_at(CameraController * _camera, GSvector3 * _target)
{
	GSvector3 target = m_transform.m_translate;
	float distance = 0.0f;

	m_camera->lookAt_cameraTarget_player(target);
	m_camera->lookAt_cameraTarget_enemy(*_target);

	//仮
	distance = _target->distance(target);
	if (distance < 10)
	{
		_camera->change_cameraWork(E_CameraWorkID::LOCK_ON);
	}
	else
	{
		_camera->change_cameraWork(E_CameraWorkID::NORMAL);
	}
}

/**
* @fn
* @brief 動いていればMoveStateに切り替え、動いていなければStandStateに切り替える
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
	m_transform.m_rotate = GSquaternion(velocity.getYaw(), GSvector3(0, 1, 0));
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

const bool Player::isAvoid() const
{
	return m_device->input()->avoid();
}

const bool Player::isAnimationEnd() const
{
	return m_animatorOne.isEndCurrentAnimation();
}