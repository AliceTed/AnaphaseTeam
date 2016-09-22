#include"../../header/scene/SceneManager.h"
SceneManager::SceneManager()
	:m_Scenes(), m_CurrentScene(nullptr)
{
}
void SceneManager::add(SceneMode _name, Scene_Ptr _scene)
{
	m_Scenes.insert(std::make_pair(_name, _scene));
}
void SceneManager::change(SceneMode _name)
{
	m_CurrentScene = m_Scenes.at(_name);
	m_CurrentScene->initialize();
}
void SceneManager::update(float _deltaTime)
{
	m_CurrentScene->update(_deltaTime);

	currentFinish();
}
void SceneManager::draw(const Renderer& _renderer)
{
	m_CurrentScene->draw(_renderer);
}
void SceneManager::finish()
{

}

const bool SceneManager::isExit() const
{
	return m_CurrentScene->isExit();
}

void SceneManager::currentFinish()
{
	if (!m_CurrentScene->isEnd())
	{
		return;
	}
	m_CurrentScene->finish();
	change(m_CurrentScene->next());
}
