#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/GameDevice.h"
Ending::Ending(GameDevice* _device)
	:m_IsEnd(false),
	m_device(_device),
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
	//Œˆ’èƒ{ƒ^ƒ“ì‚Á‚Ä‚à‚¢‚¢‚©‚à
	if (m_device->input()->jump())
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
