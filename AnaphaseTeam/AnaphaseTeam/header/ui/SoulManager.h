#pragma once
#include "renderer\IRenderer.h"
#include <list>
#include <memory>

class Soul;
//using�̕����ǂ� using(typedef)�͐퓬�啶��
using SoulPtr = std::shared_ptr<Soul>;
//typedef std::shared_ptr<Soul> soul_ptr;

class SoulManager
{
public:
	SoulManager();
	~SoulManager();
	void initialize();
	void update(float _deltaTime);
	void draw(IRenderer* _renderer);
	void remove();
	//����pointer�ł͂Ȃ��X�}�[�gpointer�ł̂����
	void add(SoulPtr& _soul);//  *_particle);
	bool isEmpty()const;
private:
	using Container = std::list<SoulPtr>;
	Container m_particles;

};