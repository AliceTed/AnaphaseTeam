#include "../../../header/scene/each/Option.h"
#include "../../../header/renderer/define/SpriteRenderDesc.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/IRenderer.h"
#include <algorithm>
Option::Option()
	:
	m_change(),
	m_image()
{
	m_slideStart[0] = m_slideStart[1] = false;
}

Option::~Option()
{
}

void Option::initialize()
{
	m_change.initialize();
	m_change.begin();
	m_image.clear();
	SlideImage image(TEXTURE_ID::OPTION, GSvector2(-300, 100), GSvector2(100, 100));
	m_image.emplace_back(image);
	SlideImage image2(TEXTURE_ID::EXIT, GSvector2(-300, 300), GSvector2(100, 300));
	m_image.emplace_back(image2);
	m_timer = 0;
	m_slideStart[0] = m_slideStart[1] = false;
}

void Option::update(float deltaTime)
{
	if (m_change.update(deltaTime))return;
	m_timer += deltaTime * 1;
	if (m_timer > 1)
	{
		slideStart(0);
	}
	if (m_timer > 20)
	{
		slideStart(1);
	}

	/*if (GameDevice::getInstacnce().input()->right())
	{
		std::for_each(m_image.begin(), m_image.end(), [](SlideImage& _image) {_image.slide();});
	}
	if (GameDevice::getInstacnce().input()->left())
	{
		std::for_each(m_image.begin(), m_image.end(), [](SlideImage& _image) {_image.slide(1,MODE::REVERSE);});
	}*/
	std::for_each(m_image.begin(), m_image.end(), [deltaTime](SlideImage& _image) {_image.update(deltaTime);});
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void Option::slideStart(unsigned int _index)
{
	if (!m_slideStart[_index])
	{
		m_image[_index].slide(0.6f);
		m_slideStart[_index] = true;
	}
}


void Option::draw(IRenderer * renderer)
{
	SpriteRenderDesc backdesc;
	backdesc.textureID =static_cast<GSuint>(TEXTURE_ID::OPTION_BACKGROUND);
	renderer->render(backdesc);

	std::for_each(m_image.begin(), m_image.end(), [&renderer](SlideImage& _image) {_image.draw(renderer);});
}

void Option::finish()
{
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
