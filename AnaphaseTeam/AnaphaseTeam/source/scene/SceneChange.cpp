#include "../../header/scene/SceneChange.h"

SceneChange::SceneChange()
	:m_isEnd(false),
	m_next(),
	m_Fade()
{
}

SceneChange::~SceneChange()
{
}

void SceneChange::initialize()
{
	m_isEnd = false;
	m_Fade.initialize();
}

const bool SceneChange::update(float deltaTime)
{
	m_Fade.update(deltaTime);
	return !m_Fade.isEnd();
}

void SceneChange::draw(const Renderer & _renderer)
{
	m_Fade.draw(_renderer);
}

void SceneChange::begin(float _fadetime)
{
	m_Fade.initialize();
	m_Fade.start(GScolor(1, 1, 1, 1), GScolor(0, 0, 0, 0),_fadetime);
}

void SceneChange::end(SceneMode _next, float _fadetime)
{
	m_next = _next;
	m_Fade.start(GScolor(0, 0, 0, 0), GScolor(1, 1, 1, 1), _fadetime, [&]() {m_isEnd = true;});
}
const SceneMode SceneChange::next() const
{
	return m_next;
}

const bool SceneChange::isEnd() const
{
	return m_isEnd;
}
