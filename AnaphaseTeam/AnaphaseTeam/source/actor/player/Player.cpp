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
#include "../../../header/camera/CameraController.h"
#include "../../../header/math/Calculate.h"
const float Player::MOVESPEED = 0.3f;
const float Player::ROTATESPEED = -2.0f;
const float Player::WALKSPEED = 0.1f;
#include "../../../header/data/CastID.h"

Player::Player(const Input* _input, Camera * _camera)
	:Actor(
		Transform({ 0,0,-30 }),
		MODEL_ID::PLAYER,
		Sphere(GSvector3(0, 0, 0), 0),
		Actor_Tag::PLAYER
		),
	m_action(nullptr),
	m_SubAction(this),
	m_attackManager(),
	m_isGround(false),
	m_camera(_camera),
	m_status(),
	m_isJumpAttack(false),
	m_group(std::make_shared<CollisionGroup>(this)),
	m_matrix()
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
}

void Player::update(float deltatime)
{
	m_action->action(this, deltatime);
	sphereChases(GSvector3(0, 1, 0));
	m_animatorOne.update(deltatime);
//	m_animatorOne.getAnimMatrix(m_matrix.get());
}

void Player::draw(const Renderer & _renderer, const Camera & _camera)
{
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	_renderer.getDraw3D().drawMesh_calcu(MODEL_ID::PLAYER, m_transform, m_matrix.get(),m_animatorOne, m_Color);
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
	m_SubAction.update(deltaTime);
	if (m_SubAction.isEnd(SubActionType::JUMP))
	{
		m_isJumpAttack = false;
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
		return;
	}

	if (m_Input->avoidTrigger())
	{
		m_SubAction.initialize(SubActionType::AVOID);
		actionChange(std::make_shared<AvoidState>());
	}
}

void Player::startJump(JumpControl * _control, float _scale)
{
	m_status.giveJumpPower(_control, _scale);
}

void Player::jumpMotion(JumpControl& _control, ANIMATION_ID _id)
{
	_control.changeMotion(m_animatorOne, _id);
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
	float speed = m_status.getMoveSpeed(false, false);
	float time = 1.0f;
	if (m_Input->walk())
	{
		speed = m_status.getWalkSpeed();
		time = 0.4f;
	}
	movement(deltaTime, speed);
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
	return m_isJumpAttack;
}

const bool Player::isEndAttack() const
{
	return m_attackManager.isEnd();
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
	return m_transform.front();
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
		m_isJumpAttack = !m_isGround;

		//無理やり攻撃中に球判定をキャラの前に作る
		float radius = 1.5f;
		GSvector3 front = m_transform.front()*(radius*1.5f);
		GSvector3 pos(m_transform.getPosition() + front);
		pos.y += 1.0f;
		Shape_Ptr shape = std::make_shared<Sphere>(pos, radius);
		Collision_Ptr actor= std::make_shared<CollisionActor>(shape, CollisionActorType::PLAYER_ATTACK);
		actor->set_dead([&]()->bool{return m_attackManager.isEnd();});
		actor->set_draw([](const Renderer& _renderer, Shape_Ptr _shape) { _shape->draw(_renderer);});
		m_group->add(actor);
	}
}

void Player::look_at(CameraController * _camera, GSvector3 * _target)
{
	GSvector3 target = m_transform.getPosition();
	_camera->special_move1(&target, _target, 10.0f, 1.5f);
}

void Player::buildup()
{
	m_status.powerUp();
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

void Player::rotate(float deltaTime, Transform & _transform)
{
	GSvector3 forward(_transform.front()*-m_Input->vertical());
	GSvector3 side(_transform.left()*m_Input->horizontal());
	GSvector3 velocity = forward + side;
	Math::ATan atan;
	float degree = atan(velocity.x, velocity.z);
	m_transform.setYaw(degree);
}

void Player::movement(float deltaTime, float _speed)
{
	Transform transform = m_camera->transform();
	if (m_Input->move())
		rotate(deltaTime, transform);
	int speed = 1;
	if (!m_Input->move())speed = 0;
	GSvector3 forward(m_transform.front()*speed);
	m_transform.translate(forward*deltaTime*_speed);


}
