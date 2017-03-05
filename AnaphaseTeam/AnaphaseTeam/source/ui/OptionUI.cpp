#include "../../header/ui/OptionUI.h"
#include "../../header/scene/SceneChange.h"
#include "../../header/scene/each/Option.h"
#include "../../header/device/GameDevice.h"

OptionUI::OptionUI()
	:m_fade(TEXTURE_ID::BLACK),
	m_select(),
	m_pad(),
	m_sound(),
	m_volume(),
	m_cahnge(false)
{
}

OptionUI::~OptionUI()
{
}

void OptionUI::initialize()
{
	createSelect();
	m_fade.initialize();
	GameDevice::getInstacnce().sound().playBGM(BGM_ID::TITLE);
}


void OptionUI::update(float _deltaTime)
{
	m_fade.update(_deltaTime);
	m_select.update(_deltaTime);
	m_pad.update(_deltaTime);
	m_sound.update(_deltaTime);
	m_volume.update(_deltaTime);
}

void OptionUI::draw(IRenderer * _renderer)
{
	m_fade.draw(_renderer);
	m_select.draw(_renderer);
	if (m_select.current() == OPTION::CONFIG)
	{
		m_pad.draw(_renderer);
	}
	if (m_select.current() == OPTION::SOUND)
	{
		m_sound.draw(_renderer);
		m_volume.draw(_renderer);
	}
}

void OptionUI::finish()
{
	m_select.initialize();
	m_pad.initialize();
	m_sound.initialize();
	m_volume.initialize();
}

void OptionUI::operation(Option& _opution)
{
	if (m_fade.isStart())
	{
		return;
	}
	cancel(_opution);
	if (GameDevice::getInstacnce().input()->right())
	{
		if (m_select.current() == OPTION::CONFIG)
		{
			m_pad.previous();
		}
		if (m_select.current() == OPTION::SOUND)
		{
			m_volume.next();
		}
	}
	if (GameDevice::getInstacnce().input()->left())
	{
		if (m_select.current() == OPTION::CONFIG)
		{
			m_pad.next();
		}
		if (m_select.current() == OPTION::SOUND)
		{
			m_volume.previous();
		}
	}
	if (GameDevice::getInstacnce().input()->up())
	{
		m_select.previous();
	}
	if (GameDevice::getInstacnce().input()->down())
	{
		m_select.next();
	}
	if (GameDevice::getInstacnce().input()->decision())
	{
		if ( m_select.current() == OPTION::TITLE)
		{
			_opution.optionDecision(m_select.current());
		}
		if (m_select.current() == OPTION::CONFIG)
		{
			_opution.padDecision(m_pad.current());
		}
		if (m_select.current() == OPTION::SOUND)
		{
			_opution.bgmDecision(m_volume.current());
		}		
	}

}

void OptionUI::outionOperation(Option & _opution)
{
	if (_opution.isChnage())
	{
		return;
	}
}

void OptionUI::padOperation(Option & _opution)
{
	if (!_opution.isChnage())
	{
		return;
	}
}

void OptionUI::cancel(Option & _opution)
{
	m_cahnge = _opution.isChnage();
}

void OptionUI::createSelect()
{
	m_select.initialize();
	ScaleImage imageOption(TEXTURE_ID::CONFIG_TEXT, GSvector2(50, 100), false, 50.0f, 1.0f);
	m_select.add(OPTION::CONFIG, imageOption);
	ScaleImage imageSE(TEXTURE_ID::SOUND_TEXT, GSvector2(50, 250), false, 50.0f, 1.0f);
	m_select.add(OPTION::SOUND, imageSE);
	ScaleImage imageTitale(TEXTURE_ID::PAUSE_TITLEBACK, GSvector2(50, 550), false, 50.0f, 1.0f);
	m_select.add(OPTION::TITLE, imageTitale);
	m_select.startChange();

	m_pad.initialize();
	ScaleImage padA(TEXTURE_ID::PAD_A, GSvector2(500, 100), false, 500.0f, 1.0f);
	m_pad.add(PAD::PAD_A, padA);
	ScaleImage padB(TEXTURE_ID::PAD_B, GSvector2(700, 400), false, 1000.0f, 1.0f);
	m_pad.add(PAD::PAD_B, padB);
	m_pad.startChange();

	m_sound.initialize();
	ScaleImage bgm(TEXTURE_ID::VOLUME_TEXT, GSvector2(600, 300), false, 600.0f, 1.0f);
	m_sound.add(SOUND::BGM, bgm);
	//ScaleImage se(TEXTURE_ID::EXIT, GSvector2(300, 500), false, 300.0f, 1.0f);
	//m_sound.add(SOUND::SE, se);
	m_sound.startChange();

	m_volume.initialize();
	ScaleImage low(TEXTURE_ID::VOLUME_SMALL, GSvector2(600, 400), false, 600.0f, 1.0f);
	m_volume.add(VOLUME::LOW, low);
	ScaleImage normal(TEXTURE_ID::VOLUME_MID, GSvector2(700, 400), false, 700.0f, 1.0f);
	m_volume.add(VOLUME::NORMAL, normal);
	ScaleImage high(TEXTURE_ID::VOLUME_LERGE, GSvector2(800, 400), false, 800.0f, 1.0f);
	m_volume.add(VOLUME::HIGH, high);
	m_volume.startChange();

}

