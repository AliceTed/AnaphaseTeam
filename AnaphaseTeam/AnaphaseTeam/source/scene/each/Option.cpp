#include "../../../header/scene/each/Option.h"
#include "../../../header/device/Input.h"
Option::Option(Input * _input)
	:m_input(_input),
	m_change()
{
}

Option::~Option()
{
}

void Option::initialize()
{
	m_change.initialize();
	m_change.begin();
}

void Option::update(float deltaTime)
{
	if (m_change.update(deltaTime))return;

}

void Option::draw(const Renderer & renderer)
{

	m_change.draw(renderer);
}

void Option::finish()
{
}

const SceneMode Option::next() const
{
	return m_change.next();
}

const bool Option::isEnd() const
{
	return m_change.isEnd();
}

const bool Option::isExit() const
{
	return false;
}
