#pragma once

#include <vector>
#include <memory>

class IRenderer;
class Particle;

class ParticleData
{
private:
	using ParticlePtr = std::shared_ptr<Particle>;
	using ParticleContaner = std::vector<ParticlePtr>;
public:
	ParticleData();
	~ParticleData();
	void initialize();
	void update(float _deltaTime);
	void draw(IRenderer* _renderer);
	void add(Particle _object);
	void remove(ParticleContaner _itr);
private:
	ParticleContaner m_particles;
};