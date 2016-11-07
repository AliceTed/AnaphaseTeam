#pragma once
#include "../../../header/actor/ICharacter.h"
#include "../../../header/actor/Actor.h"

class Enemy : public Actor,public ICharacter
{
public:
	Enemy();
	~Enemy();
public:
	//Actoråpè≥
	void initialize();
	void update(float deltatime);
	void draw(const Renderer& _renderer, const Camera& _camera);
	void finish();
	
public:
	//ICharacter
	void stand(float deltaTime);
	void move(float deltaTime);
	void attack(float deltaTime);
	void damage(float deltaTime);
	void jump(float deltaTime);
	void avoid(float deltaTime);
	void createColision();

};