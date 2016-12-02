#include "../../header/ui/TitleUI.h"
#include "../../header/scene/SceneChange.h"
#include "../../header/scene/each/Title.h"
#include "../../header/scene/each/Menu.h"
#include "../../header/device/GameDevice.h"
TitleUI::TitleUI()
	:m_select(),
	m_fade(TEXTURE_ID::TITLE_ROGO),
	m_scroll(0.0f)
{
}

TitleUI::~TitleUI()
{
}

void TitleUI::initialize()
{
	m_scroll = -70.0f;
	createSelect();
	m_fade.initialize();
	m_fade.start(GScolor(1.0f, 1.0f, 1.0f, 1.0f), GScolor(1.0f, 1.0f, 1.0f, 1.0f), 0);
}

void TitleUI::update(float deltaTime)
{
	m_select.update(deltaTime);
	m_fade.update(deltaTime);
}

void TitleUI::draw(IRenderer* _renderer)
{
	
	m_fade.draw(_renderer);
	m_select.draw(_renderer);
}

void TitleUI::finish()
{
	m_select.initialize();
}
void TitleUI::operation(Menu& _menu)
{
	if (m_fade.isStart())
	{
		return;
	}
	if (GameDevice::getInstacnce().input()->up())
	{
		m_select.previous();
	}
	if (GameDevice::getInstacnce().input()->down())
	{
		m_select.next();
	}
	if (GameDevice::getInstacnce().input()->jump())
	{
		_menu.decision(m_select.currentSelect());
		m_select.startMove();
		m_fade.start(GScolor(1.0f, 1.0f, 1.0f, 1.0f), GScolor(1.0f, 1.0f, 1.0f, 0.0f), 1.3f);
	}
}
void TitleUI::scroll()
{
	m_scroll++;
	if (m_scroll >= 180)
	{
		m_scroll = 180;
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
	GSvector2 base(m_scroll, 180);
	GSvector2 marge(0, 80);
	for (unsigned int i = 0; i < size; i++)
	{
		GSvector2 position(base + marge*i);
		ScaleImage image(id[i], position, false);
		m_select.add(select[i], image);
		
	}
	m_select.startChange();
}
