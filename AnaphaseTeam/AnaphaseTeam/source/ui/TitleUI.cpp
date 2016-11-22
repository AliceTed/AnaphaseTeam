#include "../../header/ui/TitleUI.h"
#include "../../header/renderer/Renderer.h"
#include "../../header/scene/SceneChange.h"
#include "../../header/device/Input.h"
#include "../../header/scene/each/Title.h"
TitleUI::TitleUI()
	:m_select(),
	m_cursor()
{
}

TitleUI::~TitleUI()
{
}

void TitleUI::initialize()
{
	createSelect();
}

void TitleUI::update(float deltaTime, Title& _title)
{
	m_select.update(deltaTime);
	operation(_title);
}

void TitleUI::draw(const Renderer & _renderer)
{
	_renderer.getDraw2D().textrue(TEXTURE_ID::TITLE_ROGO, &GSvector2(0, 0));
	m_select.draw(_renderer);
	m_cursor.draw(_renderer, m_select.currentSelect());
}

void TitleUI::finish()
{
	m_select.initialize();
	m_cursor.initialize();
}
void TitleUI::operation(Title& _title)
{
	_title.select(m_select);
	_title.decision(m_select.currentSelect());
}
void TitleUI::createSelect()
{
	m_select.initialize();
	m_cursor.initialize();
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
	GSvector2 base(240, 500);
	GSvector2 marge(0, 60);
	for (unsigned int i = 0; i < size; i++)
	{
		GSvector2 position(base + marge*i);
		ScaleImage image(id[i], position,false);
		m_select.add(select[i],image);
		m_cursor.add(select[i], position+GSvector2(-70,0));
	}
	m_select.startChange();
}
