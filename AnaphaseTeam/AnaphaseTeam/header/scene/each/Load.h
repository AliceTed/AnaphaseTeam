#ifndef _LOAD_H_
#define _LOAD_H_
#include "../IScene.h"

class Sound;

class Load :public IScene
{
public:
	Load(Sound* _sound);
	~Load();
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	void loadTextrue();
	void loadSound();
	void loadModel();
private:
	bool m_IsEnd;
	Sound* m_sound;
};
#endif