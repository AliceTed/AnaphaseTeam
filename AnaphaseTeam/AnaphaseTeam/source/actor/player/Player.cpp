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
	:Actor(Transform({0,0,5}), ANIMATION_ID::KENDO, SKELETON_ID::KENDO, Sphere(GSvector3(0, 0, 0), 0), Actor_Tag::PLAYER),
	m_action(nullptr),
	m_Jump(),
	m_ChainMove()
{}
Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animator.initialize();
	m_animator.addAnimation_A(PLAYERACTION_ID::STAND, true);
	m_animator.addAnimation_A(PLAYERACTION_ID::RUN, true);
	m_animator.changeAnimation_A(PLAYERACTION_ID::STAND, false);
}
void Player::update(float deltatime)
{
	m_animator.changeAnimation_A(PLAYERACTION_ID::STAND, false);
	/*move(deltatime);
	jump(deltatime);
	chain(deltatime);*/
	control();
	m_action->action(this, deltatime);
	sphereChases(GSvector3(0, 1, 0));
	m_animator.update_A(deltatime);
}

void Player::draw(const Renderer & _renderer, const Camera & _camera)
{
	//取りあえず無理やり追従させる
	const_cast<Camera&>(_camera).lookAt(m_transform.getPosition(), m_transform.getYaw());
	if (!isInsideView(_camera))
	{
		return;
	}
	alphaBlend(_camera);
	m_animator.bind_A();
	_renderer.getDraw3D().drawMesh(MODEL_ID::PLAYER, m_transform.getMatrix4(), m_Color);
}

void Player::collisionGround(const Map & _map)
{
	GSvector3 intersect;
	//現在の位置から下方向のRayを作る
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
	m_Jump.groundHit();

	//mapに埋め込まれていたらy座標を交点に移動
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
	if ((forward - side).length() > 0)m_animator.changeAnimation_A(PLAYERACTION_ID::RUN, false);
}

void Player::jump(float deltaTime)
{
	/*if (m_Input->jumpTrigger())
	{
		m_Jump.start();
	}*/
	m_Jump.jumping(this, deltaTime);
}

void Player::chain(float deltaTime)
{
	/*if (m_Input->chainTrigger())
	{
		m_ChainMove.start();
	}*/
	m_ChainMove.movement(deltaTime, this);
}

void Player::jumping(float _velocity)
{
	m_transform.translateY(_velocity);
}

void Player::chainMove(const GSvector3 & _target, float _time)
{
	//一度加速度にしているが　lerpをそのままsetPosしても良い
	//GSvector3 pos = m_transform.getPosition();
	//GSvector3 velocity = pos.lerp(_target, _time) - pos;
	//m_transform.translate(velocity);

	/*
	加速度にすると加算なので外部の影響を受けるが
	代入なら影響を受けない
	*/
	m_transform.setPosition(m_transform.getPosition().lerp(_target, _time));
}

void Player::actionChange(Action_Ptr _action)
{
	m_action = _action;
}

void Player::control()
{
	if (m_Input->jumpTrigger())
	{
		m_Jump.start();
		actionChange(std::make_shared<JumpState>());
	}
	if (m_Input->chainTrigger())
	{
		m_ChainMove.start();
	}
	if (m_Input->move())
	{
		actionChange(std::make_shared<MoveState>());
	}
}
