#include "../../header/ui/OptionUI.h"
#include "../../header/scene/SceneChange.h"
#include "../../header/scene/each/Option.h"
#include "../../header/device/GameDevice.h"

OptionUI::OptionUI()
	:m_fade(TEXTURE_ID::BLACK),
	m_select(),
	m_pad(),
	m_sound(),
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
}


void OptionUI::update(float _deltaTime)
{
	m_fade.update(_deltaTime);
	m_select.update(_deltaTime);
	m_pad.update(_deltaTime);
	m_sound.update(_deltaTime);
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
	}
	//if()
}

void OptionUI::finish()
{
	m_select.initialize();
	m_pad.initialize();
	m_sound.initialize();
}

void OptionUI::operation(Option& _opution)
{
	if (m_fade.isStart())
	{
		return;
	}
	cancel(_opution);
	//outionOperation(_opution);
	//padOperation(_opution);
	if (GameDevice::getInstacnce().input()->right())
	{
		m_pad.previous();
	}
	if (GameDevice::getInstacnce().input()->left())
	{
		m_pad.next();
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
		_opution.optionDecision(m_select.current());
		_opution.padDecision(m_pad.current());
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
	ScaleImage imageOption(TEXTURE_ID::PAUSE_GAMEBACK, GSvector2(50, 100), false, 50.0f, 1.0f);
	m_select.add(OPTION::CONFIG, imageOption);
	ScaleImage imageSE(TEXTURE_ID::PAUSE_GAMEBACK, GSvector2(50, 400), false, 50.0f, 1.0f);
	m_select.add(OPTION::SOUND, imageSE);
	ScaleImage imageTitale(TEXTURE_ID::PAUSE_TITLEBACK, GSvector2(50, 600), false, 50.0f, 1.0f);
	m_select.add(OPTION::TITLE, imageTitale);
	m_select.startChange();

	m_pad.initialize();
	ScaleImage padA(TEXTURE_ID::PAD_A, GSvector2(400, 100), false, 400.0f, 1.0f);
	m_pad.add(PAD::PAD_A, padA);
	ScaleImage padB(TEXTURE_ID::EXIT, GSvector2(800, 100), false, 800.0f, 1.0f);
	m_pad.add(PAD::PAD_B, padB);
	m_pad.startChange();

	m_sound.initialize();
	ScaleImage bgm(TEXTURE_ID::STAFFROLL, GSvector2(300, 200), false, 300.0f, 1.0f);
	m_sound.add(SOUND::BGM, bgm);
	ScaleImage se(TEXTURE_ID::EXIT, GSvector2(300, 500), false, 300.0f, 1.0f);
	m_sound.add(SOUND::SE, se);
	m_sound.startChange();

	m_volume.initialize();
	ScaleImage low(TEXTURE_ID::SPECIAL_RECOVERY, GSvector2(400, 200), false, 400.0f, 1.0f);
	m_volume.add(VOLUME::LOW, low);
	ScaleImage normal(TEXTURE_ID::SPECIAL_SUPERARMOR, GSvector2(450, 200), false, 450.0f, 1.0f);
	m_volume.add(VOLUME::NORMAL, normal);
	ScaleImage high(TEXTURE_ID::SPECIAL_ATTACK, GSvector2(500, 200), false, 500.0f, 1.0f);
	m_volume.add(VOLUME::HIGH, high);

}

