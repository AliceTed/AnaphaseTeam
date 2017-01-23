#include "../header/ui/ResultManager.h"
#include "renderer/IRenderer.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "renderer/define/NumberSpriteRenderDesc.h"
#include "data/id/TEXTURE_ID.h"

ResultManager::ResultManager()
	: m_num(0), m_score(50)
{
}

ResultManager::~ResultManager()
{
}

void ResultManager::initilize()
{
}

void ResultManager::update(float _deltaTime)
{
	if (m_score > m_num)
	{
		m_num++;
	}

	for (int i = 0; i < m_score / 5; i++)
	{

	}
}

void ResultManager::draw(IRenderer * _renderer)
{
	NumberSpriteRenderDesc desc;
	desc.decimal = 0;
	desc.digit = 1;
	desc.number = m_num;
	desc.matrix.translate(GSvector3(700, 400, 0));
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::NUMBER);
	_renderer->render(desc);
}



