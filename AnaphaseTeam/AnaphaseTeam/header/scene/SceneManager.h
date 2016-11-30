#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include "IScene.h"
#include <unordered_map>
#include <memory>
typedef std::shared_ptr<IScene>Scene_Ptr;
typedef std::unordered_map<SceneMode, Scene_Ptr> Scenes;
class IRenderer;
class SceneManager
{
public:
	SceneManager();
	void add(SceneMode _name, Scene_Ptr _scene);
	void change(SceneMode _name);
	void update(float _deltaTime);
	void draw(IRenderer * _renderer);
	void finish();
	const bool isExit()const;
private:
	void currentFinish();
private:
	Scenes m_Scenes;
	Scene_Ptr m_CurrentScene;
};
#endif