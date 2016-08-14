#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"
Ending::Ending(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input)
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
