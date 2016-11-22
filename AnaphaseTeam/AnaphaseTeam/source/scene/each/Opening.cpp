#include "../../../header/scene/each/Opening.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/Renderer.h"
Opening::Opening(GameDevice * _device)
	:m_device(_device),
	m_change(),
	m_lerp(GScolor(1,1,1,0))
{
}

Opening::~Opening()
{
}

void Opening::initialize()
{
	m_change.initialize();
	m_change.begin();
	m_lerp.start(GScolor(1,1,1,0), GScolor(1,1,1,1),7.0f);
}

void Opening::update(float deltaTime)
{
	if (m_change.update(deltaTime))return;
	m_lerp.update(deltaTime);
	if (m_lerp.isEnd()||m_device->input()->jump())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void Opening::draw(const Renderer & renderer)
{
	renderer.getDraw2D().textrue(TEXTURE_ID::ROGO,&GSvector2(170,90),&m_lerp.current());
	m_change.draw(renderer);
}

void Opening::finish()
{
}

const SceneMode Opening::next() const
{
	return m_change.next();
}

const bool Opening::isEnd() const
{
	return m_change.isEnd();
}

const bool Opening::isExit() const
{
	return false;
}
