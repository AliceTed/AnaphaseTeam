#include "../../header/ui/TitleUI.h"
#include "../../header/renderer/Renderer.h"
#include "../../header/scene/SceneChange.h"
#include "../../header/device/Input.h"
#include "../../header/scene/each/Title.h"
#include "../../header/device/GameDevice.h"
#include "../../header/data/TEXTURE_ID.h"
TitleUI::TitleUI(GameDevice* _device)
	:m_select(),
	m_device(_device),
	m_fade(TEXTURE_ID::TITLE_ROGO)
{
}

TitleUI::~TitleUI()
{
}

void TitleUI::initialize()
{
	createSelect();
	m_fade.initialize();
	m_fade.start(GScolor(1.0f, 1.0f, 1.0f, 1.0f), GScolor(1.0f, 1.0f, 1.0f, 1.0f), 0);
}

void TitleUI::update(float deltaTime, Title& _title)
{
	m_select.update(deltaTime);
	operation(_title);
	m_fade.update(deltaTime);
}

void TitleUI::draw(const Renderer & _renderer)
{
	m_fade.draw(_renderer);
	m_select.draw(_renderer);
}

void TitleUI::finish()
{
	m_select.initialize();
}
void TitleUI::operation(Title& _title)
{
	if (m_fade.isStart())
	{
		return;
	}
	if (m_device->input()->up())
	{
		m_select.previous();
	}
	if (m_device->input()->down())
	{
		m_select.next();
	}
	if (m_device->input()->jump())
	{
		_title.decision(m_select.currentSelect());
		m_select.startMove();
		m_fade.start(GScolor(1.0f, 1.0f, 1.0f, 1.0f), GScolor(1.0f, 1.0f, 1.0f, 0.0f), 1.0f);
	}
}
void TitleUI::createSelect()
{
	m_select.initialize();
	const unsigned int size = 3;
	Select select[size] =
	{
		Select::GAMESTART,
		Select::OPTION,
		Select::EXIT
	};
	TEXTURE_ID id[size] =
	{
		TEXTURE_ID::GAMESTART,
		TEXTURE_ID::OPTION,
		TEXTURE_ID::EXIT
	};
	GSvector2 base(550, 500);
	GSvector2 marge(0, 60);
	for (unsigned int i = 0; i < size; i++)
	{
		GSvector2 position(base + marge*i);
		ScaleImage image(id[i], position, false);
		m_select.add(select[i], image);
	}
	m_select.startChange();
}
