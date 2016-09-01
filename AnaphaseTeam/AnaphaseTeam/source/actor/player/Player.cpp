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

Player::Player(const Input* _input)
	:Actor(Transform({ 0,0,5 }), MODEL_ID::PLAYER, Sphere(GSvector3(0, 0, 0), 0), Actor_Tag::PLAYER),
	m_action(nullptr),
	m_SubAction(),
	m_ChainMove()
{}
Player::~Player()
{}
void Player::initialize()
{
	Actor::initialize();
	actionChange(std::make_shared<StandState>());
	m_animatorOne.initialize();

	/*m_animator.addAnimation(ANIMATION_ID::STAND, 1.0f, true);
	m_animator.addAnimation(ANIMATION_ID::RUN, 1.0f, true);
	m_animator.addAnimation(ANIMATION_ID::JUMPUP, 1.0f, true);
	m_animator.addAnimation(ANIMATION_ID::LANDING);
	m_animator.addAnimation(ANIMATION_ID::ATTACK, 1.4f);*/

	m_animatorOne.changeAnimation(ANIMATION_ID::STAND,true,true);
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
	
	m_SubAction.groundHit();
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
	subActionStart();
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true,true);
	if (m_Input->move())
	{
		actionChange(std::make_shared<MoveState>());
	}
  	control();
}
void Player::attack(float deltaTime)
{
	m_animatorOne.changeAnimation(ANIMATION_ID::ATTACK);
	if (m_animatorOne.isEndCurrentAnimation())
	{
		actionChange(std::make_shared<StandState>());
}

}

void Player::damage(float deltaTime)
{
}
void Player::move(float deltaTime)
{
	movement(deltaTime);
	subActionStart();
	m_animatorOne.changeAnimation(ANIMATION_ID::RUN, true,true);
	if (!m_Input->move())
	{
		actionChange(std::make_shared<StandState>());
	}
	control();
}
void Player::jump(float deltaTime)
{
	m_SubAction.action(this, deltaTime);
	if (m_Input->jumpTrigger())
	{
		m_SubAction.jumpStart();
	}
}
void Player::chain(float deltaTime)
{
	m_ChainMove.movement(deltaTime, this);
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
	if (m_Input->chainTrigger())
	{
		//	_chainMove->start();
		//m_SubAction.chainMoveStart();
		m_SubAction.restrictionFall();
	}
	if (m_Input->jumpTrigger())
	{
		m_SubAction.jumpInitialize();
		actionChange(std::make_shared<JumpState>());
		m_SubAction.jumpStart();
	}
	
}
//ジャンプ中のアニメーション
void Player::jumpUp()
{
	m_animatorOne.changeAnimation(ANIMATION_ID::JUMPUP, false);
}
//着地のアニメーション
void Player::jumpRigor()
{
	m_animatorOne.changeAnimation(ANIMATION_ID::LANDING, false);
}
void Player::actionChange(Action_Ptr _action)
{
	m_action = _action;
}

void Player::control()
{
	/*subActionStart();
	if (m_Input->move())
	{
		actionChange(std::make_shared<MoveState>());
	}*/
	/*ボタン押したらAttackStateに切り替わる*/
	if (m_Input->attckTrigger())
	{
		//m_attackDicision = true;
		actionChange(std::make_shared<AttackState>());
	}
}

void Player::movement(float deltaTime)
{
	m_transform.rotationY(m_Input->rotate()*deltaTime * ROTATESPEED);

	GSvector3 forward(m_transform.front()*m_Input->vertical());
	GSvector3 side(m_transform.left()*m_Input->horizontal());
	m_transform.translate((forward - side)*MOVESPEED*deltaTime);
}
