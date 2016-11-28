#include "../../../header/scene/each/Ending.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/device/GameDevice.h"
Ending::Ending()
	:m_IsEnd(false),
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

void Ending::update(float _deltaTime)
{
	if (m_change.update(_deltaTime))return;
	//決定ボタン作ってもいいかも
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void Ending::draw(const Renderer & _renderer)
{
	_renderer.getDraw2D().textrue(TEXTURE_ID::CLEAR, &GSvector2(0, 0));
	m_change.draw(_renderer);
}

void Ending::finish()
{
}

const SceneMode Ending::next() const
{
	return m_change.next();
}

const bool Ending::isEnd() const
{
	return m_change.isEnd();
}

const bool Ending::isExit() const
{
	return false;
}
