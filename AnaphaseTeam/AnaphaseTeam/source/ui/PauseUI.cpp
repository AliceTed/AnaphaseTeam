#include "../../header/ui/PauseUI.h"
#include<algorithm>
static const GSvector2 def = GSvector2(1, 1);
static const GSvector2 max = GSvector2(1.2f, 1.2f);
static const GSvector2 defPosi[2] = { GSvector2(500,300),GSvector2(500,500) };
static const GSvector2 maxPosi[2] = { GSvector2(470,270),GSvector2(470,470) };
PauseUI::PauseUI()
{
}
PauseUI::~PauseUI()
{
}
void PauseUI::initialize()
{
	m_images.clear();
	m_images.emplace_back(std::make_shared<ScaleImage>(TEXTURE_ID::PAUSE_GAMEBACK, defPosi[0], true, 0, 1.0));
	m_images.emplace_back(std::make_shared<ScaleImage>(TEXTURE_ID::PAUSE_TITLEBACK, defPosi[1], true, 0, 1.0f));
	start(0);
}
void PauseUI::update(float deltaTime)
{
	std::for_each(m_images.begin(), m_images.end(), [deltaTime](Image_Ptr value) {value->update(deltaTime); });
}
void PauseUI::start(int _select)
{
	if (_select == 0)
	{
		scale_Game(def, max, maxPosi, defPosi);
	}
	if (_select == 1)
	{
		scale_Game(max, def, defPosi, maxPosi);
	}
}

void PauseUI::scale_Game(const GSvector2 _def, const GSvector2 _max, const GSvector2 _posi0[], const GSvector2 _posi1[])
{
	m_images[0]->start(_def, _max, 0);
	m_images[1]->start(_max, _def, 0);
	m_images[0]->moveStart(_posi0[0], 1);
	m_images[1]->moveStart(_posi1[1], 1);
}

void PauseUI::draw(IRenderer* _renderer)
{
	std::for_each(m_images.begin(), m_images.end(), [&_renderer](Image_Ptr value) {value->draw(_renderer); });
}