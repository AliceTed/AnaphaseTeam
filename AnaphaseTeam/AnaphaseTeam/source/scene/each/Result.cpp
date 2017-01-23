#include "scene/each/Result.h"
#include "device/GameDevice.h"
#include "renderer\IRenderer.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "renderer/define/NumberSpriteRenderDesc.h"
#include "data/id/TEXTURE_ID.h"

Result::Result()
	:m_change(), m_number(TEXTURE_ID::NUMBER)
	, m_num(0), m_score(50)

{}

Result::~Result()
{
}

void Result::initialize()
{
	m_change.initialize();
	m_change.begin();

	m_number.initilize();

}

void Result::update(float _deltaTime)
{
	if (m_change.update(_deltaTime)) return;
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::TITLE);
	}

	if (m_score > m_num)
	{
		m_num++;
	}
}

void Result::draw(IRenderer * _renderer)
{
	NumberSpriteRenderDesc desc;
	desc.decimal = 0;
	desc.digit = 1;
	desc.number = m_num;
	desc.matrix.translate(GSvector3(500, 500, 0));
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::NUMBER);
	_renderer->render(desc);
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
