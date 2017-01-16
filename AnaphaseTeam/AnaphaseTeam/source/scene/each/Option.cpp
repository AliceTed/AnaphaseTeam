#include "../../../header/scene/each/Option.h"
#include "../../../header/renderer/IRenderer.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/data/id/BGM_ID.h"
#include "../../../header/renderer/define/SpriteRenderDesc.h"
#include "../../../header/data/id/TEXTURE_ID.h"

Option::Option()
	:m_change(),
	m_option(),
	m_optionChange(false),
	m_padChange(false)
{
}

Option::~Option()
{
}

void Option::initialize()
{
	m_change.initialize();
	m_change.begin();
	m_option.initialize();
	m_optionChange = false;
	m_padChange = true;
}

void Option::update(float deltaTime)
{
	m_option.update(deltaTime);
	if (m_change.update(deltaTime))return;
	m_option.operation(*this);
}

void Option::draw(IRenderer * _renderer)
{
	m_option.draw(_renderer);
	m_change.draw(_renderer);
}

void Option::finish()
{
	m_option.finish();
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

void Option::optionDecision(OPTION _option)
{
	switch (_option)
	{
	case OPTION::CONFIG:
		break;
	case OPTION::SOUND:
		break;
	case OPTION::TITLE:
		m_change.end(SceneMode::TITLE);
		break;
	}
}

void Option::padDecision(PAD _pad)
{
	switch (_pad)
	{
	case PAD::PAD_A:
		GameDevice::getInstacnce().inputChange(static_cast<IPUTTERN>(_pad));
		break;
	case PAD::PAD_B:
		GameDevice::getInstacnce().inputChange(static_cast<IPUTTERN>(_pad));
		break;
	}
}

void Option::bgmDecision(VOLUME _bgm)
{
	switch (_bgm)
	{
	case VOLUME::LOW:
		GameDevice::getInstacnce().sound().bgmVolume(BGM_ID::TITLE, 0);
		break;
	case VOLUME::NORMAL:
		GameDevice::getInstacnce().sound().bgmVolume(BGM_ID::TITLE, 0.7f);
		break;
	case VOLUME::HIGH:
		GameDevice::getInstacnce().sound().bgmVolume(BGM_ID::TITLE, 1.0f);
		break;
	}
}

bool Option::isChnage()
{
	return m_optionChange;
}
