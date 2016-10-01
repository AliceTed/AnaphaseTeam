#include "../../../header/scene/each/Option.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/Renderer.h"
Option::Option(GameDevice* _device)
	:m_device(_device),
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
	if (m_device->input()->jump())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void Option::draw(const Renderer & renderer)
{
	renderer.getDraw2D().textrue(TEXTURE_ID::OPTION_BACKGROUND, &GSvector2(0, 0));
	renderer.getDraw2D().textrue(TEXTURE_ID::PAD_A, &GSvector2(0, 0));
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
