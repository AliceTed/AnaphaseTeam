#include <GSgame.h>
#include "../Util/EffectGL.h"
#include "../Util/BasicShapes.h"
#include "../header/math/Calculate.h"
#include "../header/data/Release.h"

#include "../header/scene/SceneManager.h"
#include "../header/scene/each/Load.h"
#include "../header/scene/each/Title.h"
#include "../header/scene/each/GamePlay.h"
#include "../header/scene/each/Ending.h"

#include "../header/renderer/Renderer.h"
#include "../header/device/Input.h"


class MyGame : public gslib::Game
{
public:
	MyGame()
		:Game(),
		m_SceneManager(),
		m_Renderer()
	{
	}

private:
	virtual void start() override
	{
		/*
		シェアードポインタは変数に作ってから追加する
		無名作成はしない
		無名作成( add(id,std::make_shared<Scene>()) )
		*/
		std::shared_ptr<IScene>load = std::make_shared<Load>();
		std::shared_ptr<IScene>title = std::make_shared<Title>(&m_Input);
		std::shared_ptr<IScene>gameplay = std::make_shared<GamePlay>(&m_Input);
		std::shared_ptr<IScene>ending = std::make_shared<Ending>(&m_Input);
		m_SceneManager.add(SceneMode::LOAD, load);
		m_SceneManager.add(SceneMode::TITLE, title);
		m_SceneManager.add(SceneMode::GAMEPLAY, gameplay);
		m_SceneManager.add(SceneMode::ENDING, ending);
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
		m_SceneManager.draw(m_Renderer);
	}
	// 終了
	virtual void end() override
	{
		Data::Release release;
		release();
	}

private:
	SceneManager m_SceneManager;

	//以下デバイスクラスでまとめる予定
	//本当はインターフェイス作りたいが変更時面倒
	Renderer m_Renderer;
	Input m_Input;
};

int main()
{
	return MyGame().run();
}
