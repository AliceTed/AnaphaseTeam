#include <GSgame.h>
#include <memory>
#include "../header/scene/SceneManager.h"
#include "../header/scene/each/Load.h"
#include "../header/scene/each/Opening.h"
#include "../header/scene/each/Option.h"
#include "../header/scene/each/Title.h"
#include "../header/scene/each/Menu.h"
#include "../header/scene/each/GamePlay.h"
#include "../header/scene/each/Ending.h"
#include "../header/scene/each/GameClear.h"
#include "../header/scene/each/Result.h"
#include "../header/scene/each/GameOver.h"

#include "../header/renderer/IRenderer.h"
#include "../header/renderer/Renderer.h"
#include "../header/device/GameDevice.h"

#include"../header/data/release/DataAllRelease.h"
#include "../header/renderer/define/ViewportDesc.h"

class MyGame : public gslib::Game
{
public:
	MyGame()
		:Game(1280, 720, false, 60.0f),
		m_SceneManager(),
		m_renderer(std::make_unique<Renderer>())
	{
		/* */
	}

private:
	virtual void start() override
	{
		m_renderer->initialize();
		//m_renderer->perspective(45,,);
		ViewportDesc desc;
		desc.height =720;
		desc.width=1280;
		m_renderer->viewport(desc);
		LightDesc light;
		light.ambient = Color4(0.5f, 0.5f, 0.5f, 1.0f);
		light.diffuse = Color4(1.0f, 1.0f, 1.0f, 1.0f);
		light.specular = Color4(1.0f, 1.0f, 1.0f, 1.0f);
		light.position = Vector3(100.0f, 100.f, 100.0f);
		m_renderer->light(light);

		/*
		シェアードポインタは変数に作ってから追加する
		無名作成はしない
		無名作成( add(id,std::make_shared<Scene>()) )
		*/
		std::shared_ptr<IScene>load = std::make_shared<Load>();
		std::shared_ptr<IScene>opening= std::make_shared<Opening>();
		std::shared_ptr<IScene>title = std::make_shared<Title>();
		std::shared_ptr<IScene>menu = std::make_shared<Menu>();
		std::shared_ptr<IScene>option = std::make_shared<Option>();
		std::shared_ptr<IScene>gameplay = std::make_shared<GamePlay>();
		std::shared_ptr<IScene>ending = std::make_shared<Ending>();
		std::shared_ptr<IScene>gameclaer = std::make_shared<GameClear>();
		std::shared_ptr<IScene>result = std::make_shared<Result>();
		std::shared_ptr<IScene>gameover = std::make_shared<GameOver>();

		m_SceneManager.add(SceneMode::LOAD, load);
		m_SceneManager.add(SceneMode::OPENING, opening);
		m_SceneManager.add(SceneMode::TITLE, title);
		m_SceneManager.add(SceneMode::MENU, menu);
		m_SceneManager.add(SceneMode::OPTION, option);
		m_SceneManager.add(SceneMode::GAMEPLAY, gameplay);
		m_SceneManager.add(SceneMode::ENDING, ending);
		m_SceneManager.add(SceneMode::GAMECLEAR, gameclaer);
		m_SceneManager.add(SceneMode::RESULT, result);
		m_SceneManager.add(SceneMode::GAMEOVER, gameover);

		m_SceneManager.change(SceneMode::LOAD);
	}
	// 更新
	virtual void update(float deltaTime) override
	{
		m_SceneManager.update(deltaTime);
	}
	// 描画
	virtual void draw() override
	{
		m_SceneManager.draw(m_renderer.get());
	}
	// 終了
	virtual void end() override
	{
		DataAllRelease release;
		release();
	}
private:
	bool isRunning() { return !GameDevice::getInstacnce().input()->exit() && !m_SceneManager.isExit(); }
private:
	SceneManager m_SceneManager;
	std::unique_ptr<IRenderer> m_renderer;
};

int main()
{
	return MyGame().run();
}
