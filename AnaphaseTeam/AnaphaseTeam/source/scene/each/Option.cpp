#include "../../../header/scene/each/Option.h"
#include "../../../header/device/GameDevice.h"
#include "../../../header/renderer/IRenderer.h"
#include <algorithm>
Option::Option(GameDevice* _device)
	:m_device(_device),
	m_change(),
	m_image()
{
}

Option::~Option()
{
}

void Option::initialize()
{
	m_change.initialize();
	m_change.begin();
	m_image.clear();
	SlideImage image(TEXTURE_ID::PAD_A, GSvector2(-300, 100), GSvector2(100, 100));
	m_image.emplace_back(image);
	SlideImage image2(TEXTURE_ID::PAD_B, GSvector2(100, 100), GSvector2(500, 100));
	m_image.emplace_back(image2);
}

void Option::update(float deltaTime)
{
	if (m_change.update(deltaTime))return;
	
	if (m_device->input()->right())
	{
		std::for_each(m_image.begin(), m_image.end(), [](SlideImage& _image) {_image.slide();});
	}
	if (m_device->input()->left())
	{
		std::for_each(m_image.begin(), m_image.end(), [](SlideImage& _image) {_image.slide(1,MODE::REVERSE);});
	}
	std::for_each(m_image.begin(), m_image.end(), [deltaTime](SlideImage& _image) {_image.update(deltaTime);});
	if (m_device->input()->jump())
	{
		m_change.end(SceneMode::TITLE);
	}
}

void Option::draw(IRenderer * renderer)
{
	//renderer.getDraw2D().textrue(TEXTURE_ID::OPTION_BACKGROUND, &GSvector2(0, 0));
	//std::for_each(m_image.begin(), m_image.end(), [&renderer](SlideImage& _image) {_image.draw(renderer);});
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
