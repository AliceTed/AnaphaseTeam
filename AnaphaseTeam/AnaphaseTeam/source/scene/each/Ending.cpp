#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/Input.h"
Ending::Ending(const Input* _input)
	:m_IsEnd(false),
	m_Input(_input),
	m_change()
{
}
Ending::~Ending()
{
}

void Ending::initialize()
{
	m_IsEnd = false;
	m_change.initialize();
	m_change.begin();
}

void Ending::update(float deltaTime)
{
	if (m_Input->isJoyTriggerA())
	{
		m_IsEnd = true;
	}
}

void Ending::draw(const Renderer & renderer)
{
	renderer.getDraw2D().textrue(TEXTURE_ID::CLEAR, &GSvector2(0, 0));
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

const bool Ending::isExit() const
{
	return false;
}
