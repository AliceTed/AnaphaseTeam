#pragma once
#include "renderer\IRenderer.h"
#include <list>
#include <memory>

class Soul;
//usingの方が良い using(typedef)は戦闘大文字
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
	//生のpointerではなくスマートpointerでのやり取り
	void add(SoulPtr& _soul);//  *_particle);
	bool isEmpty()const;
private:
	using Container = std::list<SoulPtr>;
	Container m_particles;

};