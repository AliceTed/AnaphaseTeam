#include "../../../header/actor/Player/Player.h"

#include "../../../header/state/player/AttackState.h"
#include "../../../header/state/player/DamageState.h"
#include "../../../header/state/player/MoveState.h"
#include "../../../header/state/player/StandState.h"
#include "../../../header/state/player/StepState.h"

#include "../../../header/state/player/SingleJumpState.h"
#include "../../../header/state/player/DoubleJumpState.h"
#include "../../../header/state/player/LimitFallState.h"
#include "../../../header/state/player/LandingRigidityState.h"

#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/shape/Ray.h"
#include "../../../header/camera/CameraController.h"
#include "../../../header/math/Calculate.h"

#include "../../../header/camera/LockOn.h"
#include "../../../header/actor/Enemy/Enemy.h"

#include "../../../header/collision/PlayerAttackCollision.h"
#include "../../../header/collision/PlayerCollision.h"
#include "../../../header/collision/SpecialAttackCollision.h"
const float Player::ROTATESPEED = -2.0f;
Player::Player(GameDevice* _device, Camera * _camera, LockOn* _lockon)
	:Actor(
		Transform({ 0,0,-15 }, GSquaternion(0, 0, 0, 1)),
		MODEL_ID::PLAYER,
		Actor_Tag::PLAYER
	),
	m_device(_device),
	m_attackManager(),
	m_camera(_camera),
	m_status(),
	m_Gauge(),
	m_lockon(_lockon),
	m_scythe(),
	m_SpecialSkillManager(m_Gauge, this, m_device),
	target(0, 0, 0)
{
}

Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	createStates();
	changeState(ACTOR_STATE::STAND);
	Collision_Ptr actor = std::make_shared<PlayerCollision>(this);
	m_collision.add(actor);
	m_Gauge.initialize();
	m_status.initialize();
	m_scythe.initialize();
	m_SpecialSkillManager.initialize(SPECIALTYPE::NONE);
	target = m_transform.m_translate;
}

void Player::update(float deltatime)
{
	action(deltatime);
	m_animatorOne.update(deltatime);
	m_scythe.update(deltatime, m_animatorOne, m_transform);
	m_status.change(m_Gauge);
	m_SpecialSkillManager.update(deltatime);
	m_SpecialSkillManager.endCheck();

	m_collision.update(deltatime);
	m_Gauge.update(deltatime);
	m_isDead = m_status.getHp() <= 0;
}

void Player::draw(const Renderer & _renderer)
{
	m_animatorOne.draw(_renderer, m_transform);
	m_collision.draw(_renderer);
	m_Gauge.draw(_renderer);
	m_scythe.draw(_renderer);
	_renderer.getDraw2D().textrue(TEXTURE_ID::BLACK, &GSvector2(0, 0),
		&GSrect(0, 0, 1000, 30), &GSvector2(0, 0), &GSvector2(1, 1), 0.0f);
	_renderer.getDraw2D().textrue(TEXTURE_ID::WHITE, &GSvector2(0, 0),
		&GSrect(0, 0, m_status.getHp() * 10.0f, 30), &GSvector2(0, 0), &GSvector2(1, 1), 0.0f, &GScolor(0.0f, 1.0f, 0.0f, 1.0f));

	m_SpecialSkillManager.draw(_renderer);
}
void Player::jumping(float _velocity)
{
	m_transform.translate_up(_velocity);
}

void Player::subActionStart()
{
	if (m_device->input()->specialSkillMode())return;
	if (m_device->input()->jump())
	{	
		changeState(ACTOR_STATE::SINGLEJUMP);
		return;
	}

	if (m_device->input()->avoid())
	{
		if (m_Gauge.down(5))
		{
			changeState(ACTOR_STATE::STEP);
		}
	}
}

void Player::gaugeUp(float _scale)
{
	m_Gauge.up(_scale);
}

void Player::attackHoming(Enemy * _enemy)
{
	Math::Clamp clamp;

	if (_enemy == nullptr) return;
	/*if (m_device->input()->velocity().y >= 0)
	{
		m_transform.m_rotate = targetDirection(*_enemy);
	}*/
	m_transform.m_rotate = targetDirection(*_enemy);
	float velocity = distanceActor(*_enemy) / 5.0f;
	velocity = clamp(m_Gauge.scale(velocity), 0.0f, distanceActor(*_enemy) - 1.0f);
	target = m_transform.m_translate + (m_transform.front() * velocity);
	//gsVector3Lerp(&m_transform.m_translate, &m_transform.m_translate, &target, 0.1f);
	//m_transform.translate_front(velocity);
}

void Player::homing()
{
	m_lockon->homing();
}
void Player::specialAttack()
{
	m_animatorOne.changeAnimation(static_cast<GSuint>(ANIMATION_ID::SPECIALATTACK));
	m_SpecialSkillManager.addAttackCollision(&m_collision);
}

void Player::gaugeAdd()
{
	m_Gauge.up(10);
}

void Player::createAttackCollision()
{
	GSvector3 p = target + m_transform.front();
	p.y += 1.f;
	Collision_Ptr act = std::make_shared<PlayerAttackCollision>(p, m_animatorOne.getNextAnimationEndTime() / 60.0f, m_status.attackSpeed());
	m_collision.add(act);
}
void Player::hpDown()
{
	m_status.down();
}

void Player::recovery()
{
	m_SpecialSkillManager.recovery(m_status);
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
void Player::control()
{
	if (m_device->input()->specialSkillMode())
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
			m_SpecialSkillManager.initialize(SPECIALTYPE::SPECIALATTACK);
		}
		//return;
	}
	/*ƒ{ƒ^ƒ“‰Ÿ‚µ‚½‚çAttackState‚ÉØ‚è‘Ö‚í‚é*/
	if (m_device->input()->quickAttackTrigger())
	{
		changeState(ACTOR_STATE::ATTACK);
		m_attackManager.initialize();
		m_lockon->homing();
		m_attackManager.Start(true, this);
	}


	if (m_device->input()->slowAttackTrigger())
	{
		changeState(ACTOR_STATE::ATTACK);
		m_attackManager.initialize();
		m_lockon->homing();
		m_attackManager.Start(false, this);
	}
}

void Player::look_at(CameraController * _camera, GSvector3 * _target)
{
	GSvector3 target = m_transform.m_translate;

	m_camera->lookAt_cameraTarget_player(target);
	m_camera->lookAt_cameraTarget_enemy(*_target);

	_camera->special_move1(&target, _target, 10.0f, 1.5f);
}
void Player::createStates()
{
	registerState(ACTOR_STATE::ATTACK, new AttackState(this));
	registerState(ACTOR_STATE::DAMAGE, new DamageState(this));
	registerState(ACTOR_STATE::RUN, new MoveState(this));
	registerState(ACTOR_STATE::STAND, new StandState(this));
	registerState(ACTOR_STATE::STEP, new StepState(this));

	registerState(ACTOR_STATE::SINGLEJUMP, new SingleJumpState(this));
	registerState(ACTOR_STATE::DOUBLEJUMP, new DoubleJumpState(this));
	registerState(ACTOR_STATE::LIMITFALL, new LimitFallState(this));
	registerState(ACTOR_STATE::LANDINGRIGIDITY, new LandingRigidityState(this));
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
