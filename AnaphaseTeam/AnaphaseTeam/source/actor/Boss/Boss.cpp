//#include "../../../header/actor/Boss/Boss.h"
//#include "../../../header/shape/Sphere.h"
//#include "../../../header/camera/Camera.h"
//#include "../../../header/renderer/Renderer.h"
//#include "../../../header/math/Calculate.h"
//#include "../../../header/actor/Player/Player.h"
//#include "../../../header/camera/CameraController.h"
//
//Boss::Boss() :
//	Actor(
//		Transform({ 0,0,0 }, GSquaternion(0, 0, 0, 1)),
//		MODEL_ID::ENEMY,
//		Sphere(GSvector3(0, 7, 0), 7.0f),
//		Actor_Tag::BOSS
//		),
//	m_core(GSvector3(0, 0, 0), 1),
//	m_corecolor(1, 1, 1, 1),
//	m_color(1, 1, 1, 1),
//	m_state(State::STAND)
//{
//}
//
//Boss::~Boss()
//{
//}
//
//void Boss::initialize()
//{
//}
//
//void Boss::update(float deltatime)
//{
//	pos = getAnimEachPos();
//	m_value = rand();
//	enemyAttack();
//}
//
//void Boss::draw(const Renderer& _renderer, const Camera& _camera)
//{
//	FALSE_RETURN(isInsideView(_camera));
//	m_animatorOne.draw(_renderer, m_transform, m_color);
//}
//
//void Boss::look_at(CameraController* _camera, Player* _player)
//{
//	GSvector3 target = m_transform.m_translate;
//	_player->look_at(_camera, &target);
//
//	if (m_value % 50 == 0)
//		dirCalc(_player);
//}
//
//const GSvector3 Boss::getPosition() const
//{
//	return m_transform.m_translate;
//}
//
//vector<GSvector3> Boss::getAnimEachPos()
//{
//	vector<GSvector3> res;
//
//	return res;
//}
//
//void Boss::enemyAttack()
//{
//
//	if (m_value % 100 == 0)
//	{
//		m_state = State::ATTACK;
//
//		m_animatorOne.changeAnimation(0);
//	}
//	if (m_animatorOne.isEndCurrentAnimation())
//	{
//		m_state = State::STAND;
//		m_animatorOne.changeAnimation(1, true);
//	}
//}
//
//void Boss::dirCalc(Player* _player)
//{
//	if (m_state == State::STAND)
//	{
//		/*GSvector3 vector = _player->getPosition() - m_transform.m_translate;
//		float radian = atan2(vector.x, vector.z);
//		float degree = radian * 180.0f / M_PI;
//		m_transform.m_rotate = GSquaternion(degree, GSvector3(0, 1, 0));*/
//	}
//}
