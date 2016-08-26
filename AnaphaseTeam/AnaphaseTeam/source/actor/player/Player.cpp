#include "../../../header/actor/Player/Player.h"

#include "../../../header/actionstate/MoveState.h"
#include "../../../header/actionstate/StandState.h"
#include "../../../header/actionstate/JumpState.h"

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
	:Actor(Transform({0,0,5}), MODEL_ID::PLAYER, Sphere(GSvector3(0, 0, 0), 0), Actor_Tag::PLAYER),
	m_action(nullptr),
	m_SubAction()
{}
Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animator.initialize();

	m_animator.addAnimation(ANIMATION_ID::STAND, 77.f, 1.0f, true);
	m_animator.addAnimation(ANIMATION_ID::RUN, 78.f, 1.0f, true);

	m_animator.changeAnimation(ANIMATION_ID::STAND, false);
}
void Player::update(float deltatime)
{
	m_animator.changeAnimation(ANIMATION_ID::STAND, false);
	/*move(deltatime);
	jump(deltatime);
	chain(deltatime);*/

	m_SubAction.actionStart(this);
	m_SubAction.action(this,deltatime);

	control();

	m_action->action(this, deltatime);
	sphereChases(GSvector3(0, 1, 0));
	m_animator.update(deltatime);
}

void Player::draw(const Renderer & _renderer, const Camera & _camera)
{
	//æ‚è‚ ‚¦‚¸–³—‚â‚è’Ç]‚³‚¹‚é
	const_cast<Camera&>(_camera).lookAt(m_transform.getPosition(), m_transform.getYaw());
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	_renderer.getDraw3D().drawMesh(MODEL_ID::PLAYER, m_transform,m_animator, m_Color);
}

void Player::collisionGround(const Map & _map)
{
	GSvector3 intersect;
	//Œ»İ‚ÌˆÊ’u‚©‚ç‰º•ûŒü‚ÌRay‚ğì‚é
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

	//map‚É–„‚ß‚Ü‚ê‚Ä‚¢‚½‚çyÀ•W‚ğŒğ“_‚ÉˆÚ“®
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

}

void Player::attack(float deltaTime)
{
}

void Player::damage(float deltaTime)
{
}

void Player::move(float deltaTime)
{
	m_transform.rotationY(m_Input->rotate()*deltaTime * ROTATESPEED);

	GSvector3 forward(m_transform.front()*m_Input->vertical());
	GSvector3 side(m_transform.left()*m_Input->horizontal());
	m_transform.translate((forward - side)*MOVESPEED*deltaTime);
	if ((forward - side).length() > 0)m_animator.changeAnimation(ANIMATION_ID::RUN);
}

void Player::jump(float deltaTime)
{
	/*if (m_Input->jumpTrigger())
	{
		m_Jump.start();
	}*/
	//m_Jump.jumping(this, deltaTime);
}
void Player::jumping(float _velocity)
{
	m_transform.translateY(_velocity);
}

void Player::chainMove(const GSvector3 & _target, float _time)
{
	m_transform.setPosition(m_transform.getPosition().lerp(_target, _time));
}

void Player::subActionStart(TestJump* _jump,TestChainMove* _chainMove)
{
	if (m_Input->jumpTrigger())
	{
		_jump->start();
		actionChange(std::make_shared<JumpState>());
	}
	if (m_Input->chainTrigger())
	{
		_chainMove->start();
	}
}

void Player::actionChange(Action_Ptr _action)
{
	m_action = _action;
}

void Player::control()
{
	if (m_Input->move())
	{
		actionChange(std::make_shared<MoveState>());
	}
}
