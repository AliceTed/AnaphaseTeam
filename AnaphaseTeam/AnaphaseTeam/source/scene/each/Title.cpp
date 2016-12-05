#include "../../../header/scene/each/Title.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/renderer/define/SpriteRenderDesc.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/data/id/BGM_ID.h"
Title::Title()
	:m_IsExit(false),
	m_change(),
	m_alpha(1.0f),
	m_decrease(0.0f),
	m_IsChange(true)
{
}

Title::~Title()
{
}

void Title::initialize()
{
	m_IsExit = false;
	m_change.initialize();
	m_change.begin();
}
void Title::update(float _deltaTime)
{
	if (m_change.update(_deltaTime))return;
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::MENU);
	}
	alpha(2.0f);
}

void Title::draw(IRenderer * _renderer)
{
	SpriteRenderDesc tatle;
	tatle.textureID = static_cast<GSuint>(TEXTURE_ID::TITLE_ROGO);
	_renderer->render(tatle);

	SpriteRenderDesc presskey;
	presskey.textureID = static_cast<GSuint>(TEXTURE_ID::PRESSKEY);
	presskey.matrix.translate(420, 600, 0);
	presskey.color.a = m_alpha;
	_renderer->render(presskey);

	m_change.draw(_renderer);


}

void Title::finish()
{
	GameDevice::getInstacnce().sound().stopBGM(BGM_ID::TITLE);
	GameDevice::getInstacnce().sound().stopSE(SE_ID::ENTER);
}

const SceneMode Title::next() const
{
	return m_change.next();
}

const bool Title::isEnd() const
{
	return m_change.isEnd();
}

const bool Title::isExit() const
{
	return false;
}

void Title::alpha(float _time)
{
	m_decrease = 1 / (_time * 60);
	if (m_IsChange)
	{
		m_alpha -= m_decrease;
		if (m_alpha < 0)
		{
			m_IsChange = false;
		}
	}
	if (!m_IsChange)
	{
		m_alpha += m_decrease;
		if (m_alpha > 1.0f)
		{
			m_IsChange = true;
		}
	}
}
