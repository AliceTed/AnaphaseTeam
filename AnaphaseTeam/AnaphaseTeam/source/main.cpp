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


#include "../header/device/Input.h"
#include "../header/camera/Camera.h"

#include "../header/renderer/Draw2D.h"

#include "../header/light/DirectionalLight.h"

class MyGame : public gslib::Game
{
public:
	MyGame()
		:Game(),
		m_SceneManager(),
		m_Camera(10, 8, GSvector3(0, 0, 0)),
		target(0, 0, 0),
		light(GL_LIGHT0,GSvector3(0,1,0))
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
		std::shared_ptr<IScene>title = std::make_shared<Title>();
		std::shared_ptr<IScene>gameplay = std::make_shared<GamePlay>();
		std::shared_ptr<IScene>ending = std::make_shared<Ending>();
		m_SceneManager.add(SceneMode::LOAD, load);
		m_SceneManager.add(SceneMode::TITLE, title);
		m_SceneManager.add(SceneMode::GAMEPLAY, gameplay);
		m_SceneManager.add(SceneMode::ENDING, ending);
		m_SceneManager.change(SceneMode::LOAD);
	}
	// 更新
	virtual void update(float deltaTime) override
	{
		Input input;

		target.x += input.horizontal()*0.1f;
		target.z += input.vertical()*0.1f;
		//m_SceneManager.update(deltaTime);
	}
	// 描画
	virtual void draw() override
	{
		Draw2D draw;
		m_Camera.lookAt(target, 0);
		light.lighting();
		bool isDraw = m_Camera.isFrustumCulling({ 0,0,0 }, 2);
		
		//α値を下げ始める距離
		float maxfar = 10.0f;
		if (isDraw)
		{
			float marge = m_Camera.nearMargeDistance({ 0,0,0 },2);
			GScolor color = { 1,0,0, marge / maxfar };
			draw.string(std::to_string(color.a), &GSvector2(100, 0), 20);
			
			glPushMatrix();
			glTranslatef(0, 0, 0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
			glutSolidSphere(2, 8, 8);
			glPopMatrix();
		}
		std::string str = isDraw ? "Draw" : "Non";
		draw.string(str,&GSvector2(0,0),20);

		
		//m_SceneManager.draw();
	}
	// 終了
	virtual void end() override
	{
		/*	Data::Release release;
			release();*/
	}

private:
	SceneManager m_SceneManager;
	Camera m_Camera;
	GSvector3 target;
	DirectionalLight light;
};

int main()
{
	return MyGame().run();
}
