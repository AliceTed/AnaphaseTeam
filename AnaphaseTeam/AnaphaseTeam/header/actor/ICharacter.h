#pragma once

__interface ICharacter
{
	virtual void stand() = 0;
	virtual void move() = 0;
	virtual void attack() = 0;
	virtual void damage() = 0;
	virtual void jump() = 0;
};