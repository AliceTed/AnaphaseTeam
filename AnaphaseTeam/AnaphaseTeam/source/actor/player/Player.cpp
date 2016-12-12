#include "../../../header/actor/Player/Player.h"

#include "../../../header/state/player/AttackState.h"
#include "../../../header/state/player/DamageState.h"
#include "../../../header/state/player/MoveState.h"
#include "../../../header/state/player/StandState.h"
#include "../../../header/state/player/StepState.h"
#include "../../../header/state/player/SpecialAttackState.h"

#include "../../../header/state/player/SingleJumpState.h"
#include "../../../header/state/player/DoubleJumpState.h"
#include "../../../header/state/player/LimitFallState.h"
#include "../../../header/state/player/LandingRigidityState.h"

#include "../../../header/renderer/IRenderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/shape/Ray.h"
#include "../../../header/camera/CameraController.h"
#include "../../../header/camera/CameraWork/E_CameraWorkID.h"
#include "../../../header/math/Calculate.h"

#include "../../../header/camera/LockOn.h"
#include "../../../header/actor/Enemy/Enemy.h"
#include "../../../header/actor/Enemy/EnemyManager.h"

#include "../../../header/collision/PlayerAttackCollision.h"
#include "../../../header/collision/PlayerCollision.h"
#include "../../../header/collision/SpecialAttackCollision.h"
#include "../../../header/renderer/define/SpriteRectRenderDesc.h"

#include "../../../header/specialskill/Recovery.h"
#include "../../../header/specialskill/SpecialAttack.h"
#include "../../../header/specialskill/SuperArmor.h"

#include "../../../header/data/id/TEXTURE_ID.h"
#include "../../../header/ui/SPGaugeUI.h"
#include "../../../header/ui/HPGaugeUI.h"
#include "../../../header/ui/UIManager.h"
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
	m_Gauge(std::make_shared<Gauge>()),
	m_lockon(_lockon),
	m_scythe(),
	m_specialskill(m_Gauge.get()),
	m_target(0, 0, 0),
	m_specialUI(std::make_shared<SpecialSkillUI>(GSvector2(1100, 80))),
	m_homing(),
	m_timer(1.5f),
	m_isLockOn(false)
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

	m_status.initialize();
	m_scythe.initialize();
	m_target = m_transform.m_translate;
	m_combo.initialize();

	m_specialskill.clear();
	m_specialskill.add(SPECIALSKILL_TYPE::RECOVERY, new Recovery());
	m_specialskill.add(SPECIALSKILL_TYPE::SPECIALLATTACK, new SpecialAttack(this));
	m_specialskill.add(SPECIALSKILL_TYPE::SUPERARMOR, new SuperArmor());
	m_specialUI->initialize();
	m_Gauge->initialize();
	UIManager::getInstance().add(EUI::HP, std::shared_ptr<HPGaugeUI>(new HPGaugeUI(GSvector2(0, 10), m_status)));
	UIManager::getInstance().add(EUI::GAUGE, m_Gauge);
	UIManager::getInstance().add(EUI::SPICON, m_specialUI);
	m_timer.initialize();
	m_isLockOn = false;
}

void Player::update(float deltatime)
{
	action(deltatime);
	m_animatorOne.update(deltatime);
	m_scythe.update(deltatime, m_animatorOne, m_transform);
	m_status.change(*m_Gauge.get());
	m_specialskill.update(deltatime);
	m_timer.update(deltatime);

	m_collision.update(deltatime);
	if (m_isDead = m_status.getHp() <= 0)
	{
		m_collision.clear();
	}
}

void Player::draw(IRenderer *_renderer)
{
	m_animatorOne.draw(_renderer, m_transform);
	m_collision.draw(_renderer);
	m_scythe.draw(_renderer);
	m_specialskill.draw(_renderer);
}
void Player::finish()
{
	UIManager::getInstance().release(EUI::SIZE);
}

void Player::targetFind(EnemyManager * _enemys)
{
	if (m_isLockOn) return;
	m_lockon->nearEnemyFind(_enemys);
}

const float Player::stepDistance() const
{
	return distanceActor(*m_lockon->getTarget()) - 1.0f;
}

void Player::lookTarget()
{
	m_transform.m_rotate = targetDirection(*m_lockon->getTarget());
}

void Player::aerialTracking(float _velocity)
{
	if (isTargetAerial(*m_lockon->getTarget()))
	{
		m_transform.translate_up(_velocity);
	}
}

void Player::damage(const AttackStatus & _attackStatus)
{
	m_status.down(_attackStatus.m_power);
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
		changeState(ACTOR_STATE::STEP);
	}
}
void Player::homing()
{
	m_homing.start(this, m_lockon->getTarget(), m_transform, *m_Gauge, m_target, m_isLockOn);
}

void Player::createAttackCollision()
{
	Collision_Ptr act = Collision_Ptr(new PlayerAttackCollision(this));
	m_collision.add(act);
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
		m_specialUI->open();
		m_specialskill.canSelectCheck(m_specialUI.get());
		if (GameDevice::getInstacnce().input()->gaugeAttack1())
		{
			m_specialskill.start(SPECIALSKILL_TYPE::RECOVERY);
			m_specialUI->select(SPECIALSKILL_TYPE::RECOVERY);
		}
		if (GameDevice::getInstacnce().input()->gaugeAttack2())
		{
			m_specialskill.start(SPECIALSKILL_TYPE::SUPERARMOR);
			m_specialUI->select(SPECIALSKILL_TYPE::SUPERARMOR);
		}
		if (GameDevice::getInstacnce().input()->gaugeAttack3())
		{
			m_specialskill.start(SPECIALSKILL_TYPE::SPECIALLATTACK);
			m_specialUI->select(SPECIALSKILL_TYPE::SPECIALLATTACK);
		}
		return;
	}
	m_specialUI->close();
	/*ボタン押したらAttackStateに切り替わる*/
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
	if (m_timer.isEnd() || m_lockon->getTarget()->isDeadState())
	{
		m_isLockOn = false;
	}
	GSvector3 position = m_transform.m_translate;

	m_camera->lookAt_cameraTarget_player(position);
	m_camera->lookAt_cameraTarget_enemy(*_target);

	_camera->change_cameraWork(E_CameraWorkID::TEST);

	/*if (m_isLockOn)
	{
		_camera->change_cameraWork(E_CameraWorkID::LOCK_ON);
	}
	else
	{
		_camera->change_cameraWork(E_CameraWorkID::NORMAL);
	}*/
}
void Player::createStates()
{
	registerState(ACTOR_STATE::ATTACK, new AttackState(this));
	registerState(ACTOR_STATE::DAMAGE, new DamageState(this));
	registerState(ACTOR_STATE::RUN, new MoveState(this));
	registerState(ACTOR_STATE::STAND, new StandState(this));
	registerState(ACTOR_STATE::STEP, new StepState(this));
	registerState(ACTOR_STATE::SPECIALATTACK, new SpecialAttackState(this));

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
