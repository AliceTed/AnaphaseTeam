#pragma once
/**
* @file Pause.h
* @brief �|�[�Y���
* @author hisaaki
* @date 2016/12/05
*/
class IRenderer;
class SceneChange;
class Pause
{
public:
	Pause(SceneChange& _change);
	~Pause();
	void initialize();
	void update(float deltatime);
	void draw(IRenderer* _renderer);
	void finish();
	void select();
	void decision();
	bool isPause();
private:
	void clamp();
private:
	int m_currentSelect;
	bool m_isPause;
	SceneChange& m_change;
};