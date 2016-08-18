#include "../../header/actor/TestChainMove.h"
#include "../../header/actor/TestPlayer.h"

const float TestChainMove::MOVESPEED=0.5f;
TestChainMove::TestChainMove()
	:m_isChainMove(false),
	m_Target(0, 0, 0),
	m_Timer(1.0f)
{
}

TestChainMove::~TestChainMove()
{
}

void TestChainMove::start()
{
    /*
	��肠�������_
	���b�N�I�����̃^�[�Q�b�g�ɔ���(Ray�܂��͋��Ȃ�)���΂�
	target�����߂�
	m_target��Actor�ɂ����ق����悳��
	*/
	m_Target = GSvector3(0, 0, 0);
	m_isChainMove = true;
	m_Timer.initialize();
}

void TestChainMove::movement(float deltaTime, TestPlayer* _player)
{
	if (!m_isChainMove)return;

	m_Timer.accept([&](float _time) {_player->chainMove(m_Target, _time);});
	m_Timer.update(deltaTime / _player->distance(m_Target)*MOVESPEED);
	m_isChainMove = !m_Timer.isEnd();
}
