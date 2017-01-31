#include "scene/each/Ending.h"
#include "renderer/IRenderer.h"
#include "device/GameDevice.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "data/id/TEXTURE_ID.h"
#include "device/GameDevice.h"
#include "data/id/BGM_ID.h"

Ending::Ending()
	:m_IsEnd(false),
	m_change(),
	m_endUI(),
	m_nex(false),
	m_count(0)
{
}
Ending::~Ending()
{
}

void Ending::initialize()
{
	GameDevice::getInstacnce().sound().playBGM(BGM_ID::TITLE);
	m_IsEnd = false;
	m_change.initialize();
	m_change.begin();
	m_endUI.initilize();
	m_count = 0;
}

void Ending::update(float _deltaTime)
{
	if (m_change.update(_deltaTime))return;
	m_endUI.update(_deltaTime);
	
	endScene();

}

void Ending::draw(IRenderer * _renderer)
{

	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::BLACK);
	_renderer->render(desc);

	m_endUI.draw(_renderer);
	m_change.draw(_renderer);
}

void Ending::finish()
{
	GameDevice::getInstacnce().sound().stopBGM(BGM_ID::TITLE);
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

void Ending::endScene()
{
	if (m_endUI.isEnd())
	{
		if (GameDevice::getInstacnce().input()->jump())
		{
			m_change.end(SceneMode::TITLE);
		}
	}

	if (!m_endUI.isEnd())return;
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_count++;
	}

	if (m_count >= 2)
	{
		m_change.end(SceneMode::TITLE);
	}
}
