#pragma once
/**
* @file Load.h
* @brief ロードヘッダー
* @author Ayumu Saito
* @date 2016/12/15 Ver1.00 loadEffect関数追加
*/
#ifndef _LOAD_H_
#define _LOAD_H_
#include "../IScene.h"

class Load :public IScene
{
public:
	Load();
	~Load();
	void initialize();
	void update(float deltaTime);
	void draw(IRenderer * renderer);
	void finish();
	const SceneMode next()const;
	const bool isEnd()const;
	const bool isExit()const;
private:
	void loadTextrue();
	void loadSound();
	void loadModel();
	void loadMyAnimation();
	void loadEffect();
private:
	bool m_IsEnd;
};
#endif