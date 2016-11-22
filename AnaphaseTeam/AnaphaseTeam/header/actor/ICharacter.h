#pragma once

__interface ICharacter
{
	virtual void stand(float deltaTime) = 0;
	virtual void move(float deltaTime) = 0;
	virtual void attack(float deltaTime) = 0;
	virtual void damage(float deltaTime) = 0;
	virtual void jump(float deltaTime) = 0;
	virtual void avoid(float deltaTime) = 0;
	virtual void createColision() = 0;
};