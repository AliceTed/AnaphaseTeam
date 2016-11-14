#pragma once

class Gauge;

class SpecialAttack
{
public:
	SpecialAttack();
	~SpecialAttack();
	void initialize(Gauge* _gauge);
	void update(float deltaTime);
	const bool isEnd() const;

private:

};