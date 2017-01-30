#include "scene/each/Result.h"
#include "device/GameDevice.h"
#include "renderer\IRenderer.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "renderer/define/NumberSpriteRenderDesc.h"
#include "data/id/TEXTURE_ID.h"


Result::Result()
	:m_change(), m_number(TEXTURE_ID::NUMBER),m_manager()
	

{}

Result::~Result()
{
}

void Result::initialize()
{
	m_change.initialize();
	m_change.begin();
	m_manager.initilize();

}

void Result::update(float _deltaTime)
{
	if (m_change.update(_deltaTime)) return;
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::ENDING);
	}

	m_manager.update(_deltaTime);

}

void Result::draw(IRenderer * _renderer)
{
	m_manager.draw(_renderer);
}

void Result::finish()
{
}

const SceneMode Result::next() const
{
	return m_change.next();
}

const bool Result::isEnd() const
{
	return m_change.isEnd();
}

const bool Result::isExit() const
{
	return false;
}
