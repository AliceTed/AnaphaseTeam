#include "../../../header/scene/each/Ending.h"

Ending::Ending()
	:m_IsEnd(false)
{
}
Ending::~Ending()
{
}

void Ending::initialize()
{

	m_IsEnd = false;
}

void Ending::update(float deltaTime)
{
}

void Ending::draw(const Renderer & renderer)
{
}

void Ending::finish()
{
}

const SceneMode Ending::next() const
{
	return SceneMode::TITLE;
}

const bool Ending::isEnd() const
{
	return m_IsEnd;
}
