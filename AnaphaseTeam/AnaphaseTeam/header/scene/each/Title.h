#ifndef _TITLE_H_
#define _TITLE_H_
#include "../IScene.h"

#include "../../camera/Camera.h"
#include "../../light/DirectionalLight.h"
class Input;
class Title :public IScene
{
public:
	Title(const Input* _input);
	~Title();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
private:
	bool m_IsEnd;
	const Input* m_Input;

	Camera m_Camera;

	GSvector3 target;
	DirectionalLight light;
};
#endif