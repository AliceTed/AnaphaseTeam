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
#include "../../../header/camera/CameraWork/E_CameraWorkID.h"
#include "../../../header/math/Calculate.h"

#include "../../../header/camera/LockOn.h"
#include "../../../header/actor/Enemy/Enemy.h"

#include "../../../header/collision/PlayerAttackCollision.h"
#include "../../../header/collision/PlayerCollision.h"
#include "../../../header/collision/SpecialAttackCollision.h"
const float Player::ROTATESPEED = -2.0f;
Player::Player(Camera * _camera, LockOn* _lockon)
	:Actor(
		Transform({ 0,0,-15 }, GSquaternion(0, 0, 0, 1)),
		MODEL_ID::PLAYER,
		Actor_Tag::PLAYER
	),
	m_combo(this),
	m_camera(_camera),
	m_status(),
	m_Gauge(),
	m_lockon(_lockon),
	m_scythe(),
	m_SpecialSkillManager(m_Gauge, this),
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
	m_combo.initialize();
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
	if (m_isDead = m_status.getHp() <= 0)
	{
		m_collision.clear();
	}
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
AttackStatus Player::status()
{
	return m_combo.getStatus();
}
void Player::jumping(float _velocity)
{
	m_transform.translate_up(_velocity);
}

void Player::subActionStart()
{
	if (GameDevice::getInstacnce().input()->specialSkillMode())return;
	if (GameDevice::getInstacnce().input()->jump())
	{	
		changeState(ACTOR_STATE::SINGLEJUMP);
		return;
	}

	if (GameDevice::getInstacnce().input()->avoid())
	{
		if (m_Gauge.down(5))
		{
			changeState(ACTOR_STATE::STEP);

		}
	}
}

//void Player::gaugeUp(float _scale)
//{
//	m_Gauge.up(_scale);
//}
void Player::homing()
{
	Enemy* target = m_lockon->getTarget();
	if (target == nullptr) return;
	m_transform.m_rotate = targetDirection(*target);
	float velocity = distanceActor(*target) / 5.0f;
	Math::Clamp clamp;
	velocity = clamp(m_Gauge.scale(velocity), 0.0f, distanceActor(*target) - 1.0f);
	this->target = m_transform.m_translate + (m_transform.front() * velocity);
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
	Collision_Ptr act =Collision_Ptr(new PlayerAttackCollision(this));
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

void Player::attackmotion(Attack & _attack)
{
	_attack.changeMotion(m_animatorOne, m_status.attackSpeed());
}
void Player::control()
{
	if (GameDevice::getInstacnce().input()->specialSkillMode())
	{
		if (GameDevice::getInstacnce().input()->gaugeAttack1())
		{
			m_SpecialSkillManager.initialize(SPECIALTYPE::RECOVERY);
		}
		if (GameDevice::getInstacnce().input()->gaugeAttack2())
		{
			m_SpecialSkillManager.initialize(SPECIALTYPE::SUPERARMOR);
		}
		if (GameDevice::getInstacnce().input()->gaugeAttack3())
		{
			m_SpecialSkillManager.initialize(SPECIALTYPE::SPECIALATTACK);
		}
		//return;
	}
	/*ƒ{ƒ^ƒ“‰Ÿ‚µ‚½‚çAttackState‚ÉØ‚è‘Ö‚í‚é*/
	if (GameDevice::getInstacnce().input()->quickAttackTrigger())
	{
		changeState(ACTOR_STATE::ATTACK);
		m_combo.start(false);
	}

	if (GameDevice::getInstacnce().input()->slowAttackTrigger())
	{
		changeState(ACTOR_STATE::ATTACK);
		m_combo.start(true);
	}
}

void Player::look_at(CameraController * _camera, GSvector3 * _target)
{
	GSvector3 target = m_transform.m_translate;
	//by —L•y
	float distance;

	m_camera->lookAt_cameraTarget_player(target);
	m_camera->lookAt_cameraTarget_enemy(*_target);

	//by —L•y
	distance = target.distance(*_target);
	if (distance < 10)
	{
		_camera->change_cameraWork(E_CameraWorkID::LOCK_ON);
	}
	else
	{
		_camera->change_cameraWork(E_CameraWorkID::NORMAL);
	}
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
	GSvector2 dir = GameDevice::getInstacnce().input()->velocity();
	GSvector3 forward(_transform.front()*-dir.y);
	GSvector3 side(_transform.left()*dir.x);
	GSvector3 velocity = forward + side;
	m_transform.m_rotate = GSquaternion(velocity.getYaw(), GSvector3(0, 1, 0));
}

void Player::movement(float deltaTime, float _speed)
{
	Transform transform = m_camera->transform();
	if (GameDevice::getInstacnce().input()->move())
		rotate(deltaTime, transform);
	int speed = 1;
	if (!GameDevice::getInstacnce().input()->move())speed = 0;
	GSvector3 forward(m_transform.front()*speed);
	m_transform.translate(forward*deltaTime*_speed);
}
