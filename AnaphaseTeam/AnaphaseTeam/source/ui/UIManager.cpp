#include "../../header/ui/UIManager.h"
#include "../../header/renderer/IRenderer.h"

UIManager& UIManager::getInstance()
{
	static UIManager self;
	return self;
}

void UIManager::release(EUI _key)
{
	m_UI.erase(_key);
}

void UIManager::clear()
{
	m_UI.clear();
}

void UIManager::add(EUI _key, UI_Ptr _ui)
{
	m_UI[_key] = _ui;

}
void UIManager::update(float deltatime)
{
	auto first = m_UI.begin();
	auto end = m_UI.end();
	for (auto itr = first; itr != end; itr++)
	{
		itr->second->update(deltatime);
	}
}
void UIManager::draw(IRenderer *_renderer)
{
	auto first = m_UI.begin();
	auto end = m_UI.end();
	for (auto itr = first; itr != end; itr++)
	{
		itr->second->draw(_renderer);
	}
}